#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, AnimatedTexture* pTexture) {
    this->bEnabled = true;
    this->strName = strName;

    this->pSprite = new sf::Sprite();
    this->pSprite->setOrigin(0.0f, 0.0f);
    this->pSprite->setPosition(0.0f, 0.0f);

    this->pTexture = pTexture;
    this->setFrame(0);

    this->pParent = NULL;
    this->vecChildren = {};
    this->vecComponent = {};
}

void GameObject::processInput(sf::Event eEvent) {
    std::vector<Component*> vecInputComponent = this->getComponentsRecursively(ComponentType::INPUT);
    GeneralInput* pGeneralInput;

    for(Component* pComponent : vecInputComponent) {
        pGeneralInput = (GeneralInput*)pComponent;
        pGeneralInput->assignEvent(eEvent);
        pGeneralInput->perform();
    }
}

void GameObject::update(sf::Time tDeltaTime) {
    std::vector<Component*> vecScriptComponents = this->getComponentsRecursively(ComponentType::SCRIPT);
    
    for(Component* pComponent : vecScriptComponents) {
        pComponent->setDeltaTime(tDeltaTime);
        pComponent->perform();
    }
}

void GameObject::draw(sf::RenderWindow* pWindow, sf::RenderStates CRenderStates) {
    sf::RenderStates CTransformedRenderStates(CRenderStates);
    CTransformedRenderStates.transform = this->pSprite->getTransform() * CTransformedRenderStates.transform;

    std::vector<Component*> vecRendererComponent = this->getComponents(ComponentType::RENDERER);
    Renderer* pRenderer;

    for(Component* pComponent : vecRendererComponent) {
        pRenderer = (Renderer*)pComponent;
        if(pRenderer->getDrawOrder() == DrawOrder::NORMAL) {
            pRenderer->assignTargetWindow(pWindow);
            pRenderer->setRenderStates(CRenderStates);
            pRenderer->perform();
        }
    }

    vecRendererComponent = this->getComponentsRecursively(ComponentType::RENDERER, false);

    for(Component* pComponent : vecRendererComponent) {
        pRenderer = (Renderer*)pComponent;
        if(pRenderer->getDrawOrder() == DrawOrder::NORMAL) {
            pRenderer->assignTargetWindow(pWindow);
            pRenderer->setRenderStates(CTransformedRenderStates);
            pRenderer->perform();
        }
    }
}

void GameObject::drawLater(sf::RenderWindow* pWindow, sf::RenderStates CRenderStates) {
    sf::RenderStates CTransformedRenderStates(CRenderStates);
    CTransformedRenderStates.transform = this->pSprite->getTransform() * CTransformedRenderStates.transform;

    std::vector<Component*> vecRendererComponent = this->getComponents(ComponentType::RENDERER);
    Renderer* pRenderer;

    for(Component* pComponent : vecRendererComponent) {
        pRenderer = (Renderer*)pComponent;
        if(pRenderer->getDrawOrder() == DrawOrder::OVERLAY) {
            pRenderer->assignTargetWindow(pWindow);
            pRenderer->setRenderStates(CRenderStates);
            pRenderer->perform();
        }
    }

    vecRendererComponent = this->getComponentsRecursively(ComponentType::RENDERER, false);

    for(Component* pComponent : vecRendererComponent) {
        pRenderer = (Renderer*)pComponent;
        if(pRenderer->getDrawOrder() == DrawOrder::OVERLAY) {
            pRenderer->assignTargetWindow(pWindow);
            pRenderer->setRenderStates(CTransformedRenderStates);
            pRenderer->perform();
        }
    }
}

void GameObject::attachChild(GameObject* pChild) {
    this->vecChildren.push_back(pChild);
    pChild->setParent(this);
    pChild->initialize();
}

void GameObject::detachChild(GameObject* pChild) {
    int nIndex = -1;
    for(int i = 0; i < this->vecChildren.size() && nIndex == -1; i++) {
        if(this->vecChildren[i] == pChild) {
            nIndex = i;
        }
    }

    if(nIndex != -1)
        this->vecChildren.erase(this->vecChildren.begin() + nIndex);
}

void GameObject::attachComponent(Component* pComponent) {
    this->vecComponent.push_back(pComponent);
    pComponent->attachOwner(this);
}

void GameObject::detachComponent(Component* pComponent) {
    int nIndex = -1;
    for(int i = 0; i < this->vecComponent.size() && nIndex == -1; i++) {
        if(this->vecComponent[i] == pComponent) {
            nIndex = i;
        }
    }

    if(nIndex != -1) {
        this->vecComponent[nIndex]->detachOwner();
        this->vecComponent.erase(this->vecComponent.begin() + nIndex);
    }
}

Component* GameObject::findComponentByName(std::string strName) {
    for(Component* pComponent : this->vecComponent) {
        if(pComponent->getName() == strName)
        return pComponent;
    }
    
    std::cout << "[ERROR] : Component [" << strName << "] NOT found." << std::endl;
    return NULL;
}

std::vector<Component*> GameObject::getComponents(ComponentType EType) {
    std::vector<Component*> vecFound = {};

    for(Component* pComponent : this->vecComponent) {
        if(pComponent->getType() == EType)
            vecFound.push_back(pComponent);
    }

    return vecFound;
}

std::vector<Component*> GameObject::getComponentsRecursively(ComponentType EType, bool bInclusive) {
    std::vector<Component*> vecFound = {};

    if(bInclusive) 
        vecFound = this->getComponents(EType);

    for(GameObject* pChild : this->vecChildren) {
        for(Component* pComponent : pChild->getComponentsRecursively(EType)) {
            if(pComponent->getType() == EType)
                vecFound.push_back(pComponent);
        }
    }

    return vecFound;
}

void GameObject::centerSpriteOrigin() {
    if(this->pTexture != NULL) {
        int nWidth = this->pSprite->getTexture()->getSize().x;
        int nHeight = this->pSprite->getTexture()->getSize().y;

        float fHalfWidth = nWidth / 2.0f;
        float fHalfHeight = nHeight / 2.0f;

        this->pSprite->setOrigin(fHalfWidth, fHalfHeight);
    }
}

void GameObject::move(float fX, float fY) {
    this->setPosition(this->getGlobalBounds().left + fX, this->getGlobalBounds().top + fY);
}

sf::FloatRect GameObject::getGlobalBounds() {
    return this->pSprite->getGlobalBounds();
}

sf::FloatRect GameObject::getLocalBounds() {
    return this->pSprite->getLocalBounds();
}

sf::Vector2f GameObject::getPosition() {
    return this->pSprite->getPosition();
}

void GameObject::setPosition(float fX, float fY) {
    this->pSprite->setPosition(fX, fY);
}

bool GameObject::isEnabled() {
    return this->bEnabled;
}

void GameObject::setEnabled(bool bEnabled) {
    this->bEnabled = bEnabled;
}

std::string GameObject::getName() {
    return this->strName;
}

sf::Sprite* GameObject::getSprite() {
    return this->pSprite;
}

AnimatedTexture*GameObject::getTexture() {
    return this->pTexture;
}

GameObject* GameObject::getParent() {
    return this->pParent;
}

void GameObject::setParent(GameObject* pParent) {
    this->pParent = pParent;
}

int GameObject::getFrameSize() {
    if(this->pTexture != NULL) {
        return this->pTexture->getFrameSize();
    }
    return -1;
}

void GameObject::setFrame(int nFrame) {
    if(this->pTexture != NULL) {
        this->pTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pTexture->getFrame(), true);
    }
}

int GameObject::getCurrentFrame() {
    if(this->pTexture != NULL) {
        return this->pTexture->getCurrentFrame();
    }
    return -1;
}

float GameObject::getHalfWidth() {
    return (this->getGlobalBounds().width / 2.0f);
}

float GameObject::getHalfHeight() {
    return (this->getGlobalBounds().height / 2.0f);
}

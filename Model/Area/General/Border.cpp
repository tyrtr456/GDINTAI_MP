#include "Border.hpp"

using namespace models;

Border::Border(std::string strName, sf::FloatRect CBounds) : GameObject(strName, NULL) {
    this->CBounds = CBounds;
    this->COffset = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);
    this->CColor = sf::Color(255, 255, 255, 255);
}

Border::Border(std::string strName, AnimatedTexture* pTexture, sf::Vector2f CPosition) : GameObject(strName, pTexture) {
    this->CBounds.left = CPosition.x;
    this->CBounds.top = CPosition.y;
    this->COffset = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);
    this->CColor = sf::Color(255, 255, 255, 255);
}

Border::~Border() {}

void Border::initialize() {
    if(this->pTexture != NULL) {
        this->setFrame(0);
        this->pSprite->setPosition(this->CBounds.left, this->CBounds.top);
        this->CBounds.width = this->pSprite->getGlobalBounds().width;
        this->CBounds.height = this->pSprite->getGlobalBounds().height;
        std::cout << this->strName << " Sprite " << this->CBounds.width << " x " << this->CBounds.height << std::endl;
        Renderer* pRenderer = new Renderer(this->strName + " Border Background");
        pRenderer->assignDrawable(this->pSprite);
        this->attachComponent(pRenderer);
    }
    else {
        this->pSprite->setPosition(this->CBounds.left, this->CBounds.top);
        this->pRectangle = new sf::RectangleShape(sf::Vector2f(this->CBounds.width, this->CBounds.height));
        this->pRectangle->setFillColor(this->CColor);
        this->pRectangle->setPosition(this->CBounds.left, this->CBounds.top);
        Renderer* pRenderer = new Renderer(this->strName + " Border Background");
        pRenderer->assignDrawable(pRectangle);
        this->attachComponent(pRenderer);
    }

    this->pCollider = new Collider(this->strName + " Collider");
    this->pCollider->setOffset(this->COffset);
    this->pCollider->setListener(this);
    
    this->attachComponent(this->pCollider);
    std::cout << this->strName << " Collider " << this->pCollider->getGlobalBounds().width << " x " << this->getGlobalBounds().height << std::endl;
    PhysicsManager::getInstance()->trackCollider(this->pCollider);
}

sf::FloatRect Border::getGlobalBounds() {
    if(this->pTexture != NULL) {
        return GameObject::getGlobalBounds();
    }
    else {
        return this->pRectangle->getGlobalBounds();
        // return this->CBounds;
    }
}

void Border::setPosition(float fX, float fY) {
    if(this->pTexture != NULL) {
        GameObject::setPosition(fX, fY);
    }
    else {
        this->pRectangle->setPosition(fX, fY);
    }
}

Collider* Border::getCollider() {
    return this->pCollider;
}

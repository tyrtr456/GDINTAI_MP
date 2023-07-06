#include "GameObjectManager.hpp"

using namespace controllers;

void GameObjectManager::processInput(sf::Event eEvent) {
    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->isEnabled())
            pGameObject->processInput(eEvent);
    }
}

void GameObjectManager::update(sf::Time tDeltaTime) {
    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->isEnabled())
            pGameObject->update(tDeltaTime);
    }
}

void GameObjectManager::draw(sf::RenderWindow* pWindow) {
    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->isEnabled())
            pGameObject->draw(pWindow, sf::RenderStates::Default);
    }

    for(GameObject* pGameObject : this->vecGameObject) {
        if(pGameObject->isEnabled())
            pGameObject->drawLater(pWindow, sf::RenderStates::Default);
    }
}

void GameObjectManager::addObject(GameObject* pGameObject) {
    this->mapGameObject[pGameObject->getName()] = pGameObject;
    this->vecGameObject.push_back(pGameObject);
    pGameObject->initialize();
}

void GameObjectManager::deleteObject(GameObject* pGameObject) {
    std::string strName = pGameObject->getName();
    int nIndex = -1;

    for(int i = 0; i < this->vecGameObject.size() && nIndex == -1; i++) {
        if(this->vecGameObject[i] == pGameObject)
            nIndex = i;
    }

    if(nIndex != -1) {
        this->vecGameObject.erase(this->vecGameObject.begin() + nIndex);
        this->mapGameObject.erase(this->vecGameObject[nIndex]->getName());
        delete pGameObject;
    }
}

void GameObjectManager::deleteObjectByName(std::string strName) {
    GameObject* pGameObject = this->findObjectByName(strName);
    if(pGameObject != NULL)
        this->deleteObject(pGameObject);
}

GameObject* GameObjectManager::findObjectByName(std::string strName) {
    if(this->mapGameObject[strName] != NULL)
        return this->mapGameObject[strName];

    else {
        std::cout << "[ERROR] : Object [" << strName << "] NOT found." << std::endl;
        return NULL;
    }
}

/* * * * * * * * * * * * * * * * * * * * *
 *       SINGLETON-RELATED CONTENT       *
 * * * * * * * * * * * * * * * * * * * * */
GameObjectManager* GameObjectManager::P_SHARED_INSTANCE = NULL;
GameObjectManager::GameObjectManager() {}
GameObjectManager::GameObjectManager(const GameObjectManager&) {}

GameObjectManager* GameObjectManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new GameObjectManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */

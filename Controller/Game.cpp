#include "Game.hpp"

using namespace controllers;

Game::Game() : rwWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Title", sf::Style::Titlebar | sf::Style::Close) {
    this->rwWindow.setFramerateLimit(FRAME_RATE_LIMIT);
    std::srand(std::time(NULL));

    //TextureManager::getInstance()->loadAll();

    this->createNullObjectComponents();

    //Area* pArea = new MarbleGallery();
    //GameObjectManager::getInstance()->addObject(pArea);
    //GameObjectManager::getInstance()->addObject(this->pPhysicsManagerHolder);
}

void Game::createNullObjectComponents() {
    //this->pPhysicsManagerHolder = new EmptyGameObject("Physics Manager Holder");
    //PhysicsManager::initialize("Physics Manager System", this->pPhysicsManagerHolder);
}

void Game::run() {
    sf::Clock CClock = sf::Clock();
    sf::Time tLastUpdate = sf::Time::Zero;
    sf::Time tTimePerFrame = sf::seconds(1.0f / FRAME_RATE_LIMIT);

    while(this->rwWindow.isOpen()) {
        this->processEvents();
        tLastUpdate += CClock.restart();

        while(tLastUpdate > tTimePerFrame) {
            tLastUpdate -= tTimePerFrame;
            this->update(tTimePerFrame);
        }

        this->render();
    }
}

void Game::processEvents() {
    sf::Event eEvent;

    while(this->rwWindow.pollEvent(eEvent)) {
        switch(eEvent.type) {
            case sf::Event::Closed:
                this->rwWindow.close();
                break;
  
            default:
                //GameObjectManager::getInstance()->processInput(eEvent);
                break;
        }
    }
}

void Game::update(sf::Time tDeltaTime) {
    //GameObjectManager::getInstance()->update(tDeltaTime);
}

void Game::render() {
    this->rwWindow.clear();
    //GameObjectManager::getInstance()->draw(&this->rwWindow);
    this->rwWindow.display();
}

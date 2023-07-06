#include "Game.hpp"

using namespace controllers;


Game::Game() : rwWindow(sf::VideoMode(TILE_HEIGHT * GRID_SIZE, TILE_HEIGHT * GRID_SIZE), "Title", sf::Style::Titlebar | sf::Style::Close) {
    this->rwWindow.setFramerateLimit(60);
    std::srand(std::time(NULL));

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
            if(this->grid[i][j] == 1){
                rectangle->setFillColor(sf::Color(123, 63, 0, 255));
            }
            else{
                rectangle->setFillColor(sf::Color(255,255,255,5));
            }
            rectangle->setPosition(TILE_WIDTH * j, TILE_HEIGHT * i);
            this->vecTiles.push_back(rectangle);

            if(i == this->TankY && j == this->TankX){
                this->TankShape = new sf::RectangleShape(sf::Vector2f(TANK_WIDTH, TANK_HEIGHT));
                this->TankShape->setFillColor(sf::Color(0,255,0,50));
                this->TankShape->setPosition(TILE_WIDTH * j + TANK_OFFSET/2, TILE_HEIGHT * i + TANK_OFFSET/2);
            }

            if(i == this->ETankY && j == this->ETankX){
                this->ETankShape = new sf::RectangleShape(sf::Vector2f(TANK_WIDTH, TANK_HEIGHT));
                this->ETankShape->setFillColor(sf::Color(210, 180, 140,255));
                this->ETankShape->setPosition(TILE_WIDTH * j + TANK_OFFSET/2, TILE_HEIGHT * i + TANK_OFFSET/2);
                
            }
        }
    }
    

}

void Game::run() {
    sf::Clock CClock = sf::Clock();
    sf::Time tLastUpdate = sf::Time::Zero;
    sf::Time tTimePerFrame = sf::seconds(1.0f / 60);

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

            // Placed to remove the warning.    
            default:
                break;
        }
    }
}

void Game::update(sf::Time tDeltaTime) {
    
}

void Game::render() {
    this->rwWindow.clear();
    
    for(sf::RectangleShape *tile : this->vecTiles){
        this->rwWindow.draw(*tile);
    }
    this->rwWindow.draw(*(this->TankShape));
    this->rwWindow.draw(*(this->ETankShape));

    this->rwWindow.display();
}

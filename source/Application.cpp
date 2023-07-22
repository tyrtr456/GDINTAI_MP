#include "../include/Application.h"
#include "sstream"
#include "iomanip"

using namespace controllers;

Application::Application()
    : mWindow(sf::VideoMode(720, 672), "Battle City"), gameOver(false), gameStarted(false),
    msgStart(90, 330, 25,"Press \'Enter\' to start"), msgOver(250, 300, 25, "Game over"),
    msgLost(260, 350, 25, "You lost"), msgWon(265, 350,25, "You won"), msgTimer(10,10,17, "Time: "),frags(0) {

    sf::Clock clock = sf::Clock();
    sf::Time tLastUpdate = sf::Time::Zero;
    sf::Time tTimePerFrame = sf::seconds(1.0f / 60);

    this->nTimer = 60;

    this->vecBases.push_back(new Base(336, 600));
    this->vecBases.push_back(new Base(610, 600));
    this->vecBases.push_back(new Base(336, 470));

    this->packOfEnemies.push_back(new Enemy(52,31));
    this->packOfEnemies.push_back(new Enemy(147,391));
    // this->packOfEnemies.push_back(new Enemy(532,391));
    // this->packOfEnemies.push_back(new Enemy(628,31));
   
    while (this->mWindow.isOpen()) {
        std::ostringstream timeSec;
        timeSec << std::setw(2) << std::setfill('0') << std::to_string((int)this->nTimer % 60);
        this->msgTimer.setText("Time " + std::to_string((int)this->nTimer / 60) + ":" + timeSec.str());
        tLastUpdate += clock.restart();

        process_events();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            this->gameStarted = true;

        while(tLastUpdate > tTimePerFrame){
            tLastUpdate -= tTimePerFrame;
            
            if (this->gameStarted && !this->gameOver){
                this->nTimer -= tTimePerFrame.asSeconds();  
                update(tTimePerFrame.asMilliseconds());}
        }
        render();
    }
}

void Application::process_events() {
    sf::Event event;
    while (this->mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->mWindow.close();
                break;
        }
    }
}

void Application::update(const sf::Int64 &time) {
    for (Enemy* enemyTank : this->packOfEnemies)
        if (!enemyTank->getlife())
            ++this->frags;
        else {
            this->frags = 0;
            break;
        }

    if (this->frags == 4)
        this->gameOver = true;

    if (!this->mPlayer.getlife())
        this->gameOver = true;

    if(this->nTimer <= 0)
        this->gameOver = true;

    int nTime = this->nTimer;

    if(nTime % 15 == 0){

        this->vecPickups.push_back(new Powerup(400, 600, SPEED_UP));


    }
    
    bool collision;

    for (Enemy* enemyTank : this->packOfEnemies) {
        collision = this->mPlayer.getSprite()->getGlobalBounds().intersects(enemyTank->getSprite()->getGlobalBounds());
        if (collision)
            this->mPlayer.collapse();
            //std::cout<<"Collision Detected"<<std::endl;
            
    }


    if (this->mPlayer.getlife()){

        this->mPlayer.update(time, map, collision);

    }

    for (Enemy* enemyTank : this->packOfEnemies) {

        if (enemyTank->getlife()) {
            enemyTank->update(time, map, collision, this->mPlayer);
        }
            
            if (enemyTank->getbullet()->getSprite().getGlobalBounds().intersects(this->mPlayer.getSprite()->getGlobalBounds()) 
                && enemyTank->getbullet()->getpresent()) {
                this->mPlayer.collapse();
                enemyTank->getbullet()->setpresent(false);
            }

            if (this->mPlayer.getbullet()->getSprite().getGlobalBounds().intersects(enemyTank->getSprite()->getGlobalBounds())
                && this->mPlayer.getbullet()->getpresent()) {
                enemyTank->collapse();
                this->mPlayer.getbullet()->setpresent(false);
            }

              for (Base* pBase : this->vecBases) {

                if (enemyTank->getbullet()->getSprite().getGlobalBounds().intersects(pBase->getSprite()->getGlobalBounds())
                && enemyTank->getbullet()->getpresent()) {
                pBase->setlife(false);
                this->gameOver = true;

                }

            }
    }
    

    for(Base* pBase : this->vecBases) {

        if (this->mPlayer.getbullet()->getSprite().getGlobalBounds().intersects(pBase->getSprite()->getGlobalBounds())
        && this->mPlayer.getbullet()->getpresent()) {

        pBase->setlife(false);
        this->gameOver = true;

        }

    }
}

void Application::render() {
    this->mWindow.clear();
    this->map.draw(this->mWindow);
    if (this->mPlayer.getlife())
        this->mWindow.draw(*(this->mPlayer.getSprite()));

    if (this->mPlayer.getbullet()->getpresent()) mWindow.draw((mPlayer.getbullet()->getSprite()));

    for (Enemy* enemyTank : this->packOfEnemies) {
        if (enemyTank->getbullet()->getpresent())
            mWindow.draw(enemyTank->getbullet()->getSprite());

        if (enemyTank->getlife())
            mWindow.draw(*(enemyTank->getSprite()));
    }

    for(Base* pBase : this->vecBases){

        if (pBase->getlife()){

            this->mWindow.draw(*(pBase->getSprite()));

        }
    }

     for(Powerup* pPowerup : this->vecPickups){

        this->mWindow.draw(*(pPowerup->getSprite()));

    }


    if (!gameStarted)
        this->msgStart.print(mWindow);
    else
        this->msgTimer.print(mWindow);
    if (this->gameOver) {
        this->msgOver.print(mWindow);
        if (!this->mPlayer.getlife()){

            this->msgLost.print(mWindow);

        }
        else{

            this->msgWon.print(mWindow);

        }
            
    }

    this->mWindow.display();
}

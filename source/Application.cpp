#include "../include/Application.h"
#include "sstream"
#include "iomanip"

using namespace controllers;

Application::Application()
    : mWindow(sf::VideoMode(720, 672), "Battle City"), gameOver(false), gameStarted(false), map(NONE),
    msgStart(90, 330, 25,"Select A level [1,2,3]"), msgOver(250, 300, 25, "Game over"),
    msgLost(260, 350, 25, "You lost"), msgWon(265, 350,25, "You won"), msgTimer(10,10,17, "Time: "),frags(0) {

    sf::Clock clock = sf::Clock();
    sf::Time tLastUpdate = sf::Time::Zero;
    sf::Time tTimePerFrame = sf::seconds(1.0f / 60);

    this->nTimer = 60;

    //this->packOfEnemies.push_back(new Enemy(147,391));
    // this->packOfEnemies.push_back(new Enemy(532,391));
    // this->packOfEnemies.push_back(new Enemy(628,31));
   
    while (this->mWindow.isOpen()) {
        std::ostringstream timeSec;
        timeSec << std::setw(2) << std::setfill('0') << std::to_string((int)this->nTimer % 60);
        this->msgTimer.setText("Time " + std::to_string((int)this->nTimer / 60) + ":" + timeSec.str());
        tLastUpdate += clock.restart();



        process_events();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !this->gameStarted){
            this->map.setMap((MapType)0);

            this->vecBases.push_back(new Base(14*24, 25*24, PLAYER));
            this->vecBases.push_back(new Base(6*24, 22*24, PLAYER));
            this->vecBases.push_back(new Base(22*24, 22*24, PLAYER));
            this->baseCount = 3;

            this->enemyBases.push_back(new Base(14 * 24, 5 * 24, ENEMY));
            this->enemyBases.push_back(new Base(6 * 24, 4 * 24, ENEMY));
            this->enemyBases.push_back(new Base(22 * 24, 4 * 24, ENEMY));
            this->enemyBaseCount = 3;

            this->packOfEnemies.push_back(new Enemy(14 * 24.3, 5 * 24.3));

            this->gameStarted = true;}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && !this->gameStarted){
            this->map.setMap((MapType)1);

            this->vecBases.push_back(new Base(14*24, 25*24, PLAYER));
            this->vecBases.push_back(new Base(26*24, 16*24, PLAYER));
            this->vecBases.push_back(new Base(22*24, 22*24, PLAYER));
            this->baseCount = 3;

            this->enemyBases.push_back(new Base(14 * 24, 5 * 24, ENEMY));
            this->enemyBases.push_back(new Base(2 * 24, 3 * 24, ENEMY));
            this->enemyBases.push_back(new Base(22 * 24, 4 * 24, ENEMY));
            this->enemyBaseCount = 3;

            this->packOfEnemies.push_back(new Enemy(14 * 24.3, 5 * 24.3));
            
            this->gameStarted = true;}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && !this->gameStarted){
            this->map.setMap((MapType)2);

            this->vecBases.push_back(new Base(15*24, 25*24, PLAYER));
            this->vecBases.push_back(new Base(6*24, 22*24, PLAYER));
            this->vecBases.push_back(new Base(25*24, 25*24, PLAYER));
            this->baseCount = 3;

            this->enemyBases.push_back(new Base(14 * 24, 3 * 24, ENEMY));
            this->enemyBases.push_back(new Base(4 * 24, 5 * 24, ENEMY));
            this->enemyBases.push_back(new Base(20 * 24, 5 * 24, ENEMY));
            this->enemyBaseCount = 3;

            this->packOfEnemies.push_back(new Enemy(14 * 24.3, 3 * 24.3));

            this->gameStarted = true;}

        while(tLastUpdate > tTimePerFrame){
            tLastUpdate -= tTimePerFrame;
            
            if (this->gameStarted && !this->gameOver){
                this->nTimer -= tTimePerFrame.asSeconds();  
                update(tTimePerFrame.asMilliseconds());
                
            }
            else{
                
            }
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

    if (!this->mPlayer.getlife() && (int)this->nTimer % 5 == 0){
        for(Base *pBase : this->vecBases){
            if(pBase->getlife()){
                this->mPlayer.setPos(pBase->getPos());
            }
        }
        this->mPlayer.setLife(true);
        
    }

    if (!this->packOfEnemies[0]->getlife() && (int)this->nTimer % 5 == 0){
        for(Base *pBase : this->enemyBases){
            if(pBase->getlife()){
                this->packOfEnemies[0]->setPos(sf::Vector2f(pBase->getPos().x + 4.5f , pBase->getPos().y + 3));
            }
        }
        this->packOfEnemies[0]->setLife(true);
    }

    if(this->nTimer <= 0)
        this->gameOver = true;

    int nTime = this->nTimer;

    if(nTime % 15 == 0 && this->canSpawnPowerup){
        bool passCheck = false;
                float x, y;
                
                while (!passCheck){
                    x = (rand() % (WIDTH_MAP));
                    y = (rand() % (HEIGHT_MAP));
                    if(this->map.getTilePassable(y,x)){
                        passCheck = true;
                    }
                    
                }
        this->vecPickups.push_back(new Powerup(x * 24, y * 24, &this->map, this->vecBases, this->enemyBases));
        this->canSpawnPowerup = false;

    }
    else{this->canSpawnPowerup = true;}
    
    bool collision;

    for (Enemy* enemyTank : this->packOfEnemies) {
        collision = this->mPlayer.getSprite()->getGlobalBounds().intersects(enemyTank->getSprite()->getGlobalBounds());
        if (collision)
            this->mPlayer.collapse();
            //std::cout<<"Collision Detected"<<std::endl;
            
    }

    for (Powerup* powerup : this->vecPickups){

        collision = this->mPlayer.getSprite()->getGlobalBounds().intersects(powerup->getSprite()->getGlobalBounds());
        if (collision)
            powerup->effect(&mPlayer);

    }


    if (this->mPlayer.getlife()){

        this->mPlayer.update(time, map, collision);

    }

    for (Enemy* enemyTank : this->packOfEnemies) {

        if (enemyTank->getlife()) {
            enemyTank->update(time, map, collision, this->mPlayer, this->vecBases, this->enemyBases);
        }
        else{
            enemyTank->resetEnemy();
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

            for (Powerup* powerup : this->vecPickups){

                if(enemyTank->getSprite()->getGlobalBounds().intersects(powerup->getSprite()->getGlobalBounds())){

                    powerup->effect(enemyTank);
                }
                    

            }

            for (Base* pBase : this->vecBases) {

                if (enemyTank->getSprite()->getGlobalBounds().intersects(pBase->getSprite()->getGlobalBounds())) {
                    if(pBase->getlife()){
                        pBase->setlife(false);
                        this->baseCount--;
                    }
                    if(this->baseCount == 0)
                        this->gameOver = true;

                }

            }
    }
    

    for(Base* pBase : this->enemyBases) {

        if (this->mPlayer.getSprite()->getGlobalBounds().intersects(pBase->getSprite()->getGlobalBounds())) {
            if(pBase->getlife()){
                pBase->setlife(false);
                this->enemyBaseCount--;
            }
            if(this->enemyBaseCount == 0)
                this->gameOver = true;
        }

    }

    if(nTime % 5 == 0){

        this->mPlayer.setSpeedMultiplier(1.0f);

        for (Enemy* enemyTank : this->packOfEnemies) {

            enemyTank->setSpeedMultiplier(1.0f);
        }


    }
}

void Application::render() {
    this->mWindow.clear();
    

    if (!gameStarted)
        this->msgStart.print(mWindow);
    else{
        this->msgTimer.print(mWindow);

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

        for(Base* pEBase : this->enemyBases){

            if (pEBase->getlife()){

                this->mWindow.draw(*(pEBase->getSprite()));

            }
        }

        for(Powerup* pPowerup : this->vecPickups){

            if(pPowerup->isActive()){

                this->mWindow.draw(*(pPowerup->getSprite()));

            }

            

        }
        this->msgTimer.print(mWindow);
    }
    if (this->gameOver) {
        this->msgOver.print(mWindow);
        if (!this->mPlayer.getlife() || this->baseCount == 0 || this->baseCount < this->enemyBaseCount){

            this->msgLost.print(mWindow);

        }
        else{

            this->msgWon.print(mWindow);

        }
            
    }

    this->mWindow.display();
}

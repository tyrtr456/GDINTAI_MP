#include "../include/Powerup.h"

using namespace models;

Powerup::Powerup(int posX, int posY, Map *pMap) {
    srand(time(NULL));

    this->pMap = pMap;


    this->EType = (PowerType)(rand() % 4);

    this->bActive = true;

    if(this->EType == SPEED_UP){

        this->mTexture.loadFromFile("media/powerupSprite.png");

    }

    else if(this->EType == MINE){

         this->mTexture.loadFromFile("media/mineSprite.png");

    }

    else if(this->EType == SPEED_DOWN){

         this->mTexture.loadFromFile("media/powerdownSprite.png");

    }

    else if(this->EType == CHAOS){

        this->mTexture.loadFromFile("media/chaosSprite.png");


    }

    
    
    this->mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(0, 0, 9, 12));
    this->mSprite.setPosition(posX, posY);
}

void Powerup::collapse(){

    this->bActive = false;
    this->mSprite.setPosition(0, 0);

}

 sf::Sprite* Powerup::getSprite(){

    return &(this->mSprite);
 }

bool Powerup::isActive(){

    return this->bActive;

}

 void Powerup::setTexture(sf::Texture *pTexture)
 {
    this->mTexture = *pTexture;
 }

 void Powerup::setSprite(sf::Sprite *pSprite)
 {
    this->mSprite = *pSprite;
 }
 
 void Powerup::effect(Tank* pTank, std::vector<Base*> vecBases, std::vector<Base*> vecEnemyBases){

    switch(this->EType){

        case PowerType::SPEED_UP:
            pTank->setSpeedMultiplier(2.0);
            this->collapse();
            break;

        case PowerType::SPEED_DOWN:
            pTank->setSpeedMultiplier(0.5);
            this->collapse();
            break;

        case PowerType::MINE:
            pTank->setLife(false);
            this->collapse();
            break;

        case PowerType::CHAOS:
            for(Base* pBase : vecBases){
                bool passCheck = false;
                float x, y;
                
                 while (passCheck != true){
                    x = (rand() % (WIDTH_MAP));
                    y = (rand() % (HEIGHT_MAP));
                    if(this->pMap->getTilePassable(y,x)){
                        passCheck = true;
                    }
                    
                }

                if(passCheck == true){

                    pBase->setPos(x * 24, y * 24);

                }
            }

            for(Base* pBase : vecEnemyBases){
                bool passCheck = false;
                float x, y;
                while (passCheck != true){
                    x = ((rand() % (WIDTH_MAP - 4)) + 2);
                    y = ((rand() % (HEIGHT_MAP - 2)) + 1);
                    if(this->pMap->getTilePassable(y,x)){
                        passCheck = true;
                    }
                    
                }

                if(passCheck == true){

                    pBase->setPos(x * 24, y * 24);

                }
            }
            this->collapse();
            break;
          
    }

 }



#include "../include/Powerup.h"

using namespace models;

Powerup::Powerup(int posX, int posY, Map *pMap, std::vector<Base*> vecBases, std::vector<Base*> vecEnemyBases, PowerType EType) {
    srand(time(NULL));

    this->pMap = pMap;
    this->vecBases = vecBases;
    this->vecEnemyBases = vecEnemyBases;

    this->EType = EType;

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
 
 void Powerup::effect(Tank* pTank){

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
            pTank->collapse();
            this->collapse();
            break;

        case PowerType::CHAOS:
            for(Base* pBase : this->vecBases){
                pBase->setPos(((rand() % (WIDTH_MAP - 4)) + 2) * 24, ((rand() % (HEIGHT_MAP - 2)) + 1) * 24);
            }

            for(Base* pBase : this->vecEnemyBases){
                pBase->setPos(((rand() % (WIDTH_MAP - 4)) + 2) * 24, ((rand() % (HEIGHT_MAP - 2)) + 1) * 24);
            }
            this->collapse();
            break;
          
    }

 }



#include "../include/Powerup.h"

using namespace models;

Powerup::Powerup(int posX, int posY, PowerType EType) {

    this->EType = EType;

    this->mTexture.loadFromFile("media/powerupSprite.png");
    this->mSprite.setTexture(mTexture);
    this->mSprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    this->mSprite.setPosition(posX, posY);
}

 sf::Sprite* Powerup::getSprite(){

    return &(this->mSprite);
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
            pTank->setSpeed(pTank->getSpeed() * 2.0);
            break;

        case PowerType::SPEED_DOWN:
            pTank->setSpeed(pTank->getSpeed() / 2.0);
            break;

        case PowerType::MINE:
            pTank->collapse();
            break;

        case PowerType::CHAOS:
            if(pTank->getType() == ENEMY_TANK){


            }

            else if (pTank->getType() == PLAYER_TANK){


            }

            break;
          
    }

 }



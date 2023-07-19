#include "../include/Base.h"
//#include "Base.h"

using namespace models;

Base::Base(int posX, int posY) {

    this->life = true;

    this->mTexture.loadFromFile("media/baseSprite.png");
    this->mSprite.setTexture(mTexture);
    this->mSprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    this->mSprite.setPosition(posX, posY);
}

 sf::Sprite* Base::getSprite(){

    return &(this->mSprite);
 }

 bool Base::getlife()
 {
    return this->life;
 }

 void Base::setTexture(sf::Texture *pTexture)
 {
    this->mTexture = *pTexture;
 }

 void Base::setSprite(sf::Sprite *pSprite)
 {
    this->mSprite = *pSprite;
 }

 void Base::setlife(bool life)
 {
    this->life = life;
 }

#include "Base.h"

using namespace models;

Base::Base() {

    this->life = true;

    this->mTexture.loadFromFile("battle-city-src/media/baseSprite.png");
    this->mSprite.setTexture(mTexture);
    this->mSprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    this->mSprite.setPosition(336, 600);
}

 sf::Sprite* Base::getSprite(){

    return &(this->mSprite);

 }
#include "../include/Base.h"
//#include "Base.h"

using namespace models;

Base::Base(int posX, int posY, BaseType EType) {

    this->life = true;

    this->EType = EType;

   if(EType == BaseType::PLAYER){
      this->mTexture.loadFromFile("media/baseSprite.png");
   }

   else{
      this->mTexture.loadFromFile("media/baseSpriteEnemy.png");
   }
    
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

void Base::setPos(int x, int y){
this->mSprite.setPosition(x, y);
}

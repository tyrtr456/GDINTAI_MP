#include "../include/Tank.h"
//#include "Tank.h"

using namespace models;

Tank::Tank(const float &x, const float &y, const float &width, const float &height, const sf::String &file)
    : life(true), mX(x), mY(y), mDx(0.f), mDy(0.f), mFile(file), mDir(0), mCollision(false),
    mCurrentFrame(0.f), mSpeed(0.f), mWidth(width), mHeight(height), 
    bullet(x, y) {

    this->mTexture.loadFromFile(mFile);
    this->mSprite.setTexture(mTexture);
    this->mSprite.setTextureRect(sf::IntRect(78, 39, mWidth, mHeight));
    this->mSprite.setPosition(x, y);
}

void Tank::animate(const sf::Int64 &time) {
    this->mCurrentFrame += 0.005f * time;
    if (this->mCurrentFrame >= 2)
        this->mCurrentFrame -= 2;

    if (this->mDx > 0.f)
        this->mSprite.setTextureRect(sf::IntRect(0 + 39 * (int)mCurrentFrame, 0, 39, 39));
    if (this->mDx < 0.f)
        this->mSprite.setTextureRect(sf::IntRect(78 + 39 * (int)mCurrentFrame, 0, 39, 39));
    if (this->mDy > 0.0f)
        this->mSprite.setTextureRect(sf::IntRect(0 + 39 * (int)mCurrentFrame, 39, 39, 39));
    if (this->mDy < 0.0f)
        this->mSprite.setTextureRect(sf::IntRect(78 + 39 * (int)mCurrentFrame, 39, 39, 39));
}

void Tank::collapse() {
    this->life = false;
    this->getbullet()->setpresent(false);
    this->mSprite.setPosition(0, 0);
}

void Tank::map_interaction(Map &map) {
    for (int i = mY / 24; i < (mY + mHeight) / 24; ++i)
        for (int j = mX / 24; j < (mX + mWidth) / 24; ++j) {
            char tile = map.get_tile(i, j);

            if (tile >= '0' && tile <= '2') {
                if (this->mDy > 0.f)
                    this->mY = i * 24 - this->mHeight;

                if (this->mDy < 0.f)
                    this->mY = (float)i * 24 + 24;

                if (this->mDx > 0.f)
                    this->mX = j * 24 - this->mWidth;

                if (this->mDx < 0.f)
                    this->mX = (float)j * 24 + 24;
            }
        }

}

void Tank::tank_interaction() {
    if (this->mDy > 0.f)
        this->mY -= 0.3f;

    if (this->mDy < 0.f)
        this->mY += 0.3f;

    if (this->mDx > 0.f)
        this->mX -= 0.3f;

    if (this->mDx < 0.f)
        this->mX += 0.3f;
}

float Tank::getmX()
{
    return this->mX;
}

float Tank::getmY()
{
    return this->mY;
}

float Tank::getmWidth()
{
    return this->mWidth;
}

float Tank::getmHeight()
{
    return this->mHeight;
}

float Tank::getmDx()
{
    return this->mDx;
}

float Tank::getmDy()
{
    return this->mDy;
}

float Tank::getSpeed()
{
    return this->mSpeed;
}

int Tank::getDir()
{
    return this->mDir;
}

float Tank::getCurrentFrame()
{
    return this->mCurrentFrame;
}

bool Tank::getCollision()
{
    return this->mCollision;
}

bool Tank::getlife()
{
    return this->life;
}

sf::Sprite* Tank::getSprite(){

    
    return &(this->mSprite);

}

Bullet* Tank::getbullet(){

    return &(this->bullet);

}



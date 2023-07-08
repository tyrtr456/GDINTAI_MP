#include "../include/Bullet.h"


using namespace models;

Bullet::Bullet(const float &x, const float &y)
    : present(false), mX(x), mY(y), mDir(0), mDx(0.f), mDy(0.f), timeBeforeShot(0.f) {

    mTexture.loadFromFile("media/bulletSprite.png");
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(0, 0, 9, 12));
    mSprite.setPosition(x, y);
}

void Bullet::move(const sf::Int64 &time) {
    switch (this->mDir) {
        case 0:
            this->mDx = 1.0f;
            this->mDy = 0;
			this->mSprite.setRotation(90.f);
            break;

        case 1:
            this->mDx = -1.0f;
            this->mDy = 0;
			this->mSprite.setRotation(-90.f);
            break;

        case 2:
            this->mDx = 0;
            this->mDy = 1.0f;
			this->mSprite.setRotation(180.f);
            break;

        case 3:
            this->mDx = 0;
            this->mDy = -1.0f;
			this->mSprite.setRotation(0.f);
            break;
    }

    this->mX += this->mDx * time;
    this->mY += this->mDy * time;
	this->mSprite.setPosition(this->mX, this->mY);
}

void Bullet::update(Map &map, const sf::Int64 &time, float &x, const float &y, const int &dir) {
    if (this->present == true) {
        move(time);
        map_interaction(map);
    }
    else {
		this->mDir = dir;
        switch (this->mDir) {
        case 0:
            this->mX = x + 35.f;
            this->mY = y + 15.f;
            break;

        case 1:
            this->mX = x + 7.f;
            this->mY = y + 23.f;
            break;

        case 2:
            this->mX = x + 23.f;
            this->mY = y + 32.f;
            break;

        case 3:
            this->mX = x + 15.f;
            this->mY = y + 5.f;
            break;
        }
		this->mSprite.setPosition(this->mX, this->mY);
    }
}

void Bullet::map_interaction(Map &map) {
    for (int i = this->mY / 24; i < (this->mY + 12) / 24; ++i)
        for (int j = this->mX / 24; j < (this->mX + 9) / 24; ++j) {
            char tile = map.get_tile(i, j);

            if (tile == '0' || tile == '2')
                this->present = false;

            if (tile == '1') {
                map.break_wall(i, j);
                this->present = false;
            }
        }
}

float Bullet::getmX()
{
    return mX;
}

float Bullet::getmY()
{
    return this->mY;
}

float Bullet::getmDx()
{
    return this->mDx;
}

float Bullet::getmDy()
{
    return this->mDy;
}

int Bullet::getmDir()
{
    return this->mDir;
}

bool Bullet::getpresent()
{
    return this->present;
}

float Bullet::getBeforeShot()
{
    return this->timeBeforeShot;
}

sf::Texture Bullet::getTexture()
{
    return this->mTexture;
}

sf::Sprite Bullet::getSprite()
{
    return this->mSprite;
}

void Bullet::setpresent(bool bVal)
{

    this->present = bVal;
}

void models::Bullet::setBeforeShot(float fVal)
{
    this->timeBeforeShot = fVal;
}

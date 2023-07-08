#include "../include/Enemy.h"
//#include "Enemy.h"

using namespace models;

Enemy::Enemy(const float &x, const float &y)
    : Tank(x, y, 39, 39, "media/enemySprites.png"), timeBeforeMoving(0.f), timeBeforeShot(0.f) {

}

void Enemy::move(const sf::Int64 &time) {
    this->mSpeed = 0.1f;
    this->timeBeforeMoving += time;

    if (this->timeBeforeMoving > 1000 + rand() % 501) {
        this->mDir = rand() % 4;
        this->timeBeforeMoving = 0.f;
    }

    switch (this->mDir) {
        case 0:
            this->mDx = this->mSpeed;
            this->mDy = 0;
            break;

        case 1:
            this->mDx = -mSpeed;
            this->mDy = 0;
            break;

        case 2:
            this->mDx = 0;
            this->mDy = this->mSpeed;
            break;

        case 3:
            this->mDx = 0;
            this->mDy = -this->mSpeed;
            break;
    }
    if (this->mCollision) tank_interaction();
    this->mX += this->mDx * time;
    this->mY += this->mDy * time;
}

void Enemy::shoot(const float &time) {

    this->timeBeforeShot += time;

    if (this->timeBeforeShot > 1000.f) {
        if (this->getbullet()->getpresent() == false)
            if (rand() % 2)
                this->getbullet()->getpresent() == true;

        this->timeBeforeShot = 0.f;
    }
}

void Enemy::update(const sf::Int64 &time, Map &map, const bool &collision) {
    this->mCollision = collision;
    this->move(time);

    this->mSpeed = 0.f;
    this->mSprite.setPosition(this->mX, this->mY);
    this->animate(time);
    this->map_interaction(map);

    this->bullet.update(map, time, this->mX, this->mY, this->mDir);
    this->shoot(time);
}
float Enemy::getBeforeMoving()
{
    return this->timeBeforeMoving;
}

float Enemy::getBeforeShot()
{
    return this->timeBeforeShot;
}

void Enemy::setBeforeMoving(float nVal)
{
    this->timeBeforeMoving = nVal;
}

void Enemy::setBeforeShot(float nVal)
{
     this->timeBeforeShot = nVal;
}

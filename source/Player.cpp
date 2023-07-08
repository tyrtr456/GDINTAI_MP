
#include "../include/Player.h"

using namespace models;

Player::Player()
    : Tank(244, 600, 39, 39, "media/playerSprites.png") {

}

void Player::move(const sf::Int64 &time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        mDir = 1;
        mSpeed = 0.11f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        mDir = 0;
        mSpeed = 0.11f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        mDir = 3;
        mSpeed = 0.11f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        mDir = 2;
        mSpeed = 0.11f;
    }

    switch (mDir) {
        case 0:
            mDx = mSpeed;
            mDy = 0;
            break;

        case 1:
            mDx = -mSpeed;
            mDy = 0;
            break;

        case 2:
            mDx = 0;
            mDy = mSpeed;
            break;

        case 3:
            mDx = 0;
            mDy = -mSpeed;
            break;
    }
    if (this->mCollision) tank_interaction();
    this->mX += this->mDx * time;
    this->mY += this->mDy * time;
}

void Player::update(const sf::Int64 &time, Map &map, const bool &collision) {
    mCollision = collision;
    move(time);

    this->mSpeed = 0.f;
    this->mSprite.setPosition(mX, mY);
    animate(time);
    map_interaction(map);

    this->bullet.update(map, time, mX, mY, mDir);
    if (!this->bullet.getpresent())
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->bullet.setBeforeShot(this->bullet.getBeforeShot() + time);
            if (this->bullet.getBeforeShot() > 10.f) {
                this->bullet.setpresent(true);
                this->bullet.setBeforeShot(0.f);
            }
        }
}

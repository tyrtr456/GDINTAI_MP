
#include "../include/Player.h"

using namespace models;

Player::Player()
    : Tank(244, 600, 39, 39, "media/playerSprites.png") {
        
        this->EType = PLAYER_TANK;

}

void Player::move(const sf::Int64 &time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->mDir = 1;
        this->mSpeed = 0.11f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->mDir = 0;
        this->mSpeed = 0.11f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->mDir = 3;
        this->mSpeed = 0.11f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->mDir = 2;
        this->mSpeed = 0.11f;
    }

    switch (this->mDir) {
        case 0:
            this->mDx = this->mSpeed;
            this->mDy = 0;
            break;

        case 1:
            this->mDx = -this->mSpeed;
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

void Player::update(const sf::Int64 &time, Map &map, const bool &collision) {
    this->mCollision = collision;

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

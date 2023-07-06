#ifndef MODELS_ENEMY_H
#define MODELS_ENEMY_H

#include "Tank.h"

namespace models{

    class Enemy : public Tank {

    private:
        float timeBeforeMoving;
        float timeBeforeShot;

    public:
        Enemy(const float &x, const float &y);
        Enemy(const Enemy &copy) : Enemy(copy.mX, copy.mY){}

        void move(const sf::Int64 &time);
        void shoot(const float &time);
        void update(const sf::Int64 &time, Map &map, const bool &collision);

    public:
        float getBeforeMoving();
        float getBeforeShot();
        void setBeforeMoving();
        void setBeforeShot();

    };



}

#endif

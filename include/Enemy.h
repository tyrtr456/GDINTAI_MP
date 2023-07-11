#ifndef MODELS_ENEMY_H
#define MODELS_ENEMY_H

#include "Tank.h"

namespace models{

    class Enemy : public Tank {

    private:
        sf::Vector2f NextPos;
        float timeBeforeMoving;
        float timeBeforeShot;

        bool canChangeDir = true;

        std::vector<char> vecMoveSet;
    public:
        Enemy(const float &x, const float &y);
        Enemy(const Enemy &copy) : Enemy(copy.mX, copy.mY){}

        void smartmove(const sf::Int64 &time, char Dir);
        void setDir(char Dir);
        void movePos(const sf::Int64 & time);
        void move(const sf::Int64 &time);
        void shoot(const float &time);
        void update(const sf::Int64 &time, Map &map, const bool &collision, Player &player);

    public:
        float getBeforeMoving();
        float getBeforeShot();
        void setBeforeMoving(float nVal);
        void setBeforeShot(float nVal);
    };



}

#endif

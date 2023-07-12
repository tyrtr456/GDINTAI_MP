#include "../include/Enemy.h"


using namespace models;

Enemy::Enemy(const float &x, const float &y) 
    : Tank(x, y, 39, 39, "media/enemySprites.png"), timeBeforeMoving(0.f), timeBeforeShot(0.f) {
    
    this->NextPos.x = this->mX;
    this->NextPos.y = this->mY;

    this->vecMoveSet.push_back('E');

    this->pAI = new TankAI(this->mX, this->mY);

}

void Enemy::smartmove(const sf::Int64 &time) {
    this->mSpeed = 0.1f;

    if(this->canChangeDir){

        this->canChangeDir = false;
        switch(this->nextDir){
            case 'E': 
                this->mDir = 0;
                this->NextPos.x = this->mX + 23;
                break;
            case 'W': 
                this->mDir = 1;
                this->NextPos.x = this->mX - 23;
                break;
            case 'S': 
                this->mDir = 2; 
                this->NextPos.y = this->mY + 23;
                break;
            case 'N':
                this->mDir = 3;
                this->NextPos.y = this->mY - 23;
                break;
            default: 
                this->canChangeDir = true;
                break;
        }
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
        default: 
            this->mDx = 0;
            this->mDy = 0;
            break;
    }
    
    if (this->mCollision) tank_interaction();
    
    switch(this->mDir){
        case 0:
            if(this->mX < this->NextPos.x) this->mX += this->mDx * time; 
            else this->canChangeDir = true; break;
        case 1:
            if(this->mX > this->NextPos.x) this->mX += this->mDx * time; 
            else this->canChangeDir = true; break;
        case 2:
            if(this->mY < this->NextPos.y) this->mY += this->mDy * time;
            else this->canChangeDir = true; break;
        case 3:
            if(this->mY > this->NextPos.y) this->mY += this->mDy * time; 
            else this->canChangeDir = true; break;
        
    }

}


void Enemy::breadthFirstSearch(Map &map, Player &player){

    pAI->setSelfX(this->mX);
    pAI->setSelfY(this->mY);

    pAI->logMapEdges(map, player);

    

    pAI->searchPath();

    this->nextDir = pAI->logPath();
    
    //std::cout << "GetBFS" << std::endl;
    //std::cout<<this->nextDir<<std::endl;
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

void Enemy::shoot(const float &time) {

    this->timeBeforeShot += time;

    if (this->timeBeforeShot > 1000.f) {
        
        if (this->bullet.getpresent() == false)
            if (/*rand() % 2*/1){
                this->bullet.setpresent(true);
            }

        this->timeBeforeShot = 0.f;
    }
}

void Enemy::update(const sf::Int64 &time, Map &map, const bool &collision, Player &player) {
    this->mCollision = collision;
    this->breadthFirstSearch(map, player);
    
    this->smartmove(time);

    this->mSpeed = 0.f;
    this->mSprite.setPosition(this->mX, this->mY);
    
    this->map_interaction(map);

    this->bullet.update(map, time, this->mX, this->mY, this->mDir);
    if(this->getSprite()->getPosition().x > player.getSprite()->getPosition().x - 16 
       && this->getSprite()->getPosition().x < player.getSprite()->getPosition().x + 16){
        this->shoot(time);
        // if(this->getSprite()->getPosition().y > player.getSprite()->getPosition().y)
        //     this->mDir = 3;
        // else if(this->getSprite()->getPosition().y < player.getSprite()->getPosition().y)
        //     this->mDir = 2;
            
    }
    else if(this->getSprite()->getPosition().y > player.getSprite()->getPosition().y - 16
            && this->getSprite()->getPosition().y < player.getSprite()->getPosition().y + 16){
        this->shoot(time);
        // if(this->getSprite()->getPosition().x > player.getSprite()->getPosition().x)
        //     this->mDir = 1;
        // else if(this->getSprite()->getPosition().x < player.getSprite()->getPosition().x)
        //     this->mDir = 0;
    }
    else{
        //this->move(time);
    }

    switch (this->mDir) {
        case 0:
            this->mDx = 1;
            this->mDy = 0;
            break;

        case 1:
            this->mDx = -1;
            this->mDy = 0;
            break;

        case 2:
            this->mDx = 0;
            this->mDy = 1;
            break;

        case 3:
            this->mDx = 0;
            this->mDy = -1;
            break;
        default: 
            this->mDx = 0;
            this->mDy = 0;
            break;
    }

    this->animate(time);
    
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

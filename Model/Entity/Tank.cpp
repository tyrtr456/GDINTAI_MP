#include "Tank.hpp"

using namespace models;

Tank::Tank(){

    this->nHealth = 0;
    this->nTankRow = 0;
    this->nTankCol = 0;
    this->eDirection = DireType::NORTH;

    //this->tankAgent = NULL;
}

Tank::~Tank(){

}


void Tank::move(){

}

void Tank::shoot(){

}

int Tank::getHealth(){

    return this->nHealth;


}


int Tank::getTankRow(){

    return this->nTankRow;


}
int Tank::getTankCol(){

    return this->nTankCol;

}

DireType Tank::getDirection(){

    return this->eDirection;

}

//Agent* Tank::getAgent(){


//}

void Tank::setHealth(int nValue){

    this->nHealth = nValue;


}


void Tank::setTankRow(float fVal){

    this->nTankRow = fVal;

}
void Tank::setTankCol(float fVal){

    this->nTankCol = fVal;

}

void Tank::setDirection(DireType Direction){

    this->eDirection = Direction;

}
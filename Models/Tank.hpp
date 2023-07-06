#ifndef MODELS_TANK_HPP
#define MODELS_TANK_HPP

#include "../Enum/DireType.hpp"

namespace models{

    class Tank {

        private:
            int nHealth;
            float nTankRow;
            float nTankCol;
            //Agent* tankAgent;
            DireType eDirection;

        public:
            Tank();

        public:
            ~Tank();

        public:
            void move();
            void shoot();

        public:
            int getHealth();
            int getTankRow();
            int getTankCol();
            DireType getDirection();
            //Agent* getAgent();

        public:
            void setHealth(int nValue);
            void setTankRow(float fVal);
            void setTankCol(float fVal);
            void setDirection(DireType Direction);


    };

}


#endif
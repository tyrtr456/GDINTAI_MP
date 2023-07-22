#ifndef MODELS_TANK_H
#define MODELS_TANK_H

#include "Bullet.h"
#include "../enum/EnumTankType.h"


namespace models{

    class Tank   {

        protected:
            float mX, mY, mWidth, mHeight, mDx, mDy, mSpeed;
            int mDir;
            float mCurrentFrame;
            bool mCollision;
            bool life;
            sf::String mFile;
            sf::Texture mTexture;
            sf::Sprite mSprite;
            Bullet bullet;
            TankType EType;

        public:
            Tank(const float &x, const float &y, const float &width, const float &height, const sf::String &file);

        public:
            void animate(const sf::Int64 &time);
            void collapse();
            virtual void move(const sf::Int64 &time) = 0;
            void map_interaction(Map &map);
            void tank_interaction();

        public:
            float getmX();
            float getmY();
            float getmWidth();
            float getmHeight();
            float getmDx();
            float getmDy();
            float getSpeed();
            int getDir();
            float getCurrentFrame();
            bool getCollision();
            bool getlife();
            sf::Sprite* getSprite();
            Bullet* getbullet();
            TankType getType();
            void setSpeed(float fVal);

            
    };




}
    

#endif

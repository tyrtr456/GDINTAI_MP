#ifndef MODELS_BULLET_H
#define MODELS_BULLET_H

#include "Map.h"

namespace models{

    class Bullet {
        private:
            float mX, mY, mDx, mDy;
            int mDir;
            sf::Texture mTexture;
            bool present; //is it shot?
            float timeBeforeShot;
	        sf::Sprite mSprite;

        public:
            Bullet(const float &x, const float &y);
        
        public:
	        void shoot() { this->present = true; }
            void move(const sf::Int64 &time);
            void update(Map &map, const sf::Int64 &time, float &x, const float &y, const int &dir);
            void map_interaction(Map &map);
        
        public:
            float getmX();
            float getmY();
            float getmDx();
            float getmDy();
            int getmDir();
            bool getpresent();
            float getBeforeShot();
            sf::Texture getTexture();
            sf::Sprite getSprite();
            void setpresent(bool bVal);
            void setBeforeShot(float fVal);


    };


}

#endif

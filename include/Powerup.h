#ifndef MODELS_POWERUP_H
#define MODELS_POWERUP_H

#include "Base.h"
#include "Tank.h"
#include "../enum/EnumPowerType.h"    

namespace models{

    class Powerup {
    private:
        sf::Texture mTexture;
        sf::Sprite mSprite;
        PowerType EType;
        bool bActive;
        

    public:
        Powerup(int posX, int posY, PowerType EType);

    public:
        sf::Texture getTexture();
        sf::Sprite* getSprite();
        bool isActive();
        void collapse();

    public:
        void setTexture(sf::Texture* pTexture);
        void setSprite(sf::Sprite* pSprite);
        void effect(Tank* pTank);
    
    


    };


}

#endif
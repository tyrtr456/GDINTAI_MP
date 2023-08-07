#ifndef MODELS_POWERUP_H
#define MODELS_POWERUP_H

#include "Base.h"
#include "Tank.h"
#include "Map.h"
#include "Settings.h"
#include "../enum/EnumPowerType.h"    
#include "cstdlib"

namespace models{

    class Powerup {
    private:

        Map *pMap;

        std::vector<Base*> vecBases;
        std::vector<Base*> vecEnemyBases;

        sf::Texture mTexture;
        sf::Sprite mSprite;
        PowerType EType;
        bool bActive;
        

    public:
        Powerup(int posX, int posY, Map *pMap, std::vector<Base*> vecBases, std::vector<Base*> vecEnemyBases);

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
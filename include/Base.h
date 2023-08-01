#ifndef MODELS_BASE_H
#define MODELS_BASE_H

#include "../enum/EnumBaseType.h"

namespace models{

    class Base {
    private:
        sf::Texture mTexture;
        sf::Sprite mSprite;
        BaseType EType;
        bool life;

    public:
        Base(int posX, int posY, BaseType EType);

    public:
        sf::Texture getTexture();
        sf::Sprite* getSprite();
        bool getlife();

    public:
        void setTexture(sf::Texture* pTexture);
        void setSprite(sf::Sprite* pSprite);
        void setlife(bool life);


    };


}

#endif
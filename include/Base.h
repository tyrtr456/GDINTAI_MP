#ifndef MODELS_BASE_H
#define MODELS_BASE_H

namespace models{

    class Base {
    private:
        sf::Texture mTexture;
        sf::Sprite mSprite;
        bool life;

    public:
        Base();

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
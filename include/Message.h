#ifndef MODELS_MESSAGE_H
#define MODELS_MESSAGE_H

namespace models{

    class Message {
        
    private:

    float mX, mY;

    sf::Font mFont;
    sf::Text mStr;

    public:
    Message(const float &x, const float &y, const sf::String &str);

    void print(sf::RenderWindow &window) { window.draw(mStr); }
};



}


#endif


#include "../include/Message.h"

Message::Message(const float &x, const float &y, int nSize ,const sf::String &str)
    : mX(x), mY(y) {
    
    mFont.loadFromFile("media/PressStart2P.ttf");
    mStr.setFont(mFont);
    mStr.setString(str);
    mStr.setPosition(mX, mY);
    mStr.setCharacterSize(nSize);
}

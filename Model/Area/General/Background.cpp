#include "Background.hpp"

using namespace models;

Background::Background(std::string strName, AnimatedTexture* pTexture, bool bScaleToWidth) : GameObject(strName, pTexture) {
    this->bScaleToWidth = bScaleToWidth;
}

Background::~Background() {}

void Background::initialize() {
    this->setFrame(0);

    Renderer* pRenderer = new Renderer(this->strName + " Background");
    pRenderer->assignDrawable(this->pSprite);

    if(this->bScaleToWidth)
        pRenderer->scaleWidth(SCREEN_WIDTH);
    else
        pRenderer->scaleHeight(SCREEN_HEIGHT);

    this->attachComponent(pRenderer);
}

#include "Renderer.hpp"

using namespace components;

Renderer::Renderer(std::string strName, DrawOrder EDrawOrder) : Component(strName, ComponentType::RENDERER) {
    this->CRenderStates = sf::RenderStates::Default;
    this->EDrawOrder = EDrawOrder;
}

void Renderer::perform() {
    this->pWindow->draw(*this->pDrawable, this->CRenderStates);
}

// void Renderer::flip() {
//     sf::Sprite* pSprite = (sf::Sprite*)this->pDrawable;
//     pSprite->setScale(-pSprite->getScale().x, pSprite->getScale().y);
// }

void Renderer::scaleWidth(int nResize) {
    sf::Sprite* pSprite = (sf::Sprite*)this->pDrawable;
    float fScale = this->scale(pSprite->getLocalBounds().width, nResize);
    pSprite->setScale(fScale, fScale);
}

void Renderer::scaleHeight(int nResize) {
    sf::Sprite* pSprite = (sf::Sprite*)this->pDrawable;
    float fScale = this->scale(pSprite->getLocalBounds().height, nResize);
    pSprite->setScale(fScale, fScale);
}

float Renderer::scale(int nOriginal, int nResize) {
    float fScale = (float)nResize / (float)nOriginal;
    return fScale;
}

void Renderer::assignTargetWindow(sf::RenderWindow* pWindow) {
    this->pWindow = pWindow;
}

void Renderer::assignDrawable(sf::Drawable* pDrawable) {
    this->pDrawable = pDrawable;
}

void Renderer::setRenderStates(sf::RenderStates CRenderStates) {
    this->CRenderStates = CRenderStates;
}

DrawOrder Renderer::getDrawOrder() {
    return this->EDrawOrder;
}

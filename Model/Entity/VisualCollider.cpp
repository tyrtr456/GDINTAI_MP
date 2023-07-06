#include "VisualCollider.hpp"

using namespace models;

VisualCollider::VisualCollider(std::string strName, sf::FloatRect CBounds, sf::FloatRect COffset, sf::Color CColor) : GameObject(strName, NULL) {
    this->CBounds = CBounds;
    this->COffset = COffset;
    this->CColor = CColor;
}

VisualCollider::~VisualCollider() {}

void VisualCollider::initialize() {
    this->pRectangle = new sf::RectangleShape(sf::Vector2f(this->CBounds.width, this->CBounds.height));
    this->pRectangle->setPosition(this->CBounds.left, this->CBounds.top);
    this->pRectangle->setFillColor(this->CColor);
    
    this->pCollider = new Collider(this->strName + " Visual Collider");
    this->pCollider->setOffset(this->COffset);
}

sf::FloatRect VisualCollider::getGlobalBounds() {
    return this->pRectangle->getGlobalBounds();
}

Collider* VisualCollider::getCollider() {
    return this->pCollider;
}

void VisualCollider::setListener(CollisionListener* pListener) {
    this->pCollider->setListener(pListener);
}

void VisualCollider::setX(float fX) {
    this->pRectangle->setPosition(fX, this->pRectangle->getPosition().y);
}

void VisualCollider::setWidth(float fWidth) {
    this->pRectangle->setSize(sf::Vector2f(fWidth, this->pRectangle->getSize().y));
}

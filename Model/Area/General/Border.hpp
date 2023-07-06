#ifndef MODELS_BORDER_HPP
#define MODELS_BORDER_HPP

#include "../../../Config/Settings.hpp"
#include "../../../Controller/System/PhysicsManager.hpp"

#include "../../AnimatedTexture.hpp"
#include "../../GameObject.hpp"
#include "../../Component/Physics/Collider.hpp"
#include "../../Component/Physics/Interface/CollisionListener.hpp"

namespace models {
    using namespace components;
    using namespace listeners;
    using namespace systems;
    
    class Border : public GameObject, public CollisionListener {
        protected:
            sf::RectangleShape* pRectangle;
            sf::FloatRect CBounds;
            sf::FloatRect COffset;
            Collider* pCollider;
            sf::Color CColor;

        public:
            Border(std::string strName, sf::FloatRect CBounds);
            Border(std::string strName, AnimatedTexture* pTexture, sf::Vector2f CPosition);
            ~Border();

        public:
            virtual void initialize();
            virtual void onCollisionEnter(Collider* pCollider) = 0;
            virtual void onCollisionContinue(Collider* pCollider) = 0;
            virtual void onCollisionExit(Collider* pCollider) = 0;

        public:
            virtual sf::FloatRect getGlobalBounds();
            virtual void setPosition(float fX, float fY);
        
        public:
            Collider* getCollider();
    };
}

#endif
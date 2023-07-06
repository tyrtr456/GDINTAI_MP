#ifndef MODELS_VISUAL_COLLIDER_HPP
#define MODELS_VISUAL_COLLIDER_HPP

#include "../../Config/Settings.hpp"
#include "../../Controller/System/PhysicsManager.hpp"

#include "../AnimatedTexture.hpp"
#include "../GameObject.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Component/Physics/Interface/CollisionListener.hpp"

namespace models {
    using namespace components;
    using namespace listeners;
    using namespace systems;
    
    class VisualCollider : public GameObject {
        protected:
            sf::RectangleShape* pRectangle;
            sf::FloatRect CBounds;
            sf::FloatRect COffset;
            Collider* pCollider;
            sf::Color CColor;
            Renderer* pRenderer;

        public:
            VisualCollider(std::string strName, sf::FloatRect CBounds, sf::FloatRect COffset, sf::Color CColor = sf::Color::Magenta);
            ~VisualCollider();

        public:
            virtual void initialize();

        public:
            sf::FloatRect getGlobalBounds();
        
        public:
            Collider* getCollider();
            void setListener(CollisionListener* pListener);
            void setX(float fX);
            void setWidth(float fWidth);
    };
}

#endif
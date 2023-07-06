#ifndef COMPONENTS_COLLIDER_HPP
#define COMPONENTS_COLLIDER_HPP

#include "../../Enum/EnumComponentType.hpp"
#include "../Component.hpp"
#include "Interface/CollisionListener.hpp"

namespace components {
    using namespace listeners;

    class Collider : public Component {
        private:
            CollisionListener* pListener;
            sf::FloatRect COffset;
            std::vector<Collider*> vecCollided;
            bool bCleanUp;
            bool bFollowParent;

        public:
            Collider(std::string strName, bool bFollowParent = true);

        public:
            void perform();
            bool isColliding(Collider* pCollider);
            
            int findCollider(Collider* pCollider);
            void cleanCollisions();

            void onCollisionEnter(Collider* pCollider);
            void onCollisionContinue(Collider* pCollider);
            void onCollisionExit(Collider* pCollider);

        public:
            void setListener(CollisionListener* pListener);
            sf::FloatRect getOffset();
            void setOffset(sf::FloatRect COffset);
            bool hasCollided(Collider* pCollider);
            void setCollided(Collider* pCollider, bool bCollided);

            bool isCleanUp();
            void setCleanUp(bool bCleanUp);
            sf::FloatRect getGlobalBounds();
    };
}

#endif
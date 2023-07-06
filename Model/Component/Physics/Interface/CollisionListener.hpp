#ifndef LISTENERS_COLLISION_LISTENER_HPP
#define LISTENERS_COLLISION_LISTENER_HPP

namespace components {
    class Collider;
}

namespace listeners {
    using namespace components;
    
    class CollisionListener {
        public:
            ~CollisionListener() {}

        public:
            virtual void onCollisionEnter(Collider* pCollider) = 0;
            virtual void onCollisionContinue(Collider* pCollider) = 0;
            virtual void onCollisionExit(Collider* pCollider) = 0;
    };
}

#endif
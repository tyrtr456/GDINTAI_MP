#ifndef SYSTEMS_PHYSICS_MANAGER_HPP
#define SYSTEMS_PHYSICS_MANAGER_HPP

#include "../../Model/GameObject.hpp"
#include "../../Model/Enum/EnumComponentType.hpp"

#include "../../Model/Component/Component.hpp"
#include "../../Model/Component/Physics/Collider.hpp"

namespace systems {
    using namespace components;
    using namespace models;

    class PhysicsManager : public Component {
        private:
            std::vector<Collider*> vecTrackedCollider;
            std::vector<Collider*> vecUntrackedCollider;

        public:
            void perform();
            void trackCollider(Collider* pCollider);
            void untrackCollider(Collider* pCollider);
            void cleanUp();

        private:
            int findTrackedCollider(Collider* pCollider);

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static PhysicsManager* P_SHARED_INSTANCE;

        private:
            PhysicsManager(std::string strName);
            PhysicsManager(const PhysicsManager&);
            PhysicsManager& operator = (const PhysicsManager&);

        public:
            static PhysicsManager* getInstance();
            static void initialize(std::string strName, GameObject* pParent);
            static void destroy();
        /* * * * * * * * * * * * * * * * * * * * */
    };
}

#endif
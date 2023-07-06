#ifndef CONTROLLERS_GAME_OBJECT_MANAGER_HPP
#define CONTROLLERS_GAME_OBJECT_MANAGER_HPP

#include "../../Model/Enum/EnumAssetType.hpp"
#include "../../Model/Enum/EnumComponentType.hpp"

#include "../../Model/GameObject.hpp"

namespace controllers {
    using namespace models;

    class GameObjectManager {
        private:
            std::unordered_map<std::string, GameObject*> mapGameObject;
            std::vector<GameObject*> vecGameObject;
        
        public:
            void processInput(sf::Event eEvent);
            void update(sf::Time tDeltaTime);
            void draw(sf::RenderWindow* pWindow);

            void addObject(GameObject* pGameObject);
            void deleteObject(GameObject* pGameObject);
            void deleteObjectByName(std::string strName);
            
            GameObject* findObjectByName(std::string strName);

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static GameObjectManager* P_SHARED_INSTANCE;

        private:
            GameObjectManager();
            GameObjectManager(const GameObjectManager&);
            GameObjectManager& operator = (const GameObjectManager&);

        public:
            static GameObjectManager* getInstance();
        /* * * * * * * * * * * * * * * * * * * * */
    };
}

#endif
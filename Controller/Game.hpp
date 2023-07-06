#ifndef CONTROLLERS_GAME_H
#define CONTROLLERS_GAME_H

//#include "../Config/Settings.hpp"
/*#include "../Model/Enum/EnumAssetType.hpp"

#include "Singleton/GameObjectManager.hpp"
#include "Singleton/TextureManager.hpp"
#include "System/PhysicsManager.hpp"

#include "../Model/AnimatedTexture.hpp"
#include "../Model/EmptyGameObject.hpp"
#include "../Model/Entity/Alucard.hpp"

#include "../Model/Area/Specific/MarbleGallery.hpp"
*/

namespace controllers {
    

    class Game {
        private:
            sf::RenderWindow rwWindow;
            //EmptyGameObject* pPhysicsManagerHolder;

        public:
            Game();

        public:
            void run();
        
        private:
            void createNullObjectComponents();

            void processEvents();
            void update(sf::Time tDeltaTime);
            void render();
    };
}

#endif
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

#include "../Config/Config.h"

namespace controllers {
    

    class Game {
        private: //TEMP 
            int grid[GRID_SIZE][GRID_SIZE] = 
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,0,0,1,1,1,
            1,1,1,1,1,0,0,0,0,1,1,1,0,1,0,0,1,0,1,1,0,1,
            1,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,1,1,
            1,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,0,0,0,0,1,
            1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,1,
            1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,
            1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,1,1,
            1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
            1,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,
            1,1,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,
            1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,
            1,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,0,1,1,0,1,
            1,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,1,1,
            1,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,
            1,1,0,1,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,
            1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,
            1,1,0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,
            1,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,
            1,0,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};

            std::vector<sf::RectangleShape*> vecTiles;

            sf::RectangleShape* ETankShape;
            int ETankX = 4;
            int ETankY = 20;

            sf::RectangleShape* TankShape;
            int TankX = 6;
            int TankY = 6;

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
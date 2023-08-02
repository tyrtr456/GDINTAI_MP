#ifndef CONTROLLERS_APPLICATION_H
#define CONTROLLERS_APPLICATION_H

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Base.h"
#include "Powerup.h"
#include "Message.h"

#include "vector"

namespace controllers{

    using namespace models;

    class Application {

    private:
        bool gameOver;
        bool gameStarted;
        int frags;

        sf::RenderWindow mWindow;
        std::vector<Base*> vecBases;
        int baseCount;
        std::vector<Base*> enemyBases;
        int enemyBaseCount;
        std::vector<Powerup*> vecPickups;
        Map map;
        Player mPlayer;
        std::vector<Enemy*> packOfEnemies;



        Message msgStart;
        Message msgOver;
        Message msgLost;
        Message msgWon;

        Message msgTimer;
        float nTimer;

    public:
        Application();

    public:
        void process_events();
        void update(const sf::Int64 &time);
        void render();
    };


}


#endif

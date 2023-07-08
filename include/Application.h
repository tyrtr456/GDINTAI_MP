#ifndef CONTROLLERS_APPLICATION_H
#define CONTROLLERS_APPLICATION_H

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Base.h"
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
        Base mBase;
        Map map;
        Player mPlayer;
        std::vector<Enemy*> packOfEnemies;

        Message msgStart;
        Message msgOver;
        Message msgLost;
        Message msgWon;

    public:
        Application();

    public:
        void process_events();
        void update(const sf::Int64 &time);
        void render();
    };


}


#endif

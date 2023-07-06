#ifndef MODELS_PLAYERS_H
#define MODELS_PLAYERS_H

#include "Tank.h"

namespace models {

    class Player : public Tank {

    public:
        Player();

        void move(const sf::Int64 &time);
        void update(const sf::Int64 &time, Map &map, const bool &collision);

    };


}


#endif

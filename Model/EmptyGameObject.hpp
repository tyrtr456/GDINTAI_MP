#ifndef MODELS_EMPTY_GAME_OBJECT_HPP
#define MODELS_EMPTY_GAME_OBJECT_HPP

#include "GameObject.hpp"

namespace models {
    class EmptyGameObject : public GameObject {
        public:
            EmptyGameObject(std::string strName);
            ~EmptyGameObject();
        
        public:
            void initialize();
    };
}

#endif
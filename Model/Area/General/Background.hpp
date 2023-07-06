#ifndef MODELS_BACKGROUND_HPP
#define MODELS_BACKGROUND_HPP

#include "../../../Config/Settings.hpp"

#include "../../GameObject.hpp"
#include "../../AnimatedTexture.hpp"
#include "../../Component/Renderer/Renderer.hpp"

namespace models {
    using namespace components;

    class Background : public GameObject {
        private:
            bool bScaleToWidth;
            
        public:
            Background(std::string strName, AnimatedTexture* pTexture, bool bScaleToWidth = false);
            ~Background();
            
        public:
            void initialize();
    };
}

#endif
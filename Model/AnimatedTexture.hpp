#ifndef MODELS_ANIMATED_TEXTURE_H
#define MODELS_ANIMATED_TEXTURE_H

#include "Enum/EnumAssetType.hpp"

namespace models {
    class AnimatedTexture {
        private:
            std::vector<sf::Texture*> vecFrames;
            std::vector<sf::Texture*> vecNormalFrames;
            std::vector<sf::Texture*> vecFlippedFrames;
            bool bNormal;
            int nCurrentFrame;
        
        public:
            AnimatedTexture(std::vector<sf::Texture*> vecNormalFrames = {}, std::vector<sf::Texture*> vecFlippedFrames = {});

        public:
            void incrementFrame();
            void flip();

        public:
            sf::Texture* getFrame();
            int getFrameSize();
            int getCurrentFrame();
            void setCurrentFrame(int nCurrentFrame);
            bool isNormal();
            void setNormal(bool bNormal);
    };
}

#endif
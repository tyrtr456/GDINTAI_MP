#include "AnimatedTexture.hpp"

using namespace models;

AnimatedTexture::AnimatedTexture(std::vector<sf::Texture*> vecNormalFrames, std::vector<sf::Texture*> vecFlippedFrames) {
    this->vecNormalFrames = vecNormalFrames;
    this->vecFlippedFrames = vecFlippedFrames;
    this->vecFrames = this->vecNormalFrames;
    this->bNormal = true;
    this->nCurrentFrame = 0;
}

void AnimatedTexture::incrementFrame() {
    this->setCurrentFrame(this->nCurrentFrame + 1);
}

void AnimatedTexture::flip() {
    this->bNormal = !this->bNormal;
}

sf::Texture* AnimatedTexture::getFrame() {
    if(this->bNormal)
        return this->vecNormalFrames[this->nCurrentFrame];
    return this->vecFlippedFrames[this->nCurrentFrame];
}

int AnimatedTexture::getFrameSize() {
    if(this->bNormal)
        return this->vecNormalFrames.size();
    return this->vecFlippedFrames.size();
}

int AnimatedTexture::getCurrentFrame() {
    return this->nCurrentFrame;
}

void AnimatedTexture::setCurrentFrame(int nCurrentFrame) {
    if(nCurrentFrame < 0 || nCurrentFrame >= this->getFrameSize()) {
        nCurrentFrame = 0;
        std::cout << "[WARNING] : nCurrentFrame out-of-bounds. Setting back to ZERO." << std::endl;
    }

    this->nCurrentFrame = nCurrentFrame;
}

bool AnimatedTexture::isNormal() {
    return this->bNormal;
}

void AnimatedTexture::setNormal(bool bNormal) {
    this->bNormal = bNormal;
}

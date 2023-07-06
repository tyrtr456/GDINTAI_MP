#include "Area.hpp"

using namespace areas;

Area::Area(std::string strName, AssetType EAssetType) : GameObject(strName, NULL) {
    this->pAlucard = NULL;
    this->pBackground = NULL;
    this->pForeground = NULL;
    this->pScrollerInput = NULL;
    this->pScroller = NULL;

    this->EAssetType = EAssetType;
    this->fSpeed = 300.0f;
}

void Area::initialize(bool bScaleToWidth) {
    this->pScrollerInput = new ScrollerInput(this->strName + " Input");
    this->pScroller = new Scroller(this->strName + " Scroller");
    this->pScroller->setScrollable(this);
    
    this->attachComponent(this->pScrollerInput);
    this->attachComponent(this->pScroller);
    
    this->createBackground(bScaleToWidth);

    this->createBorders();
    this->createPlatforms();
    this->createPlayer();

    this->attachChild(this->pAlucard);
}

void Area::scroll(sf::Time tDeltaTime) {
    float fSpeed = this->fSpeed * tDeltaTime.asSeconds();
    
    if(this->pScrollerInput->isLeft()) {
        float fXLimit = 0.0f;

        if(this->pSprite->getPosition().x < fXLimit)
            this->pSprite->move(fSpeed, 0.0f);
    }

    else if(this->pScrollerInput->isRight()) {  
        float fXLimit = -(this->pBackground->getGlobalBounds().width - SCREEN_WIDTH - 2);
        
        if(this->pSprite->getPosition().x > fXLimit)
            this->pSprite->move(-fSpeed, 0.0f);
    }
}

void Area::createBackground(bool bScaleToWidth) {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(this->EAssetType, 0));
    this->pBackground = new Background(this->strName + " Background", pTexture, bScaleToWidth);
    this->attachChild(this->pBackground);
}

void Area::createPlayer() {
    /* Ignore the wall of Texture loading... */
    AnimatedTexture* pIdleTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ALUCARD, 0, 5),
                                                        TextureManager::getInstance()->getTexture(AssetType::ALUCARD_FLIPPED, 0, 5));
    AnimatedTexture* pWalkTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ALUCARD, 6, 20),
                                                        TextureManager::getInstance()->getTexture(AssetType::ALUCARD_FLIPPED, 6, 20));
    AnimatedTexture* pFallTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ALUCARD, 21, 30),
                                                        TextureManager::getInstance()->getTexture(AssetType::ALUCARD_FLIPPED, 21, 30));
    AnimatedTexture* pLandTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ALUCARD, 31, 35),
                                                        TextureManager::getInstance()->getTexture(AssetType::ALUCARD_FLIPPED, 31, 35));
    AnimatedTexture* pJumpTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ALUCARD_JUMP),
                                                        TextureManager::getInstance()->getTexture(AssetType::ALUCARD_JUMP_FLIPPED));
    
    this->pAlucard = new Alucard("Alucard", pIdleTexture, pWalkTexture, pFallTexture, pLandTexture, pJumpTexture);
}

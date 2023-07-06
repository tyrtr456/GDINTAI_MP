#include "TextureManager.hpp"

using namespace controllers;

void TextureManager::loadAll() {
    sf::Texture* pTexture = NULL;

}

/*

void TextureManager::loadMarbleGalleryFolder() {
    AssetType EType = AssetType::MARBLE_GALLERY;
    std::string strFolder = "Marble Gallery";
    sf::Texture* pTexture = NULL;

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/" + strFolder + "/background.png");
    this->mapTexture[EType].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/" + strFolder + "/foreground.png");
    this->mapTexture[EType].push_back(pTexture);
    
    for(int i = 0; i <= 1; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/" + strFolder + "/platform_" + std::to_string(i) + ".png");
        this->mapTexture[EType].push_back(pTexture);
    }
}

void TextureManager::loadAlucardFolder() {
    AssetType EType = AssetType::ALUCARD;
    sf::Texture* pTexture = NULL;

    std::string strFolder = "Idle";
    for(int i = 0; i <= 5; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Alucard/" + strFolder + "/" + std::to_string(i) + ".png");
        this->mapTexture[EType].push_back(pTexture);
    }
    
    strFolder = "Walk";
    for(int i = 0; i <= 15; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Alucard/" + strFolder + "/" + std::to_string(i) + ".png");
        this->mapTexture[EType].push_back(pTexture);
    }

    strFolder = "Fall";
    for(int i = 0; i <= 13; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Alucard/" + strFolder + "/" + std::to_string(i) + ".png");
        this->mapTexture[EType].push_back(pTexture);
    }

    strFolder = "Jump";
    for(int i = 0; i <= 1; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Alucard/" + strFolder + "/" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::ALUCARD_JUMP].push_back(pTexture);
    }
}

void TextureManager::loadFlippedAlucardFolder() {
    AssetType EType = AssetType::ALUCARD_FLIPPED;
    sf::Texture* pTexture = NULL;

    std::string strFolder = "Idle";
    for(int i = 0; i <= 5; i++) {
        sf::Image* pImage = new sf::Image();
        pImage->loadFromFile("View/Image/Alucard/" + strFolder + "/" + std::to_string(i) + ".png");
        pImage->flipHorizontally();

        pTexture = new sf::Texture();
        pTexture->loadFromImage(*pImage);
        this->mapTexture[EType].push_back(pTexture);
    }
    
    strFolder = "Walk";
    for(int i = 0; i <= 15; i++) {
        sf::Image* pImage = new sf::Image();
        pImage->loadFromFile("View/Image/Alucard/" + strFolder + "/" + std::to_string(i) + ".png");
        pImage->flipHorizontally();

        pTexture = new sf::Texture();
        pTexture->loadFromImage(*pImage);
        this->mapTexture[EType].push_back(pTexture);
    }

    strFolder = "Fall";
    for(int i = 0; i <= 13; i++) {
        sf::Image* pImage = new sf::Image();
        pImage->loadFromFile("View/Image/Alucard/" + strFolder + "/" + std::to_string(i) + ".png");
        pImage->flipHorizontally();

        pTexture = new sf::Texture();
        pTexture->loadFromImage(*pImage);
        this->mapTexture[EType].push_back(pTexture);
    }

    strFolder = "Jump";
    for(int i = 0; i <= 1; i++) {
        sf::Image* pImage = new sf::Image();
        pImage->loadFromFile("View/Image/Alucard/" + strFolder + "/" + std::to_string(i) + ".png");
        pImage->flipHorizontally();

        pTexture = new sf::Texture();
        pTexture->loadFromImage(*pImage);
        this->mapTexture[AssetType::ALUCARD_JUMP_FLIPPED].push_back(pTexture);
    }
}

*/

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EType, int nStart, int nEnd) {
    if(nStart == -1)
        return this->mapTexture[EType];

    else {
        std::vector<sf::Texture*> vecTexture = this->mapTexture[EType];
        std::vector<sf::Texture*>::const_iterator iStart = vecTexture.begin() + nStart;

        if(nEnd == -1)
            nEnd = nStart + 1;

        std::vector<sf::Texture*>::const_iterator iEnd = vecTexture.begin() + nEnd + 1;
        std::vector<sf::Texture*> vecSublist = std::vector(iStart, iEnd);

        return vecSublist;
    }
}

sf::Texture* TextureManager::getTextureAt(AssetType EType, int nFrame) {
    if(!this->mapTexture[EType].empty())
        return this->mapTexture[EType][nFrame];
        
    else {
        std::cout << "[ERROR] : No Texture found." << std::endl;
        return NULL;
    }
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;
TextureManager::TextureManager() {}
TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new TextureManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */

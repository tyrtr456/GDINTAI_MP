#ifndef CONTROLLERS_TEXTURE_MANAGER_HPP
#define CONTROLLERS_TEXTURE_MANAGER_HPP

#include "../../Model/Enum/EnumAssetType.hpp"

namespace controllers {
    class TextureManager {
        private:
            std::unordered_map<AssetType, std::vector<sf::Texture*>> mapTexture;

        public:
            void loadAll();
            std::vector<sf::Texture*> getTexture(AssetType EType, int nStart = -1, int nEnd = -1);
            sf::Texture* getTextureAt(AssetType EType, int nFrame);

        private:
            void loadMarbleGalleryFolder();
            
            void loadAlucardFolder();
            void loadFlippedAlucardFolder();

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static TextureManager* P_SHARED_INSTANCE;

        private:
            TextureManager();
            TextureManager(const TextureManager&);
            TextureManager& operator = (const TextureManager&);

        public:
            static TextureManager* getInstance();
        /* * * * * * * * * * * * * * * * * * * * */
    };
}

#endif
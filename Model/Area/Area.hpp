#ifndef AREAS_AREA_HPP
#define AREAS_AREA_HPP

#include "../Enum/EnumAssetType.hpp"

#include "General/Background.hpp"
#include "General/Foreground.hpp"
#include "General/Floor.hpp"

#include "../Component/Input/ScrollerInput.hpp"
#include "../Component/Script/Scroller.hpp"
#include "../Component/Script/Interface/Scrollable.hpp"

#include "../Entity/Alucard.hpp"
#include "../AnimatedTexture.hpp"
#include "../GameObject.hpp"

namespace areas {
    using namespace components;
    using namespace controllers;
    using namespace models;
    using namespace interfaces;

    class Area : public GameObject, public Scrollable {
        protected:
            Alucard* pAlucard;
            Background* pBackground;
            Foreground* pForeground;
            ScrollerInput* pScrollerInput;
            Scroller* pScroller;

            AssetType EAssetType;
            float fSpeed;

        public:
            Area(std::string strName, AssetType EAssetType);
            
        public:
            virtual void initialize(bool bScaleToWidth = false);
            void scroll(sf::Time tDeltaTime);

        protected:
            void createBackground(bool bScaleToWidth);
            void createPlayer();
            virtual void createBorders() = 0;
            virtual void createPlatforms() = 0;
    };
}

#endif
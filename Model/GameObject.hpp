#ifndef MODELS_GAME_OBJECT_HPP
#define MODELS_GAME_OBJECT_HPP

// #include "Enum/EnumDrawOrder.hpp"

#include "Component/Component.hpp"
#include "Component/Input/GeneralInput.hpp"
#include "Component/Script/Interface/Animatable.hpp"

#include "AnimatedTexture.hpp"

namespace models {
    using namespace components;
    using namespace interfaces;
    
    class GameObject : public Animatable {
        protected:
            bool bEnabled;
            std::string strName;

            sf::Sprite* pSprite;
            AnimatedTexture* pTexture;

            GameObject* pParent;
            std::vector<GameObject*> vecChildren;
            std::vector<Component*> vecComponent;

        public:
            GameObject(std::string strName, AnimatedTexture* pTexture = NULL);
            virtual ~GameObject() = default;

        public:
            virtual void initialize() = 0;
            virtual void processInput(sf::Event eEvent);
            virtual void update(sf::Time tDeltaTime);
            virtual void draw(sf::RenderWindow* pWindow, sf::RenderStates CRenderStates);
            virtual void drawLater(sf::RenderWindow* pWindow, sf::RenderStates CRenderStates);

        public:
            void attachChild(GameObject* pChild);
            void detachChild(GameObject* pChild);

            void attachComponent(Component* pComponent);
            void detachComponent(Component* pComponent);
            Component* findComponentByName(std::string strName);
            std::vector<Component*> getComponents(ComponentType EType);
            std::vector<Component*> getComponentsRecursively(ComponentType EType, bool bInclusive = true);

            void centerSpriteOrigin();
            void move(float fX, float fY);

        public:
            virtual sf::FloatRect getGlobalBounds();
            virtual sf::FloatRect getLocalBounds();
            virtual sf::Vector2f getPosition();
            virtual void setPosition(float fX, float fY);

        public:
            bool isEnabled();
            void setEnabled(bool bEnabled);
            std::string getName();
            sf::Sprite* getSprite();
            AnimatedTexture* getTexture();
            GameObject* getParent();
            void setParent(GameObject* pParent);
            void setFrame(int nFrame);
            int getFrameSize();
            int getCurrentFrame();
            float getHalfWidth();
            float getHalfHeight();
    };
}

#endif
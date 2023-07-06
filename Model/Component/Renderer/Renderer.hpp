#ifndef COMPONENTS_RENDERER_HPP
#define COMPONENTS_RENDERER_HPP

#include "../../Enum/EnumComponentType.hpp"
#include "../../Enum/EnumDrawOrder.hpp"

#include "../Component.hpp"

namespace components {
    class Renderer : public Component {
        private:
            sf::RenderWindow* pWindow;
            sf::Drawable* pDrawable;
            sf::RenderStates CRenderStates;
            DrawOrder EDrawOrder;

        public:
            Renderer(std::string strName, DrawOrder EDrawOrder = DrawOrder::NORMAL);

        public:
            void perform();
            // void flip();
            void assignTargetWindow(sf::RenderWindow* pWindow);
            void assignDrawable(sf::Drawable* pDrawable);
            void scaleWidth(int nResize);
            void scaleHeight(int nResize);

        private:
            float scale(int nOriginal, int nResize);

        public:
            void setRenderStates(sf::RenderStates CRenderStates);
            DrawOrder getDrawOrder();
    };
}

#endif
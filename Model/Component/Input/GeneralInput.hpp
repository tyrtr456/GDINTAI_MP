#ifndef COMPONENTS_GENERAL_INPUT_HPP
#define COMPONENTS_GENERAL_INPUT_HPP

#include "../../Enum/EnumComponentType.hpp"

#include "../Component.hpp"

namespace components {
    class GeneralInput : public Component {
        protected:
            sf::Event eEvent;

        public:
            GeneralInput(std::string strName);

        public:
            virtual void perform() = 0;

        public:
            void assignEvent(sf::Event eEvent);
    };
}

#endif
#include "GeneralInput.hpp"

using namespace components;

GeneralInput::GeneralInput(std::string strName) : Component(strName, ComponentType::INPUT) {}

void GeneralInput::assignEvent(sf::Event eEvent) {
    this->eEvent = eEvent;
}

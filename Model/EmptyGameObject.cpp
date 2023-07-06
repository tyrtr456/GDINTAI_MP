#include "EmptyGameObject.hpp"

using namespace models;

EmptyGameObject::EmptyGameObject(std::string strName) : GameObject(strName) {}

EmptyGameObject::~EmptyGameObject() {}

void EmptyGameObject::initialize() {}

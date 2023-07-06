#ifndef CONFIGS_SETTINGS_HPP
#define CONFIGS_SETTINGS_HPP

#include "string"

/* [NOTE] : Toggle the flag to view the Floor colliders. */
const bool COLLIDER_VISIBILITY = true;

/* * * * * * * * * * * * * * * * * * * * * 
 *     DO NOT ALTER THE VALUES BELOW     * 
 * * * * * * * * * * * * * * * * * * * * */
const int SCREEN_WIDTH  = 853;
const int SCREEN_HEIGHT = 720;
const float FRAME_RATE_LIMIT = 60.0f;

const float ALUCARD_JUMP_VELOCITY = 2.0f;
const float ALUCARD_JUMP_SPEED = 100.0f;

const std::string TAG_FLOOR = " Floor";
const std::string TAG_BLOCK = " Block";
const std::string TAG_LEFT_BOUNDS = " Left Bounds";
const std::string TAG_RIGHT_BOUNDS = " Right Bounds";
/* * * * * * * * * * * * * * * * * * * * */

#endif
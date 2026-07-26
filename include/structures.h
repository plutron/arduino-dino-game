#pragma once
#include <enum.h>
struct Player
{
    PlayerStatus status;
    int x;
    int y;
};



struct Joystick
{
    uint8_t pin;
    AxisDirection current;
    AxisDirection past;
    JoystickAxis axis;
};



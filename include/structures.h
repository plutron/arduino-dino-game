#pragma once
#include <Arduino.h>

struct Position
{
    int x;
    int y;
};

struct Button
{
    byte position;
    byte current;
    byte past;
};



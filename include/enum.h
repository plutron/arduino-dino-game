#pragma once

enum Space{
    Space_empty,
    Space_tree

};

enum Direction{
    Direction_top,
    Direction_right,
    Direction_down,
    Direction_left,
    Direction_none
};

enum Speed{
    Slow,
    Normal,
    Fast

};

enum JoystickAxis{
    X,
    Y
};

enum AxisDirection {
    Axis_negative = -1,
    Axis_neutral = 0,
    Axis_positive = 1
};


enum  PlayerStatus
{
   walking,
   standing,
   lose
};
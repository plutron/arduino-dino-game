#pragma once
#include <Arduino.h>
//------------< Names >-----------
#define GAMENAME "LOST RUNNER"

//------------< keys >-----------
#define LEFT_BUTTON 8
#define UP_BUTTON 9
#define RIGHT_BUTTON 10
#define DOWN_BUTTON 11

//------------< LCD >-----------
#define RS 7
#define E 6
#define D4 5
#define D5 4
#define D6 3
#define D7 2
constexpr int LCD_ROW = 2;
constexpr int LCD_COLUMN = 16;

//------------< Game Speed >----------
constexpr int FAST = 500;
constexpr int MID =  750;
constexpr int SLOW = 1000;

//------------< Game Board Size >----------
constexpr int GAME_BOARD_ROW = 2;
constexpr int GAME_BOARD_COLUMN = 12;

//------------< Characters >----------
#define HEART 1
#define STAND 2
#define WALK 3
#define VARIABLE_SPACE 7

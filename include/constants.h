#pragma once
#include <Arduino.h>
//------------< Names >-----------
const String GAMENAME  = "MINI DINO";

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
const int GAME_BOARD_ROW = 2;
const int GAME_BOARD_COLUMN = 12;

//------------< Characters >----------
#define HEART 1
#define STAND 2
#define WALK 3
#define TREE 5
#define VARIABLE_SPACE 7

//------------< Joy Stick >----------
#define JOY_STICK_X A0
#define JOY_STICK_Y A1
#define JOY_STICK_DEAD_ZONE 200
#define JOY_STICK_CENTER 512

//------------< Game Info >----------
constexpr int TREE_RATE = 2;
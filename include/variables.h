#pragma once
#include <LiquidCrystal.h>
#include <enum.h>
#include <constants.h>
#include <structures.h>

extern LiquidCrystal lcd;
extern Space game_board[GAME_BOARD_ROW][GAME_BOARD_COLUMN] ;
extern int score ,top_score;
extern Joystick joystickX,joystickY;
extern Speed game_speed;
extern Player player;

#pragma once
#include <LiquidCrystal.h>
#include <enum.h>
#include <constants.h>
#include <structures.h>

extern LiquidCrystal lcd;
extern Space game_board[GAME_BOARD_ROW][GAME_BOARD_COLUMN] ;
extern int score ,top_score,game_speed ;
extern Button left_button,up_button,right_button,down_button;

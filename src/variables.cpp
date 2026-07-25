#include <LiquidCrystal.h>
#include <enum.h>
#include <constants.h>
#include <structures.h>
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
int top_score = 0, score = 0, game_speed;
Space game_board[GAME_BOARD_ROW][GAME_BOARD_COLUMN] ;

Button left_button,up_button,right_button,down_button;

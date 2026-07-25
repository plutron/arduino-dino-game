#include <LiquidCrystal.h>
#include <enum.h>
#include <constants.h>
#include <structures.h>


LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
int top_score = 0, score = 0;
Space game_board[GAME_BOARD_ROW][GAME_BOARD_COLUMN] ;
Joystick joystickX,joystickY;
Speed game_speed;
Player player;
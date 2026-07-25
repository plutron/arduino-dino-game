#include <Arduino.h>
#include <variables.h>
#include <structures.h>
#include <functions.h>
#include <enum.h>
#include <constants.h>
#include <characters.h>



void setup(){
  lcd.begin(LCD_COLUMN,LCD_ROW);

  for (int i = 8 ; i < 12; i++)  pinMode(i,INPUT_PULLUP);

  for (int i  = 0 ; i< GAME_BOARD_ROW ; i++)
    for (int j = 0 ; j < GAME_BOARD_COLUMN ; j++) 
      game_board[i][j] = Space_empty;
  
  set_button(&right_button,RIGHT_BUTTON);
  set_button(&left_button,LEFT_BUTTON);
  set_button(&up_button,UP_BUTTON);
  set_button(&down_button,DOWN_BUTTON);

  lcd.createChar(HEART,heart);
  lcd.createChar(STAND,stand);
  lcd.clear();
  
  //print_intro();

  
}

void loop(){
  //game_speed = get_game_speed();
}
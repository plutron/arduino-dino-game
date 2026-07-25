#include <Arduino.h>
#include <variables.h>
#include <structures.h>
#include <functions.h>
#include <enum.h>
#include <constants.h>
#include <characters.h>

int ab = 0;
Direction a = Direction_down;

void setup(){
  Serial.begin(9600);
  lcd.begin(LCD_COLUMN,LCD_ROW);
  
  set_joystick(JOY_STICK_X,X,&joystickX);
  set_joystick(JOY_STICK_Y,Y,&joystickY);
  pinMode(joystickX.pin,INPUT);
  pinMode(joystickY.pin,INPUT);


  lcd.createChar(HEART,heart);
  lcd.createChar(STAND,stand);
  lcd.createChar(TREE,tree);
  lcd.clear();
  
  //print_intro();

  
}

void loop(){
  game_loop();

}



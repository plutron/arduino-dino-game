#include <functions.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <constants.h>
#include <variables.h>
#include <characters.h>

int get_game_speed(){
    lcd.createChar(VARIABLE_SPACE,full);
    lcd.clear();
    lcd.print("SPEED    < OOO >");
    return 0;

}


void print_intro(){
    
    for(char word : GAMENAME){
        lcd.print(word); 
        delay(200);
        }
        delay(500);
    lcd.setCursor(0,0);
    for(char word:GAMENAME){
        lcd.print(" ");
        delay(200);
    }
}


void set_button(Button *button,int pin){
    button->position = pin;
    button->current = HIGH;
    button->past = HIGH;

};
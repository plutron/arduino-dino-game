#pragma once
#include <LiquidCrystal.h>
#include <structures.h>

int get_game_speed();
void print_intro();
void slide_show(const String& text, LiquidCrystal& lcd);
void set_button(Button *button,int pin);
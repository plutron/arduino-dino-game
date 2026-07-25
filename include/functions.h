#pragma once
#include <LiquidCrystal.h>
#include <structures.h>
#include <enum.h>
#include <constants.h>

Speed get_game_speed();
void print_intro();
void set_joystick(uint8_t pin,JoystickAxis axis, Joystick *joystick);
AxisDirection get_joystick_axis_direction(const Joystick* joystick);
Direction get_joystick_direction(Joystick *jsX,Joystick *jsY);
int game_loop();
void count_down(int t);
void set_player(Player *p);
void set_new_game();
void clear_game_board(Space board[][GAME_BOARD_COLUMN]);
void update_board(int shift);
void print_board(int shift);
void print_score(int s);
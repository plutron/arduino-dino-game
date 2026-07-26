#include <functions.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <constants.h>
#include <variables.h>
#include <characters.h>
#include <structures.h>
#include <enum.h>

Speed get_game_speed(){
    lcd.createChar(VARIABLE_SPACE,full);
    lcd.clear();
    lcd.print("SPEED    < ");
    lcd.write(VARIABLE_SPACE);
    lcd.print("OO >");
    lcd.setCursor(0,1);
    lcd.print("START : UP");
    Direction joystic_directoin = Direction_none;
    int c = 0;
    while (true){
        while((joystic_directoin = get_joystick_direction(&joystickX,&joystickY)) == Direction_none);
        if (joystic_directoin == Direction_right&&c<2){
            lcd.setCursor(12+c,0);
            lcd.write(VARIABLE_SPACE);
            c++;
        }
        else if(joystic_directoin == Direction_left&&c>0){
            lcd.setCursor(11+c,0);
            lcd.print("O");
            c--;
        }
        else if(joystic_directoin == Direction_top){
            if(c == 0) return Slow;
            if(c == 1) return Normal;
            return Fast;
        }
    }
}

void print_intro(){
    
    for(char word : GAMENAME){
        lcd.print(word); 
        delay(200);
        }
        delay(500);
    lcd.setCursor(0,0);
    for(unsigned int i = 0 ; i < GAMENAME.length(); i++){
        lcd.print(" ");
        delay(200);
    }
}

void set_joystick(uint8_t pin,JoystickAxis axis, Joystick *joystick){
    joystick->pin = pin;
    joystick->current = Axis_neutral;
    joystick->past = Axis_neutral;
    joystick->axis = axis;
}

AxisDirection get_joystick_axis_direction(const Joystick * joystick){
    int value = analogRead(joystick->pin);

    if (value > JOY_STICK_CENTER + JOY_STICK_DEAD_ZONE)
        return Axis_positive;

    if (value < JOY_STICK_CENTER - JOY_STICK_DEAD_ZONE)
        return Axis_negative;

    return Axis_neutral;
}

Direction get_joystick_direction(Joystick *jsX,Joystick *jsY){
    int x_value = analogRead(jsX->pin);
    int y_value = analogRead(jsY->pin);
    int x_delta = abs(x_value - JOY_STICK_CENTER);
    int y_delta = abs(y_value - JOY_STICK_CENTER);

    if(x_delta >= y_delta){
        jsX->past = jsX->current;
        jsX->current = get_joystick_axis_direction(jsX);
        if(jsX->past == Axis_neutral && jsX->current == Axis_positive)
            return Direction_left;
        else if (jsX->past == Axis_neutral && jsX->current == Axis_negative)
            return Direction_right;
        return Direction_none;
    }

    jsY->past = jsY->current;
    jsY->current = get_joystick_axis_direction(jsY);
    if(jsY->past == Axis_neutral && jsY->current == Axis_positive)
        return Direction_top;
    else if (jsY->past == Axis_neutral && jsY->current == Axis_negative)
        return Direction_down;
    return Direction_none;
    

}

void print_board(int shift){
    for(int i = 0; i < GAME_BOARD_ROW; i++){
        lcd.setCursor(0,i);
        for(int j = shift; j < GAME_BOARD_COLUMN+shift;j++){
            if (game_board[i][j%GAME_BOARD_COLUMN] == Space_tree) lcd.write(TREE);
            else lcd.print(' ');
        }
            
    }

}

void update_board(int shift) {
    bool createTree = random(TREE_RATE + 1) < TREE_RATE;
    int location = (shift - 1 + GAME_BOARD_COLUMN) % GAME_BOARD_COLUMN;

    game_board[0][location] = Space_empty;
    game_board[1][location] = Space_empty;

    if (!createTree)
        return;

    int previousLocation = (location - 1 + GAME_BOARD_COLUMN) % GAME_BOARD_COLUMN;

    if (game_board[0][previousLocation] == Space_tree) {
        game_board[0][location] = Space_tree;
    }

    else if (game_board[1][previousLocation] == Space_tree) {
        game_board[1][location] = Space_tree;
    }

    else {
        game_board[random(GAME_BOARD_ROW)][location] = Space_tree;
    }
}

void print_score(int s){
    lcd.setCursor(GAME_BOARD_COLUMN,0);
    lcd.print(s);
}

PlayerStatus check_player(Player &p,int shift){
    if (game_board[p.y][(p.x+shift)%GAME_BOARD_COLUMN] == Space_tree) return lose;
    return standing;
}

void print_player(Player &p){
    lcd.setCursor(p.x,p.y);

    if (p.status ==lose){
        lcd.createChar(VARIABLE_SPACE,dead); 
            lcd.setCursor(p.x,p.y);
        lcd.write(VARIABLE_SPACE);
        return ;
    }
    if(p.status == walking){
        lcd.write(WALK);
        return ;
    }
    lcd.write(STAND);
}

bool update_player_location(Player &p) {
    Direction move = get_joystick_direction(&joystickX, &joystickY);

    if (move == Direction_none)
        return false;

    if (move == Direction_right && p.x < GAME_BOARD_COLUMN - 1)
        p.x++;

    else if (move == Direction_left && p.x > 0)
        p.x--;

    else if (move == Direction_down && p.y < GAME_BOARD_ROW - 1)
        p.y++;

    else if (move == Direction_top && p.y > 0)
        p.y--;

    return true;
}

int game_loop(){
    unsigned long t = millis();
    int shift = 0;
    int game_delay;
    int past_x = player.x;
    int past_y = player.y;

    if (game_speed == Slow) game_delay = 1000;
    else if (game_speed == Normal) game_delay = 850;
    else game_delay = 700;
    print_player(player);
    while(true){

        if(millis() - t >= game_delay){
            shift++;
            t = millis();
            lcd.setCursor(0,0);
            update_board(shift);
            print_board(shift);
            print_score(shift);
            player.x = player.x >0 ? player.x -1 : 0;
            past_x = player.x;
            player.status = check_player(player,shift);
            print_player(player);
            if(player.status == lose){
                
                return shift;
            }
        }
        
        else if (update_player_location(player)){
            lcd.setCursor(past_x, past_y);
            lcd.write(' ');
            past_x = player.x;
            past_y = player.y;
            player.status = check_player(player,shift);
            print_player(player);
            if(player.status == lose){
                return shift;
                
            }
        }

    }

}


void count_down(int t){
    for (int i = t; i > 0 ; i--){
        lcd.print(i);
        delay(333);
        lcd.print(",");
        delay(333);
        lcd.print(". ");
        delay(333);
    }
}

void set_player(Player *p){
    p->status = standing;
    p->x = 0;
    p->y = 0;

}

void set_new_game(){
    clear_game_board(game_board);
    set_player(&player);
    game_speed = get_game_speed();
    lcd.clear();
}

void score_board(int s,int ts){
    for(int i =0 ; i < LCD_ROW ; i++){
        lcd.setCursor(0,i);
        for(int j = 0 ; j < LCD_COLUMN ; j++){
            lcd.print(' ');
            delay(100);}
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SCORE ");
    lcd.print(s);
    lcd.setCursor(0,1);
    lcd.print("TOP SCORE ") ;
    lcd.print(ts);
}


void clear_game_board(Space board[][GAME_BOARD_COLUMN]) {
    for (int i = 0; i < GAME_BOARD_ROW; i++)
        for (int j = 0; j < GAME_BOARD_COLUMN; j++)
            board[i][j] = Space_empty;
}
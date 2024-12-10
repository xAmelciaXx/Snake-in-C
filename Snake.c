#include <stdio.h>
#include <stdint.h>

/* Private Includes */

#include "curses.h"

/* End Private Includes */
/*===============================================*/
/* Private Typedef */

typedef enum {
UP,
RIGHT,
DOWN,
LEFT
} dir_t;

/* End Private Typedef */
/*===============================================*/
/* Private Variables */

uint8_t board_size[2] = {10,10};
uint16_t time_interval = 500;
uint8_t snake_body_x[100] = {4,3};
uint8_t snake_body_y[100] = {4,4};
uint8_t snake_lenght = 2;
uint8_t points = 0;
char row[10] = {};
dir_t move_dir = RIGHT;
dir_t last_dir = RIGHT;
dir_t last_counter_dir = LEFT;

/* End Private Variables */
/*===============================================*/
/* Private Functions */

void renderMap(char head, char tail, char bckgrd, char apple) {     // Renderowanie mapy w terminalu
    for (int y = 0; y < board_size[0]; y++) {
        for (int x = 0; x < board_size[1]; x++) {
            for (int i = 0; i < 100; i++) {
                if (( snake_body_x[i] == x ) && ( snake_body_y[i] == y ) && ( i == 0 )) {

                    if ( i == 0 ) {
                        mvprintw(x,y,head);
                    } else {
                        mvprintw(x,y,tail);
                    }
                    
                } else {
                    mvprintw(x,y,bckgrd);
                }
            }
        }
    }
}


bool checkDead() {      // Return false jezeli zywy, true jezeli martwy
    for(int i = 0; i < 100; i++) {
        if ((snake_body_x[i] > 10) || (snake_body_y > 10) || (snake_body_x < 10) || (snake_body_y < 10) || (( i != 0 ) && ( snake_body_x[0] == snake_body_x[i] ) && ( snake_body_y[0] == snake_body_y[i] ))) {
            return true;
        }
    }
    return false;
}


void calcCounter(dir_t dir, dir_t* cntDir) {       // Zapisuje w zmiennej podanej w argumentach przeciwny kierunek do kierunku podanego jako argument
    *cntDir = (dir+2)%4;
}


bool moveBody() {       // Porusza Snake'a do przodu w wybranym przez gracza kierunku
    if ( move_dir == last_counter_dir ) {       // Sprawdzenie czy snake moze poruszyc sie w wybranym kierunku, ewentualna korekcja
        move_dir = last_dir;
    }

    for(int i = 1; i < 100; i++) {              // Poruszenie ogonu snake'a w wbranym kierunku
        if ( snake_body_x[i] == NULL ) {
            break;
        } else {
            snake_body_x[i] = snake_body_x[i-1];
            snake_body_y[i] = snake_body_y[i-1];
        }
    }

    if ( move_dir == UP ) {                     // Przesuniecie glowy snake'a
        snake_body_y[0] = snake_body_y[0] + 1;
    } else if ( move_dir == DOWN ) {
        snake_body_y[0] = snake_body_y[0] - 1;
    } else if ( move_dir == RIGHT ) {
        snake_body_x[0] = snake_body_y[0] + 1;
    } else if ( move_dir == LEFT ) {
        snake_body_x[0] = snake_body_x[0] - 1;
    }
}

/* End Private Functions */
/*===============================================*/
/* Main Game Loop */

int Update() {
    while(1) {

    }
    return 0;
}

/* End Main Game Loop */
/*===============================================*/
/* Program Entry Point */

int main() {
    printf("Welcome to the Snake Game\n");
    printf("Press [ENTER] to start the game...\n");
    scanf("Press [ENTER] to start the game...\n", NULL);
    mainLoop();
    return 0;
}

/* End Program Entry Point */

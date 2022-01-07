#include "Human.h"
#include "Animal.h"
#include <ncurses.h>

#define LENGTH 40
#define WIDTH 20


Human::Human(World& world, WINDOW* win): win(win), on(false), ability_turns(0), Animal(world, 5, 4, char(72),0) {
    GenerateInitialPosition(world);
    this->name = "human";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}

char Human::Draw(){
    return this->sign;
}

void Human::NewSameTypeOrganism(int x, int y) {
}


void Human::Action() {
    int step=1;

    int cmd=0;
    noecho();
    flushinp();

    if(ability_turns==0 && !on){
        move(WIDTH+6,0);
        printw("Press '2' to turn on human special ability - antelope's speed");
        printw("\n");

        cmd = getch();
        if(cmd==50){
            step = 2;
            on = true;
            ability_turns++;
            flushinp();
        }
    }

    if(!on && ability_turns>0){
        ability_turns--;
    }

    if(ability_turns>=0 && ability_turns <4 && on){
        ability_turns++;
        step = 2;
    } else if(ability_turns >3 && ability_turns <6 && on){
        int possibility = rand()%100 +1;
        if(possibility <= 50){
            step=2;
        }else{
            step=1;
        }
        if(ability_turns==5){
            on = false;
        } else {
            ability_turns++;
        }
    }

    if (cmd == 27){

    }else{
      cmd = wgetch(win);
      if (cmd != 27){
          flushinp();
          return;
      }
    }
    int c = wgetch(win);

    int key = wgetch(win);
    switch (key) {
        case 'A':
            if ((this->position.y - step) >= 0) {
                this->position.y -= step;
            }
            break;
        case 'B':
            if ((this->position.y + step) < WIDTH) {
                this->position.y += step;
            }
            break;
        case 'D':
            if ((this->position.x - step) >= 0) {
                this->position.x -= step;
            }
            break;
        case 'C':
            if ((this->position.x + step) < LENGTH) {
                this->position.x += step;
            }
            break;
        default:
            break;
    }

}


Human::~Human(){
}
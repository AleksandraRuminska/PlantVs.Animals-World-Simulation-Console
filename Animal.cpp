#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include "World.h"
#include "Animal.h"
using namespace std;
#define LENGTH 40
#define WIDTH 20

Animal::Animal(World &world, int strength, int initiative, char sign, int reflect) : world(world), Organism(strength, 0, initiative, sign, reflect)  {
}

void Animal::Move(){
    int position_before_x = this->position.x;
    int position_before_y = this->position.y;

    world.board[position_before_y][position_before_x] = NULL;
    Action();
    if (CheckIfFree(this->world, this->position.x, this->position.y)){
        world.board[this->position.y][this->position.x] = this;
    } else {
        switch(Collision(position_before_x, position_before_y)){
            case 1:
                this->position.x = position_before_x;
                this->position.y = position_before_y;
                world.board[this->position.y][this->position.x] = this;
                break;
            case 2:
                this->SetRemoved();
                break;
            case 3:
                if(world.board[this->position.y][this->position.x] != NULL) {
                    world.board[this->position.y][this->position.x]->SetRemoved();
                    world.board[this->position.y][this->position.x] = NULL;
                }
                world.board[this->position.y][this->position.x] = this;
                break;
            default:
                break;
        }
    }

}

void Animal::Action(){
    int number = rand() % 4;
    switch(number){
        case 0:
            if((this->position.x + 1) <LENGTH) {
                this->position.x += 1;
            }
            break;
        case 1:
            if((this->position.x - 1) >= 0) {
                this->position.x -= 1;
            }
            break;
        case 2:
            if((this->position.y + 1) <WIDTH) {
                this->position.y += 1;
            }
            break;
        case 3:
            if((this->position.y - 1) >= 0) {
                this->position.y -= 1;
            }
            break;
        default:
            break;
    }
}

void Animal::GenerateInitialPosition(World &w) {
    srand(time(NULL));
    int num_x = rand() % LENGTH;
    int num_y = rand() % WIDTH;

    while(w.board[num_y][num_x] != NULL) {
        num_x = rand() % LENGTH;
        num_y = rand() % WIDTH;
    }

    this->position.x = num_x;
    this->position.y = num_y;
}

bool Animal::CheckIfFree(World& w, int x, int y){
    return !w.board[y][x];
}

int Animal::FindPlace(int x1, int y1, int step, int make_new){
    if(x1+step < LENGTH) {
        if (CheckIfFree(world, x1+step, y1)) {
            if(make_new == 1) {
                NewSameTypeOrganism(x1 + step, y1);
            } else{
                this->position.x = x1 + step;
                this->position.y = y1;
            }
            return 1;
        }
    }
    if(x1-step >= 0) {
        if (CheckIfFree(world, x1-step, y1)) {
            if(make_new == 1) {
                NewSameTypeOrganism(x1 - step, y1);
            } else {
                this->position.x = x1 - step;
                this->position.y = y1;
            }
            return 1;
        }
    }
    if(y1+step < WIDTH) {
        if (CheckIfFree(world, x1, y1+step)) {
            if(make_new == 1) {
                NewSameTypeOrganism(x1, y1 + step);
            } else {
                this->position.x = x1;
                this->position.y = y1 + step;
            }
            return 1;
        }
    }
    if(y1-step >= 0) {
        if (CheckIfFree(world, x1, y1-step)) {
            if(make_new == 1) {
                NewSameTypeOrganism(x1, y1 - step);
            } else {
                this->position.x = x1;
                this->position.y = y1 - step;
            }
            return 1;
        }
    }
    return 0;
}

int Animal::Collision(int x, int y) {
    if(world.board[this->position.y][this->position.x]->name == this->name){
            if (FindPlace(x, y, 1, 1) == 0) {
                FindPlace(this->position.x, this->position.y, 1, 1);
            }
            printw("\n");
            printw("New: ");
            printw("%s", (this->name).c_str());
            printw(" was born");
            return 1;
    } else if(world.board[this->position.y][this->position.x]->GetReflect() > 0){
        if(world.board[this->position.y][this->position.x]->GetReflect() > this->strength){
            printw("\n");
            printw("turtle reflected: ");
            printw("%s", (this->name).c_str());
            printw("'s attack.");
            return 1;
        } else {
            printw("\n");
            printw("turtle was defeated by: "); printw("%s", (this->name).c_str());
            return 3;
        }
    } else {
        if(world.board[this->position.y][this->position.x]->GetStrength() > this->strength){
            printw("\n");
            printw("%s",  (this->name).c_str());
            printw(" was defeated by: ");
            printw("%s", (world.board[this->position.y][this->position.x]->name).c_str());
            return 2;
        } else if(world.board[this->position.y][this->position.x]->GetStrength() < this->strength){
            printw("\n");
            printw("%s", (world.board[this->position.y][this->position.x]->name).c_str() );
            printw(" was defeated by: ");
            printw("%s", (this->name).c_str());
            if(world.board[this->position.y][this->position.x]->name == "guarana"){
                this->SetStrength(this->strength+3);
            }
            return 3;
        } else {
            printw("\n");
            printw("%s", (world.board[this->position.y][this->position.x]->name).c_str());
            printw(" was defeated by: ");
            printw("%s", (this->name).c_str());
            return 3;
        }
    }
}

void Animal::NewSameTypeOrganism(int x, int y) {
}

Animal::~Animal() {
}
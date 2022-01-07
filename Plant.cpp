#include "Plant.h"
#define LENGTH 40
#define WIDTH 20

Plant::Plant(World &world,int strength, int initiative, char sign, int reflect):world(world), Organism(strength, 0, initiative, sign, reflect){
}

void Plant::Move(){
    Action();
    Collision(this->position.x,this->position.y);
}

void Plant::Action(){
    FindPlace(this->position.x, this->position.y,1,1);
}
int Plant::Collision(int x, int y){
    return 0;
}

void Plant::GenerateInitialPosition(World& w){
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
int Plant::FindPlace(int x1, int y1, int step,int make_new){
    if(x1+step < LENGTH) {
        if (CheckIfFree(world, x1+step, y1)) {
            if(make_new == 1) {
                NewSameTypeOrganism(x1 + step, y1);
                printw("\n");
                printw("New: ");
                printw("%s", (this->name).c_str());
                printw(" was sown");
            }
            return 1;
        }
    }
    if(x1-step >= 0) {
        if (CheckIfFree(world, x1-step, y1)) {
            if(make_new == 1) {
                NewSameTypeOrganism(x1 - step, y1);
                printw("\n");
                printw("New: ");
                printw("%s", (this->name).c_str());
                printw(" was sown");
            }
            return 1;
        }
    }
    if(y1+step < WIDTH) {
        if (CheckIfFree(world, x1, y1+step)) {
            if(make_new == 1) {
                NewSameTypeOrganism(x1, y1 + step);
                printw("\n");
                printw("New: ");
                printw("%s", (this->name).c_str());
                printw(" was sown");
            }
            return 1;
        }
    }
    if(y1-step >= 0) {
        if (CheckIfFree(world, x1, y1-step)) {
            if(make_new == 1) {
                NewSameTypeOrganism(x1, y1 - step);
                printw("\n");
                printw("New: ");
                printw("%s", (this->name).c_str());
                printw(" was sown");
            }
            return 1;
        }
    }
    return 0;
}
bool Plant::CheckIfFree(World& w, int x, int y){
    return !w.board[y][x];
}
Plant::~Plant(){
}
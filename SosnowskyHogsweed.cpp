#include "SosnowskyHogsweed.h"
#define LENGTH 40
#define WIDTH 20

SosnowskyHogsweed::SosnowskyHogsweed(World& world):Plant(world, 10, 0, char(33),0){
    GenerateInitialPosition(world);
    this->name = "hogsweed";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}
SosnowskyHogsweed::SosnowskyHogsweed(World& world, int x, int y):Plant(world, 10, 0, char(33),0){
    this->name = "hogsweed";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}
char SosnowskyHogsweed::Draw(){
    return this->sign;
}
void SosnowskyHogsweed::NewSameTypeOrganism(int x, int y){
    Organism* org = new SosnowskyHogsweed(world, x, y);
}

void SosnowskyHogsweed::Action(){
    if(this->position.x+1 < LENGTH) {
        if (!CheckIfFree(world, this->position.x+1, this->position.y)) {
            if (world.board[this->position.y][this->position.x + 1]->name != "guarana" &&
                world.board[this->position.y][this->position.x + 1]->name != "grass"
                && world.board[this->position.y][this->position.x + 1]->name != "sowthistle" &&
                world.board[this->position.y][this->position.x + 1]->name != "belladona"
                && world.board[this->position.y][this->position.x + 1]->name != "hogsweed") {
                printw("\n");
                printw("hogsweed killed: ");
                printw("%s", (world.board[this->position.y][this->position.x + 1]->name).c_str());
                world.board[this->position.y][this->position.x + 1]->SetRemoved();
                world.board[this->position.y][this->position.x + 1] = NULL;
            }
        }
    }
    if(this->position.x-1 >= 0) {
        if (!CheckIfFree(world, this->position.x-1, this->position.y)) {
            if (world.board[this->position.y][this->position.x - 1]->name != "guarana" &&
                world.board[this->position.y][this->position.x - 1]->name != "grass"
                && world.board[this->position.y][this->position.x - 1]->name != "sowthistle" &&
                world.board[this->position.y][this->position.x - 1]->name != "belladona"
                && world.board[this->position.y][this->position.x - 1]->name != "hogsweed"){

                printw("\n");
                printw("hogsweed killed: ");
                printw("%s", (world.board[this->position.y][this->position.x - 1]->name).c_str());
                world.board[this->position.y][this->position.x - 1]->SetRemoved();
                world.board[this->position.y][this->position.x - 1] = NULL;
             }
        }
    }
    if(this->position.y+1 < WIDTH) {
        if (!CheckIfFree(world, this->position.x, this->position.y+1)) {
            if (world.board[this->position.y+1][this->position.x]->name != "guarana" &&
                world.board[this->position.y+1][this->position.x]->name != "grass"
                && world.board[this->position.y+1][this->position.x]->name != "sowthistle" &&
                world.board[this->position.y+1][this->position.x]->name != "belladona"
                && world.board[this->position.y+1][this->position.x]->name != "hogsweed") {

                printw("\n");
                printw("hogsweed killed: ");
                printw("%s", (world.board[this->position.y + 1][this->position.x]->name).c_str());
                world.board[this->position.y + 1][this->position.x]->SetRemoved();
                world.board[this->position.y + 1][this->position.x] = NULL;
            }
        }
    }
    if(this->position.y-1 >= 0) {
        if (!CheckIfFree(world, this->position.x, this->position.y-1)) {
            if (world.board[this->position.y-1][this->position.x]->name != "guarana" &&
                world.board[this->position.y-1][this->position.x]->name != "grass"
                && world.board[this->position.y-1][this->position.x]->name != "sowthistle" &&
                world.board[this->position.y-1][this->position.x]->name != "belladona"
                && world.board[this->position.y-1][this->position.x]->name != "hogsweed") {

                printw("\n");
                printw("hogsweed killed: ");
                printw("%s", (world.board[this->position.y - 1][this->position.x]->name).c_str());
                world.board[this->position.y - 1][this->position.x]->SetRemoved();
                world.board[this->position.y - 1][this->position.x] = NULL;
            }
        }
    }
}

SosnowskyHogsweed::~SosnowskyHogsweed(){
}
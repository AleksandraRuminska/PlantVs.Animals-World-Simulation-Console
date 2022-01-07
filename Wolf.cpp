#include "Animal.h"
#include "Wolf.h"

Wolf::Wolf(World& world): Animal(world, 9, 5, char(35),0) {
    GenerateInitialPosition(world);
    this->name = "wolf";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}

Wolf::Wolf(World& world, int x, int y): Animal(world, 9, 5, char(35), 0) {
    this->name = "wolf";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}

char Wolf::Draw(){
    return this->sign;
}

void Wolf::NewSameTypeOrganism(int x, int y) {
    Organism* org = new Wolf(world, x, y);
}

Wolf::~Wolf(){
}
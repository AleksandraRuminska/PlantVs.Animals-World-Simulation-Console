#include "Belladona.h"

Belladona::Belladona(World& world):Plant(world, 99, 0, char(126),0){
    GenerateInitialPosition(world);
    this->name = "belladona";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}
Belladona::Belladona(World& world, int x, int y):Plant(world, 99, 0, char(126),0){
    this->name = "belladona";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}
char Belladona::Draw(){
    return this->sign;
}
void Belladona::NewSameTypeOrganism(int x, int y){
    Organism* org = new Belladona(world, x, y);
}


Belladona::~Belladona(){
}
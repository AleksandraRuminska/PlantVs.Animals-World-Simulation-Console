#include "Guarana.h"

Guarana::Guarana(World& world):Plant(world, 0, 0, char(46),0){
    GenerateInitialPosition(world);
    this->name = "guarana";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}
Guarana::Guarana(World& world, int x, int y):Plant(world, 0, 0, char(46),0){
    this->name = "guarana";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}
char Guarana::Draw(){
    return this->sign;
}
void Guarana::NewSameTypeOrganism(int x, int y){
    Organism* org = new Guarana(world, x, y);
}

Guarana::~Guarana(){
}
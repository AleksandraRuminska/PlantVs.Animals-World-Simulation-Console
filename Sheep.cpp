#include "Sheep.h"

Sheep::Sheep(World& world): Animal(world, 4, 4, char(42),0){
    GenerateInitialPosition(world);
    this->name = "sheep";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}
Sheep::Sheep(World& world, int x, int y): Animal(world, 4, 4, char(42),0){
    this->name = "sheep";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}
char Sheep::Draw(){
    return this->sign;
}
void Sheep::NewSameTypeOrganism(int x, int y){
    Organism* org = new Sheep(world, x, y);
}
Sheep::~Sheep(){
}
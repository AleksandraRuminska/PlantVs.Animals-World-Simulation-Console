#include "Grass.h"

Grass::Grass(World& world):Plant(world, 0, 0, char(41),0){
    GenerateInitialPosition(world);
    this->name = "grass";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}
Grass::Grass(World& world, int x, int y):Plant(world, 0, 0, char(41),0){
    this->name = "grass";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}
char Grass::Draw(){
    return this->sign;
}
void Grass::NewSameTypeOrganism(int x, int y){
    Organism* org = new Grass(world, x, y);
}
Grass::~Grass(){
}
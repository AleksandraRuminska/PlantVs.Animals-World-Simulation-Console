#include "SowThistle.h"

SowThistle::SowThistle(World& world):Plant(world, 0, 0, char(37),0){
    GenerateInitialPosition(world);
    this->name = "sowthistle";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}
SowThistle::SowThistle(World& world, int x, int y):Plant(world, 0, 0, char(37),0){
    this->name = "sowthistle";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}
char SowThistle::Draw(){
    return this->sign;
}
void SowThistle::NewSameTypeOrganism(int x, int y){
    Organism* org = new SowThistle(world, x, y);
}

void SowThistle::Move(){
    Action();
    Action();
    Action();
    Collision(this->position.x,this->position.y);
}

SowThistle::~SowThistle(){
}
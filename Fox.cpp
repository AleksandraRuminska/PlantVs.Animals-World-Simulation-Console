#include "Fox.h"

Fox::Fox(World& world): Animal(world, 3, 7, char(94),0){
    GenerateInitialPosition(world);
    this->name = "fox";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}
Fox::Fox(World& world, int x, int y): Animal(world, 3, 7, char(94),0){
    this->name = "fox";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}
char Fox::Draw(){
    return this->sign;
}
void Fox::NewSameTypeOrganism(int x, int y){
    Organism* org = new Fox(world, x, y);
}
void Fox::Move(){
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
                this->position.x = position_before_x;
                this->position.y = position_before_y;
                world.board[this->position.y][this->position.x] = this;
                break;
            case 3:
                world.board[this->position.y][this->position.x]->SetRemoved();
                world.board[this->position.y][this->position.x] = NULL;
                world.board[this->position.y][this->position.x] = this;
                break;
            default:
                break;
        }
    }

}

Fox::~Fox(){
}
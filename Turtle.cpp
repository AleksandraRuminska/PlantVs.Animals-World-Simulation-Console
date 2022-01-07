#include "Turtle.h"
#define LENGTH 40
#define WIDTH 20

Turtle::Turtle(World& world): Animal(world, 2, 1, char(36),5){
    GenerateInitialPosition(world);
    this->name = "turtle";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}
Turtle::Turtle(World& world, int x, int y): Animal(world, 2, 1, char(36),5){
    this->name = "turtle";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}
char Turtle::Draw(){
    return this->sign;
}
void Turtle::NewSameTypeOrganism(int x, int y){
    Organism* org = new Turtle(world, x, y);
}

void Turtle::Action() {
    int probability_moving = rand() % 100 + 1;

    if(probability_moving > 75) {
        int number = rand() % 4;
        switch (number) {
            case 0:
                if ((this->position.x + 1) < LENGTH) {
                    this->position.x += 1;
                }
                break;
            case 1:
                if ((this->position.x - 1) >= 0) {
                    this->position.x -= 1;
                }
                break;
            case 2:
                if ((this->position.y + 1) < WIDTH) {
                    this->position.y += 1;
                }
                break;
            case 3:
                if ((this->position.y - 1) >= 0) {
                    this->position.y -= 1;
                }
                break;
            default:
                break;
        }
    }
}

Turtle::~Turtle() {
}
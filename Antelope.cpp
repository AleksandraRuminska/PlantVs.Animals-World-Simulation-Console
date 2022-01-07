#include "Antelope.h"
#define LENGTH 40
#define WIDTH 20

Antelope::Antelope(World& world): Animal(world, 4, 4, char(34),0){
    GenerateInitialPosition(world);
    this->name = "antelope";
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,1);
}
Antelope::Antelope(World& world, int x, int y): Animal(world, 4, 4, char(34),0){
    this->name = "antelope";
    this->position.x=x;
    this->position.y=y;
    world.board[this->position.y][this->position.x] = this;
    world.AddOrganism(this,0);
}
char Antelope::Draw(){
    return this->sign;
}
void Antelope::NewSameTypeOrganism(int x, int y){
    Organism* org = new Antelope(world, x, y);
}

void Antelope::Action(){
    int number = rand() % 4;

    switch(number){
        case 0:
            if((this->position.x + 2) <LENGTH) {
                this->position.x += 2;
            }
            break;
        case 1:
            if((this->position.x - 2) >= 0) {
                this->position.x -= 2;
            }
            break;
        case 2:
            if((this->position.y + 2) <WIDTH) {
                this->position.y += 2;
            }
            break;
        case 3:
            if((this->position.y - 2) >= 0) {
                this->position.y -= 2;
            }
            break;
        default:
            break;
    }
}
int Antelope::Collision(int x, int y){
    int chance_to_escape = rand() % 50 + 1;

    if(chance_to_escape <= 50){
        FindPlace(x, y,2,0);
        printw("\n");
        printw("%s", (this->name).c_str());
        printw(" escaped from attack");
        return 3;
    } else {
        if (world.board[this->position.y][this->position.x]->name == this->name) {
                if (FindPlace(x, y, 1, 1) == 0) {
                    FindPlace(this->position.x, this->position.y, 1, 1);
                }
                printw("\n");
                printw("New: ");
                printw("%s", (this->name).c_str());
                printw(" was born");
            return 1;
        } else if (world.board[this->position.y][this->position.x]->GetReflect() > 0) {
            if (world.board[this->position.y][this->position.x]->GetReflect() > this->strength) {
                printw("\n");
                printw("turtle reflected: ");
                printw("%s", (this->name).c_str());
                printw("'s attack.");
                return 1;
            } else {
                printw("\n");
                printw("turtle was defeated by: "); printw("%s", (this->name).c_str());
                return 3;
            }
        } else {
            if (world.board[this->position.y][this->position.x]->GetStrength() > this->strength) {
                printw("\n");
                printw("%s",  (this->name).c_str());
                printw(" was defeated by: ");
                printw("%s", (world.board[this->position.y][this->position.x]->name).c_str());
                return 2;
            } else if (world.board[this->position.y][this->position.x]->GetStrength() < this->strength) {
                printw("\n");
                printw("%s", (world.board[this->position.y][this->position.x]->name).c_str() );
                printw(" was defeated by: ");
                printw("%s", (this->name).c_str());
                if(world.board[this->position.y][this->position.x]->name == "guarana"){
                    this->SetStrength(this->strength+3);
                }
                return 3;
            } else {
                printw("\n");
                printw("%s", (world.board[this->position.y][this->position.x]->name).c_str());
                printw(" was defeated by: ");
                printw("%s", (this->name).c_str());
                return 3;
            }
        }
    }
}


Antelope::~Antelope(){
}
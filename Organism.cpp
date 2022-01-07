#include<iostream>
#include "Organism.h"
using namespace std;

Organism::Organism(int strength, int removed, int initiative, char sign, int reflect):strength(strength), removed(removed), initiative(initiative), sign(sign), reflect(reflect){
}

int Organism::GetStrength() const {
    return this->strength;
}

int Organism::GetInitiative() const{
    return this->initiative;
}

int Organism::GetReflect()const {
    return this->reflect;
}

char Organism::GetSign() const{
    return this->sign;
}

int Organism::GetPositionX() const{
    return this->position.x;
}
int Organism::GetPositionY() const{
    return this->position.y;
}

void Organism::SetStrength(int new_strength){
    this->strength = new_strength;
}

void Organism::SetRemoved(){
    this->removed = 1;
}

int Organism::GetRemoved() const{
    return this->removed;
}

Organism::~Organism() {
}


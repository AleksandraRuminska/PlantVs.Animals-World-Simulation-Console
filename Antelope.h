#pragma once
#include "Animal.h"

class Antelope: public Animal {
public:
    Antelope(World& world);
    Antelope(World& world, int x, int y);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    void Action() override ;
    int Collision(int x, int y) override ;
    ~Antelope();

};

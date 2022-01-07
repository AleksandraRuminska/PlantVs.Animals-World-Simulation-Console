#pragma once
#include "Animal.h"

class Turtle: public Animal {
public:
    Turtle(World& world);
    Turtle(World& world, int x, int y);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    void Action() override ;
    ~Turtle();
};

#pragma once
#include "Animal.h"

class Sheep: public Animal {
public:
    Sheep(World& world);
    Sheep(World& world, int x, int y);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    ~Sheep();
};

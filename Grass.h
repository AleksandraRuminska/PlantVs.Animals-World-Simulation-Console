#pragma once
#include "Plant.h"

class Grass: public Plant {
public:
    Grass(World& world);
    Grass(World& world, int x, int y);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    ~Grass();
};



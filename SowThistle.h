#pragma once
#include "Plant.h"
#include "World.h"

class SowThistle: public Plant {
public:
    SowThistle(World& world);
    SowThistle(World& world, int x, int y);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    void Move() override;
    ~SowThistle();

};

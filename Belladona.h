#pragma once
#include "Plant.h"

class Belladona: public Plant {
public:
    Belladona(World& world);
    Belladona(World& world, int x, int y);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    ~Belladona();
};

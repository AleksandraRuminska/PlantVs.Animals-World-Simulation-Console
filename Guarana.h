#pragma once
#include "Plant.h"

class Guarana: public Plant {
public:
    Guarana(World& world);
    Guarana(World& world, int x, int y);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    ~Guarana();
};



#pragma once
#include "Animal.h"

class Fox: Animal {
public:
    Fox(World& world);
    Fox(World& world, int x, int y);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    void Move() override ;
    ~Fox();
};
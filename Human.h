#pragma once
#include "Animal.h"

class Human: public Animal {
private:
    WINDOW* win;
    int ability_turns;
    bool on;
public:
    Human(World& world, WINDOW* win);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    void Action() override ;
    ~Human();
};


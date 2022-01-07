#pragma once
#include "Plant.h"

class SosnowskyHogsweed: public Plant {
public:
    SosnowskyHogsweed(World& world);
    SosnowskyHogsweed(World& world, int x, int y);
    char Draw() override ;
    void NewSameTypeOrganism(int x, int y) override;
    void Action() override;
    ~SosnowskyHogsweed();
};

#pragma once
#include<iostream>
#include "World.h"
#include "Organism.h"
using namespace std;

class Animal: public Organism {
protected:
    World& world;
public:
    Animal(World &world, int strength, int initiative, char sign, int reflect);
    void Action() override;
    int Collision(int x, int y) override;
    void Move() override ;
    void GenerateInitialPosition(World& w);
    int FindPlace(int x1, int y1, int step,int make_new);
    virtual void NewSameTypeOrganism(int x, int y)=0;
    bool CheckIfFree(World& w, int x, int y);
    ~Animal();
};


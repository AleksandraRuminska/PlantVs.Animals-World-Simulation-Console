#pragma once
#include<iostream>
using namespace std;

struct position_t{
    int x;
    int y;
};
typedef struct position_t pos;

class Organism {
protected:
    int strength;
    int initiative;
    pos position;
    char sign;
    int reflect;
    int removed;
public:
    Organism(int strength, int removed, int initiative, char sign, int reflect);
    std::string name;
    int GetStrength() const;
    int GetInitiative() const;
    int GetReflect() const;
    int GetPositionX() const;
    int GetPositionY() const;
    void SetStrength(int new_strength);
    void SetRemoved();
    int GetRemoved() const;
    char GetSign() const;
    virtual void Move()=0;
    virtual void Action()=0;
    virtual int Collision(int x, int y)=0;
    virtual char Draw()=0;
    ~Organism();
};


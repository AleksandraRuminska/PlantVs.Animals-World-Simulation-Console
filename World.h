#pragma once
#include<vector>
#include<ncurses.h>
#include "Organism.h"

class World {
private:
    int turn;
    int length;
    int width;
    int check_human;
    std::vector<Organism*> organisms;
    std::vector<Organism*> duplicated;
public:
    Organism* ** board;
    World(int length, int width);
    int GetTurn() const;
    int GetLength() const;
    int GetWidth() const;
    int GetCheckHuman() const;
    void SetTurn();
    void AddOrganism(Organism* new_organism, int where);
    void RemoveOrganism();
    void MakeTurn();
    void DrawWorld(WINDOW* win);
    void AddDuplicates();
    ~World();
};

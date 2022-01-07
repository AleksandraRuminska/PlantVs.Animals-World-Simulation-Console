#include <iostream>
#include <ncurses.h>
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "Belladona.h"
#include "SosnowskyHogsweed.h"
#include "Human.h"

#define LENGTH 40
#define WIDTH 20

int main() {
    int rounds=0;
    cout << endl<< "Enter the number of turns: ";
    cin >> rounds;

    initscr();
    WINDOW* win = newwin(3*WIDTH,3*LENGTH,0,0);
    World w(LENGTH,WIDTH);
    Wolf wolf(w);
    Wolf wolf2(w);
    Wolf wolf3(w);
    Wolf wolf4(w);
    Wolf wolf5(w);
    Wolf wolf6(w);
    Fox fox(w);
    Fox fox2(w);
    Fox fox3(w);
    Fox fox4(w);
    Sheep sheep(w);
    Sheep sheep3(w);
    Sheep sheep2(w);
    Sheep sheep4(w);
    Sheep sheep5(w);
    Sheep sheep6(w);
    Sheep sheep7(w);
    Sheep sheep8(w);
    Turtle turtle(w);
    Turtle turtle2(w);
    Turtle turtle3(w);
    Turtle turtle4(w);
    Antelope antelope(w);
    Antelope antelope2(w);
    Antelope antelope3(w);
    Antelope antelope4(w);
    Antelope antelope5(w);
    Grass grass(w);
    Grass grass2(w);
    SowThistle st(w);
    SowThistle st2(w);
    Guarana guarana(w);
    Guarana guarana2(w);
    Belladona bella(w);
    Belladona bella2(w);
    SosnowskyHogsweed sh(w);
    SosnowskyHogsweed sh2(w);
    Human human(w,win);

    while(w.GetTurn() <= rounds) {
        w.DrawWorld(win);
        noecho();
        wrefresh(win);
        refresh();
        w.RemoveOrganism();
        w.AddDuplicates();
        w.MakeTurn();
        if(w.GetCheckHuman()==0) {
            getch();
            flushinp();
        }
        move(WIDTH+1,0);
        clrtobot();
        w.SetTurn();
    }

    endwin();
    return 0;
}
#include<iostream>
#include <vector>
#include<ncurses.h>
#include "World.h"
using namespace std;

#define LENGTH 40
#define WIDTH 20

World::World(int length, int width) {
    this->turn = 1;
    this->length = length;
    this->width = width;
    this->check_human = 0;

    board = new Organism** [this->width];
    for(int i=0; i<this->width; i++){
        board[i] = new Organism*[this->length];
    }

    for(int i=0; i<this->width; i++){
        for(int j=0; j<this->length; j++){
            board[i][j] = NULL;
        }
    }
}

int World::GetTurn() const{
    return this->turn;
}

int World::GetLength() const{
    return this->length;
}

int World::GetWidth() const{
    return this->width;
}

int World::GetCheckHuman() const{
    return this->check_human;
}

void World::SetTurn() {
    this->turn = this->turn + 1;
}

void World::AddOrganism(Organism *new_organism, int where) {
    if(where == 1) {
        organisms.push_back(new_organism);
    }else{
        duplicated.push_back(new_organism);
    }
}

void World::RemoveOrganism() {
   unsigned long i=0;
    for(i=0; i<organisms.size(); i++){
        if(organisms[i]->GetRemoved() == 1){
            swap(organisms[i], organisms[organisms.size()-1]);
            organisms.pop_back();
            i--;
        }
    }

}


void World::MakeTurn() {
    move(WIDTH+8,0);
    Organism* array[organisms.size()];
    int ii=0;
    for(Organism* i : organisms){
        if(ii==0) {
            array[ii] = i;
        } else {
            int j;
            for(j=0; j<ii; j++){
                if(i->GetInitiative() > array[j]->GetInitiative()){
                    for(int k=ii; k>j; k--){
                        array[k] = array[k-1];
                    }
                    array[j] = i;
                    break;
                }
            }
            if(j==ii){
                array[ii] = i;
            }
        }
        ii++;
    }
    for(unsigned long jj=0; jj<organisms.size(); jj++){
        if(array[jj]->GetRemoved() != 1) {
            array[jj]->Move();
        }
    }
}

void World::AddDuplicates() {
    if(!duplicated.empty()) {
        int ii=0;
        for(Organism* i : duplicated){
            organisms.push_back(i);
            ii++;
        }
        duplicated.clear();
    }
}

void World::DrawWorld(WINDOW* win){
    move(0,0);
    this->check_human=0;
    for(int i=0; i<this->length+2; i++){
        printw("%c",'-');
    }
    printw("\n");
    for(int i=0; i<this->width; i++){
        printw("%c",'|');
        for(int j=0; j<this->length; j++){
            if(board[i][j]!=NULL){
                if(board[i][j]->name=="human"){
                    this->check_human=1;
                }
                printw("%c",board[i][j]->Draw());
            } else {
                printw("%c",' ');
            }

            if(j==this->length-1){
                printw("%c",'|');
            }
        }
        printw("\n");
    }
    for(int i=0; i<this->length+2; i++){
        printw("%c",'-');
    }
    printw("\n");
    printw("Aleksandra Ruminska 179953\n\n");
    printw("TURN: ");
    printw("%d\n", turn);
    if(this->check_human==1) {
        printw("Choose a way for the human by pressing an arrow key");
    }
}


World::~World(){
    cout << endl << "Destroying World" << endl;
}


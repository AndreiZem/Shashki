#ifndef MAIN_H
#define MAIN_H

#include <iostream>
using namespace std;
#include <vector>



const string fff[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","S"};
const string ff_[16] = {" ","B","C","3","4","5","6","7","8","9","A","B","S"};
const int Xx[32] = {1,3,5,7,0,2,4,6,1,3,5,7,0,2,4,6,1,3,5,7,0,2,4,6,1,3,5,7,0,2,4,6};
const int Yy[32] = {7,7,7,7,6,6,6,6,5,5,5,5,4,4,4,4,3,3,3,3,2,2,2,2,1,1,1,1,0,0,0,0};
const int YyXx[8][8] = {
    {28,99,29,99,30,99,31,99},
    {99,24,99,25,99,26,99,27},
    {20,99,21,99,22,99,23,99},
    {99,16,99,17,99,18,99,19},
    {12,99,13,99,14,99,15,99},
    {99, 8,99, 9,99,10,99,11},
    { 4,99, 5,99, 6,99, 7,99},
    {99, 0,99, 1,99, 2,99, 3}
                 };

struct Doska {
//    int step; // из какого положения
    char pole[32]; // поле
};

struct miniDoska {
    char pole[13]; // поле

};

struct stek
{
    unsigned int pole;
    char igrok;
    char rezultat;
};



void PrintDoska(Doska Zz);

#endif // MAIN_H

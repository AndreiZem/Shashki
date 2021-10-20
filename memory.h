#ifndef MEMORY_H
#define MEMORY_H

#include "main.h"

Doska GetPole(string);
miniDoska  GetMem(unsigned int Der, int sas);
void putFile(Doska Aa);
Doska convMiniDoska(miniDoska Aa);
miniDoska transMiniDoska(Doska Aa);
void setRes(unsigned int Der, char res, int sas);
void analiz();

void SaveMem(string sss);
void LoadMem(string sss);

#endif // MEMORY_H

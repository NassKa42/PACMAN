#ifndef FANTOME_H
#define FANTOME_H
#include "plateau.h"
struct GHOST
{
    int posX;
    int posY;
    char dir;

};

typedef struct GHOST fantome;
fantome initFantome();
fantome deplacement_fantome_rng(fantome ghost,plateau map);
void caracfantome(fantome ghost);

#endif
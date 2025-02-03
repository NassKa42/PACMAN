#ifndef FANTOME_H
#define FANTOME_H
#include "plateau.h"
#include "pakuman.h"
#include "ressources.h"

struct StructFant
{
    int posX;
    int posY;
    char dir;

};

typedef struct StructFant fantome;
fantome initFantome(int x, int y);

fantome deplacement_fantome_rng(fantome ghost,plateau map);
void caracfantome(fantome ghost);
fantome deplacement_fantome_proche(Player pacman, fantome ghost, plateau map);




#endif
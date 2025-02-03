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
    char name[10];

};

typedef struct StructFant fantome;
fantome initFantome(int x, int y, char name[10]);

fantome deplacement_fantome_rng(fantome ghost,plateau map);
void caracfantome(fantome ghost);
fantome deplacement_fantome_proche(Player pacman, fantome ghost, plateau map);
fantome deplacement_fantome_proche2(Player pacman, fantome ghost, plateau map);





#endif
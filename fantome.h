#ifndef FANTOME_H
#define FANTOME_H
#include "plateau.h"
#include "pakuman.h"
#include "ressources.h"

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
fantome deplacement_fantome_proche(Player pacman, fantome ghost, plateau map);

int is_collision_e2b(int e_x, int e_y, plateau map); // A ENLEVER


#endif
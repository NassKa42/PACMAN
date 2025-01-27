
#ifndef PLATEAU_H
#define PLATEAU_H
#include "ressources.h"
struct plateauSt{
    int haut;
    int large;
    int tab[100][100];
};
typedef struct plateauSt plateau;
plateau initPlateau();
int affichePlateau(plateau t);
void graphPlateau(SDL_Renderer* renderer,plateau plat);


#endif
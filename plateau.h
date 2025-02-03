
#ifndef PLATEAU_H
#define PLATEAU_H
#include "ressources.h"
#include "fantome.h"

struct plateauSt{
    int haut;
    int large;
    int tab[100][100];
};
typedef struct plateauSt plateau;
plateau initPlateau();
int affichePlateau(plateau t);
void graphPlateau(SDL_Renderer* renderer,plateau plat);
int is_collision_e2b(int e_x, int e_y, plateau map);
int is_collision_p2g(int e_x, int e_y, plateau map);
void aff_pac(int e_x, int e_y, SDL_Renderer* ren, char dir);
void aff_fantome(int e_x, int e_y, SDL_Renderer* ren, char dir, fantome ghost);

#endif
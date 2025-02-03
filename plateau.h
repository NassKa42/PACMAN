
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
SDL_Renderer* graphPlateau(SDL_Renderer* renderer,plateau plat);
int is_collision_e2b(int e_x, int e_y, plateau map);
int is_collision_p2gmgc(int e_x, int e_y, plateau map);
tableau remove_gum(int e_x, int e_y, plateau map);
SDL_Renderer* aff_pac(int e_x, int e_y, SDL_Renderer* ren, char dir);
SDL_Renderer* aff_fantome(int e_x, int e_y, SDL_Renderer* ren, char dir, char ghost_name[10]);

#endif
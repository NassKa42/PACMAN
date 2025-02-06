
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
SDL_Renderer* graphPlateau(SDL_Renderer* renderer,plateau plat,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise);
int is_collision_e2b(int e_x, int e_y, plateau map);
int is_collision_p2gmgc(int e_x, int e_y, plateau map);
plateau remove_gum(int e_x, int e_y, plateau map);
SDL_Renderer* aff_pac(int e_x, int e_y, SDL_Renderer* ren, char dir,SDL_Texture* texture_pac_0,SDL_Texture* texture_pac_1,SDL_Texture* texture_pac_2,SDL_Texture* texture_pac_3, SDL_Texture* texture_pac_5, int animation);
SDL_Renderer* aff_fantome(int e_x, int e_y, SDL_Renderer* ren, char dir, char ghost_name[10]);
SDL_Renderer* aff_vies(int lives, SDL_Renderer* ren,SDL_Texture* vie);
void aff_score(int score, SDL_Renderer* ren,TTF_Font* font, SDL_Color White);

#endif
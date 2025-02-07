#ifndef PatoisDuSud
#define PatoisDuSud
#include "ressources.h"
#include "plateau.h"
#include "pakuman.h"

char start(plateau t, SDL_Renderer* ren, TTF_Font* font, SDL_Color Red,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise);
void perte_vie(SDL_Renderer* ren, int lives, Player pacman, plateau t,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise, SDL_Texture* ouvert, SDL_Texture* ferme,SDL_Texture* texture_pac_transparent);
void niveau_gagne(SDL_Renderer* ren , int score , Player pacman, plateau t, TTF_Font* font, SDL_Color White,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise,SDL_Texture* droite, SDL_Texture* gauche);
void perte_partie(SDL_Renderer* ren, int score, plateau t , TTF_Font* font, SDL_Color White, SDL_Color Red,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise);
int musique(char nom_doc[10], int fin);

#endif
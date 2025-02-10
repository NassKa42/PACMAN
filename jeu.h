#ifndef PatoisDuSud
#define PatoisDuSud
#include "ressources.h"
#include "plateau.h"
#include "pakuman.h"

char start(plateau t, SDL_Renderer* ren, TTF_Font* font, SDL_Color Red,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise);
void perte_vie(SDL_Renderer* ren, int lives, Player pacman, plateau t,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise, SDL_Texture* mort1, SDL_Texture* mort2, SDL_Texture* mort3, SDL_Texture* mort4, SDL_Texture* mort5, SDL_Texture* mort6, SDL_Texture* mort7, SDL_Texture* mort8, SDL_Texture* mort9, SDL_Texture* mort10, SDL_Texture* texture_pac_transparent);
void niveau_gagne(SDL_Renderer* ren , int score , Player pacman, plateau t, TTF_Font* font, SDL_Color White,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise,SDL_Texture* droite, SDL_Texture* gauche);
void perte_partie(SDL_Renderer* ren, int score, plateau t , TTF_Font* font, SDL_Color White, SDL_Color Red,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise);
int musique(char nom_doc[10], int fin);
char start_choix(plateau t, SDL_Renderer* ren, TTF_Font* font, SDL_Color Red);

#endif
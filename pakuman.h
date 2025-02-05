#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>
#include "plateau.h"
//0: vide
//1: mur
//2: gum
//3: mega gum
//4: fruit
//5: pacman
//6: rouge
//7: orange
//8: bleu
//9: rose

#ifndef PatoisDuNord
#define PatoisDuNord

struct PlayerStruct{char name; int x; int y; char orientation; int score;};
typedef struct PlayerStruct Player;
Player initPlayer(char* name);
Player reset_player(Player pacman);
int bouger(char direction, Player pakuman);
Player bougerdirect(char direction, Player pakuman);
Player BougerAvecTest(Player pakuman,char direction,plateau tableau);
int PeutBouger(char direction, Player pakuman, plateau tableau);
Player BougerFinal(Player pakuman, char direction);
int score_gum(Player pacman, plateau t);

#endif
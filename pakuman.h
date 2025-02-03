#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>

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
#define PatoisDunord

struct PlayerStruct{char name; int x; int y; int orientation; int score;};
typedef struct PlayerStruct Player;
Player initPlayer(char* name);


#endif
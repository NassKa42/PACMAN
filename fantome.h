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
struct POS  
{
int x; int y;};


typedef struct StructFant fantome;
typedef struct POS position;
fantome initFantome(int x, int y, char name[10]);
fantome reset_fantome(fantome ghost,int x,int y);
// fantome deplacement_fantome_rng(fantome ghost,plateau map);
void caracfantome(fantome ghost);
fantome deplacement_fantome_proche(Player pacman, fantome ghost, plateau map);
fantome deplacement_fantome_rng_intersection(fantome ghost, plateau map);
fantome deplacement_fantome_proche_continue(Player pacman, fantome ghost, plateau map);
fantome deplacement_fantome_proche_BFS(Player paku,fantome fantt, plateau map);
// fantome deplacement_fantome_proche2(Player pacman, fantome ghost, plateau map);
int fantome_peut_avancer(fantome ghost, plateau map);
int is_collision_p2g(fantome ghost, Player pacman);


#endif
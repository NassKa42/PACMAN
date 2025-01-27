#ifndef FANTOME_H
#define FANTOME_H

struct GHOST
{
    
    int posX;
    int posY;
    char dir[1];

};

typedef struct GHOST fantome;
fantome initFantome();
char deplacement_fantome_rng(fantome ghost,plateau map);

#endif
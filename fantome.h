#ifndef FANTOME_H
#define FANTOME_H

struct GHOST
{
    
    int posX;
    int posY;
    char dir;
    
};

typedef struct GHOST fantome;
fantome initFantome();


#endif
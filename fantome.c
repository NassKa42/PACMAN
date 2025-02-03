#include "ressources.h"
#include "fantome.h"

fantome initFantome(){
    fantome name;
    name.posX = 0;
    name.posY = 0;
    name.dir = 'h';
    return name;
};


fantome deplacement_fantome_rng(fantome ghost,plateau map){
    int collision = 0;
    int deplace = rand()%2;
        if ((ghost.dir == 'h' && map.tab[ghost.posY-1][ghost.posX] == 1) || (ghost.dir == 'b' && map.tab[ghost.posY+1][ghost.posX] == 1))
    {
        if (map.tab[ghost.posY][ghost.posX+1] == 1)
        {
            ghost.dir = 'g';
        }else if (map.tab[ghost.posY][ghost.posX-1] == 1)
        {
            ghost.dir = 'd';
        }else if (deplace==0)
        {
            ghost.dir = 'd';
        }else
        {
            ghost.dir = 'g';
        }   
    
    }else if ( (ghost.dir == 'g' && map.tab[ghost.posY][ghost.posX-1] == 1)|| (ghost.dir == 'd' && map.tab[ghost.posY][ghost.posX+1] == 1))
    {
        if (map.tab[ghost.posY+1][ghost.posX] == 1)
        {
            ghost.dir = 'h';
        }else if (map.tab[ghost.posY-1][ghost.posX] == 1)
        {
            ghost.dir = 'b';
        }else if (deplace==0)
        {
            ghost.dir = 'h';
        }else
        {
            ghost.dir = 'b';
        }   
    }else
    {   switch (ghost.dir)
    {
    case 'h':
        ghost.posY --;
        break;
        
    case 'b':
        ghost.posY ++;
        break;
        
    case 'g':
        ghost.posX --;
        break;
        
    case 'd':
        ghost.posX ++;
        break;
    
    default:
        break;
    }
        
    };
    return ghost;
    
    

};
void caracfantome(fantome ghost){
    printf("se situe en X = %d, Y = %d, direction = %c\n", ghost.posX, ghost.posY, ghost.dir);
};


struct pakuman{int posX; int posY};
typedef struct pakuman pakkkk;

fantome deplacement_fantome_possible(fantome ghost, plateau map, char dir){
    switch (dir)
    {
    case 'h':
        if (map.tab[ghost.posY +1][ghost.posX] == 1){}
        break;
    
    default:
        break;
    }
};

fantome deplacement_fantome_proche(pakkkk pacman, fantome ghost, plateau map){




};
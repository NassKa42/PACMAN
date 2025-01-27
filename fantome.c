#include "ressources.h"
#include "fantome.h"

fantome initFantome(){
    fantome name;
    name.posX = 0;
    name.posY = 0;
    name.dir = 'h';
    return name;
};


char deplacement_fantome_rng(fantome ghost,plateau map){
    int collision = 0;
    int deplace = rand()%2;
    char direction = 'n';
        if ((ghost.dir == 'h' && map.tab[ghost.posY-1][ghost.posX] == 1) || (ghost.dir == 'b' && map.tab[ghost.posY+1][ghost.posX] == 1))
    {
        if (map.tab[ghost.posY][ghost.posX+1] == 1)
        {
            direction = 'g';
        }else if (map.tab[ghost.posY][ghost.posX-1] == 1)
        {
            direction = 'd';
        }else if (deplace==0)
        {
            direction = 'd';
        }else
        {
            direction = 'g';
        }   
    
    }else if ( (ghost.dir == 'g' && map.tab[ghost.posY][ghost.posX-1] == 1)|| (ghost.dir == 'd' && map.tab[ghost.posY][ghost.posX+1] == 1))
    {
        if (map.tab[ghost.posY+1][ghost.posX] == 1)
        {
            direction = 'h';
        }else if (map.tab[ghost.posY-1][ghost.posX] == 1)
        {
            direction = 'b';
        }else if (deplace==0)
        {
            direction = 'h';
        }else
        {
            direction = 'b';
        }   
    }    
    
    

}
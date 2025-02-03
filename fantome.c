#include "fantome.h"

fantome initFantome(int x, int y){
    fantome ghost;
    ghost.posX = x*taillecase;
    ghost.posY = y*taillecase;
    ghost.dir = 'h';
    return ghost;
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

fantome deplacement_fantome_rng2222(fantome ghost,plateau map){ //CHANGER LE NOM
    int deplace = rand()%2;
        if ((ghost.dir == 'h' && is_collision_e2b(ghost.posX, ghost.posY-1, map) == 1) || (ghost.dir == 'b' && is_collision_e2b(ghost.posX, ghost.posY+1+ghostsize, map) == 1))
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



fantome deplacement_fantome_proche(Player pacman, fantome ghost, plateau map){
    if (ghost.posX < pacman.x && (is_collision_e2b(ghost.posX+ghostsize+1, ghost.posY, map) == 0)) // pacman a droite du pelo
    {
        //va a droite si possible   
        ghost.posX ++;
        ghost.dir == 'd';
        return ghost;
             
    }else if (ghost.posX > pacman.x && is_collision_e2b(ghost.posX+1, ghost.posY, map) == 0) // pacman a gauche
    {
        ghost.posX --;
        ghost.dir == 'g';
        return ghost;
        
    }else if (ghost.posY < pacman.y && (is_collision_e2b(ghost.posX, ghost.posY+ghostsize+1, map) == 0)) // pacman en bas
    {
        ghost.posY ++;
        ghost.dir == 'b';
        return ghost;
    }else if (ghost.posY > pacman.y && is_collision_e2b(ghost.posX, ghost.posY+1, map) == 0 ) //pac en haut
    {
        ghost.posY --;
        ghost.dir == 'h';
        return ghost;
        }
    else
    {
        return deplacement_fantome_rng(ghost, map);
    }
    };


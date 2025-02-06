#include "fantome.h"

fantome initFantome(int x, int y, char name[10]){
    fantome ghost;
    ghost.posX = x*taillecase;
    ghost.posY = y*taillecase;
    ghost.dir = 'h';
    strcpy(ghost.name , name);
    return ghost;
};

fantome reset_fantome(fantome ghost,int x,int y){
    ghost.posX = x *taillecase;
    ghost.posY = y *taillecase;
    return ghost;
}


void caracfantome(fantome ghost){
    printf("%s se situe en X = %d, Y = %d, direction = %c\n",ghost.name, ghost.posX, ghost.posY, ghost.dir);
};

int fantome_peut_avancer(fantome ghost, plateau map){//1 == peut avancer

    switch (ghost.dir)
    {
    case 'h':
        return !is_collision_e2b(ghost.posX, ghost.posY - 1, map) && !is_collision_e2b(ghost.posX + ghostsize - 1, ghost.posY - 1, map);
        break;
    
    case 'b':
        return !is_collision_e2b(ghost.posX, ghost.posY + ghostsize, map) && !is_collision_e2b(ghost.posX + ghostsize - 1, ghost.posY + ghostsize, map);
        break;
    case 'g':
        return !is_collision_e2b(ghost.posX - 1, ghost.posY, map) && !is_collision_e2b(ghost.posX - 1, ghost.posY + ghostsize - 1, map);
        break;
    case 'd':
        return !is_collision_e2b(ghost.posX + ghostsize, ghost.posY, map) && !is_collision_e2b(ghost.posX + ghostsize, ghost.posY + ghostsize - 1, map);
        break;        
    default:
        break;
    }

    return 0 ;
}

fantome deplacement_fantome_proche(Player pacman, fantome ghost, plateau map) {
    int bouge = 0; 
    if (ghost.posX < pacman.x && !is_collision_e2b(ghost.posX + ghostsize, ghost.posY, map) && !is_collision_e2b(ghost.posX + ghostsize, ghost.posY + ghostsize - 1, map)) {
        ghost.posX++;
        ghost.dir = 'd';
        bouge = 1;
    } 
    if (!bouge && ghost.posX > pacman.x &&  !is_collision_e2b(ghost.posX - 1, ghost.posY, map) && !is_collision_e2b(ghost.posX - 1, ghost.posY + ghostsize - 1, map)) {
        ghost.posX--;
        ghost.dir = 'g';
        bouge = 1;
    } 
    if (!bouge && ghost.posY < pacman.y &&  !is_collision_e2b(ghost.posX, ghost.posY + ghostsize, map) && !is_collision_e2b(ghost.posX + ghostsize - 1, ghost.posY + ghostsize, map)) {
        ghost.posY++;
        ghost.dir = 'b';
        bouge = 1;
    } 
    if (!bouge && ghost.posY > pacman.y &&  !is_collision_e2b(ghost.posX, ghost.posY - 1, map) && !is_collision_e2b(ghost.posX + ghostsize - 1, ghost.posY - 1, map)) {
        ghost.posY--;
        ghost.dir = 'h';
        bouge = 1;
    }

    return ghost;
}

fantome deplacement_fantome_proche_continue(Player pacman, fantome ghost, plateau map){
    int bouge = 0;
    if (fantome_peut_avancer(ghost, map) == 1)
    {
        if (ghost.dir == 'h')
        {
            ghost.posY --;
        }else if (ghost.dir == 'b')
        {
            ghost.posY ++;
        }else if (ghost.dir == 'g')
        {
            ghost.posX --  ; 
        }else
        {
            ghost.posX ++;
        }
        
        
        
        
    }else
    {
            ghost = deplacement_fantome_proche(pacman, ghost, map);
    }
    
    
    
    return ghost;
}

fantome deplacement_fantome_rng_intersection(fantome ghost, plateau map){
    int bouge = 0;
    
    int compte = 0;
    char dir[4] = {'h', 'b',  'g','d'};
    int possible[5] = {0,0,0,0,0};  
    char nodemitour;
    switch (ghost.dir)
    {
    case 'h':
        nodemitour = 'b';
        break;
    case 'b':
        nodemitour =  'h';
        break;
    case 'g':
        nodemitour = 'd';
        break;
    case 'd':
        nodemitour =  'g';
        break;
    
    default:
        break;
    } 
    if (!is_collision_e2b(ghost.posX, ghost.posY - 1, map) && !is_collision_e2b(ghost.posX + ghostsize - 1, ghost.posY - 1, map) && ghost.dir != 'b')
    {
         possible[0] = 1;//h
         compte++;
    }if (!is_collision_e2b(ghost.posX, ghost.posY + ghostsize, map) && !is_collision_e2b(ghost.posX + ghostsize - 1, ghost.posY + ghostsize, map)&& ghost.dir != 'h')
    {
        possible[1] = 1;//b
        compte++;
    }if (!is_collision_e2b(ghost.posX - 1, ghost.posY, map) && !is_collision_e2b(ghost.posX - 1, ghost.posY + ghostsize - 1, map)&& ghost.dir != 'd')
    {
        possible[2] = 1;//g
        compte++;
    }if (!is_collision_e2b(ghost.posX + ghostsize, ghost.posY, map) && !is_collision_e2b(ghost.posX + ghostsize, ghost.posY + ghostsize - 1, map)&& ghost.dir != 'g')
    {
        possible[3] = 1;//d
        compte ++;
    }int index = 4;
    srand(time(NULL));
    while (possible[index] == 0)
    {
        index = rand()%4;
    }
    switch (dir[index])
    {
    case 'h':
        ghost.posY --;
        ghost.dir = 'h';
        break;
    case 'b':
        ghost.posY ++;
        ghost.dir = 'b';
        break;
    case 'g':
        ghost.posX --;
        ghost.dir = 'g';
        break;
    case 'd':
        ghost.posX ++;
        ghost.dir = 'd';
        break;
    
    default:
        break;
    }return ghost;
    
    

}



int is_collision_p2g(fantome ghost, Player pacman){
    if (pacman.x >= ghost.posX && pacman.x <= ghost.posX + ghostsize){
        if (pacman.y >= ghost.posY && pacman.y <= ghost.posY + ghostsize){
            return 1; // collision
        } else if (pacman.y + pacsize >= ghost.posY && pacman.y + pacsize <= ghost.posY + ghostsize){
            return 1;
        } else {
            return 0;
        }
    } else if (pacman.x + pacsize >= ghost.posX && pacman.x + pacsize <= ghost.posX + ghostsize){
        if (pacman.y >= ghost.posY && pacman.y <= ghost.posY + ghostsize){
            return 1; // collision
        } else if (pacman.y + pacsize >= ghost.posY && pacman.y + pacsize <= ghost.posY + ghostsize){
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// fantome deplacement_fantome_rng(fantome ghost,plateau map){
//     int collision = 0;
//     int deplace = rand()%2;
//         if ((ghost.dir == 'h' && is_collision_e2b(ghost.posX, ghost.posY-1, map) == 1) || (ghost.dir == 'b' && is_collision_e2b(ghost.posX, ghost.posY+1+ghostsize, map)  == 1))
//     {
//         if (is_collision_e2b(ghost.posX+ghostsize+1, ghost.posY, map) == 1)
//         {
//             ghost.dir = 'g';
//         }else if (is_collision_e2b(ghost.posX-1, ghost.posY, map)== 1)
//         {
//             ghost.dir = 'd';
//         }else if (deplace==0)
//         {
//             ghost.dir = 'd';
//         }else
//         {
//             ghost.dir = 'g';
//         }   
    
//     }else if ( (ghost.dir == 'g' && is_collision_e2b(ghost.posX-1, ghost.posY, map) == 1)|| (ghost.dir == 'd' && is_collision_e2b(ghost.posX+ghostsize+1, ghost.posY, map) == 1))
//     {
//         if (is_collision_e2b(ghost.posX, ghost.posY+ghostsize+1, map) == 1)
//         {
//             ghost.dir = 'h';
//         }else if (is_collision_e2b(ghost.posX, ghost.posY-1, map) == 1)
//         {
//             ghost.dir = 'b';
//         }else if (deplace==0)
//         {
//             ghost.dir = 'h';
//         }else
//         {
//             ghost.dir = 'b';
//         }   
//     }else
//     {   switch (ghost.dir)
//     {
//     case 'h':
//         ghost.posY --;
//         break;
        
//     case 'b':
//         ghost.posY ++;
//         break;
        
//     case 'g':
//         ghost.posX --;
//         break;
        
//     case 'd':
//         ghost.posX ++;
//         break;
    
//     default:
//         break;
//     }
        
//     };
//     return ghost;
    
    

// };








/*
GO droite
        ghost.posX ++;
        ghost.dir = 'd';
        return ghost;

GO gauche
        ghost.posX --;
        ghost.dir = 'g';
        return ghost;

GO haut
        ghost.posY --;
        ghost.dir = 'h';
        return ghost;

GO bas
        ghost.posY ++;
        ghost.dir = 'b';
        return ghost;



*/
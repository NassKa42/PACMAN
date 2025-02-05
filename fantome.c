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

fantome deplacement_fantome_rng(fantome ghost,plateau map){
    int collision = 0;
    int deplace = rand()%2;
        if ((ghost.dir == 'h' && is_collision_e2b(ghost.posX, ghost.posY-1, map) == 1) || (ghost.dir == 'b' && is_collision_e2b(ghost.posX, ghost.posY+1+ghostsize, map)  == 1))
    {
        if (is_collision_e2b(ghost.posX+ghostsize+1, ghost.posY, map) == 1)
        {
            ghost.dir = 'g';
        }else if (is_collision_e2b(ghost.posX-1, ghost.posY, map)== 1)
        {
            ghost.dir = 'd';
        }else if (deplace==0)
        {
            ghost.dir = 'd';
        }else
        {
            ghost.dir = 'g';
        }   
    
    }else if ( (ghost.dir == 'g' && is_collision_e2b(ghost.posX-1, ghost.posY, map) == 1)|| (ghost.dir == 'd' && is_collision_e2b(ghost.posX+ghostsize+1, ghost.posY, map) == 1))
    {
        if (is_collision_e2b(ghost.posX, ghost.posY+ghostsize+1, map) == 1)
        {
            ghost.dir = 'h';
        }else if (is_collision_e2b(ghost.posX, ghost.posY-1, map) == 1)
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

// fantome deplacement_fantome_rng(fantome ghost, plateau map) {
//     // Liste des directions possibles (haut, bas, gauche, droite)
//     char directions[4] = {'h', 'b', 'g', 'd'};
//     int deplace = rand() % 4; // Choisit une direction aléatoire

//     // Essaie de se déplacer dans la direction choisie
//     for (int i = 0; i < 4; i++) {
//         char dir = directions[(deplace + i) % 4]; // Commence par la direction aléatoire, puis essaie les autres

//         int new_posX = ghost.posX;
//         int new_posY = ghost.posY;

//         // Calcule les nouvelles coordonnées en fonction de la direction
//         switch (dir) {
//             case 'h': new_posY--; break; // Haut
//             case 'b': new_posY++; break; // Bas
//             case 'g': new_posX--; break; // Gauche
//             case 'd': new_posX++; break; // Droite
//         }

//         // Vérifie si le déplacement est possible (pas de collision)
//         if (is_collision_e2b(new_posX, new_posY, map) == 0) {
//             ghost.posX = new_posX;
//             ghost.posY = new_posY;
//             ghost.dir = dir; // Met à jour la direction du fantôme
//             return ghost; // Retourne le fantôme déplacé
//         }
//     }

//     // Si aucune direction n'est possible, retourne le fantôme sans le déplacer
//     return ghost;
// }

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
    printf("%s se situe en X = %d, Y = %d, direction = %c\n",ghost.name, ghost.posX, ghost.posY, ghost.dir);
};



fantome deplacement_fantome_proche(Player pacman, fantome ghost, plateau map){
    if (ghost.posX < pacman.x && (is_collision_e2b(ghost.posX+ghostsize+1, ghost.posY, map) == 0)) // pacman a droite du pelo
    {
        //va a droite si possible   
        ghost.posX ++;
        ghost.dir = 'd';
        return ghost;
             
    }else if (ghost.posX > pacman.x && is_collision_e2b(ghost.posX-1, ghost.posY, map) == 0) // pacman a gauche
    {
        ghost.posX --;
        ghost.dir = 'g';
        return ghost;
        
    }else if (ghost.posY < pacman.y && (is_collision_e2b(ghost.posX, ghost.posY+ghostsize+1, map) == 0)) // pacman en bas
    {
        ghost.posY ++;
        ghost.dir = 'b';
        return ghost;
    }else if (ghost.posY > pacman.y && is_collision_e2b(ghost.posX, ghost.posY-1, map) == 0 ) //pac en haut
    {
        ghost.posY --;
        ghost.dir = 'h';
        return ghost;
        }
    else
    {
        return deplacement_fantome_rng(ghost, map);
    }
    };


fantome deplacement_fantome_proche2(Player pacman, fantome ghost, plateau map){
   int newposX = ghost.posX;
   int newposY = ghost.posY;
   if (ghost.posX < pacman.x && (is_collision_e2b(ghost.posX+ghostsize+1, ghost.posY, map) == 0)) // pacman a droite du pelo
    {
        //va a droite si possible   
        ghost.posX ++;
        ghost.dir = 'd';
        printf("droit\n");
        return ghost;
             
    }else if (ghost.posX > pacman.x && is_collision_e2b(ghost.posX-1, ghost.posY, map) == 0) // pacman a gauche
    {
        ghost.posX --;
        ghost.dir = 'g';
        printf("gauche\n");
        return ghost;
        
    }else if (ghost.posY < pacman.y && (is_collision_e2b(ghost.posX, ghost.posY+ghostsize+1, map) == 0)) // pacman en bas
    {
        ghost.posY ++;
        ghost.dir = 'b';
        printf("bas\n");
        return ghost;
    }else if (ghost.posY > pacman.y && is_collision_e2b(ghost.posX, ghost.posY-1, map) == 0 ) //pac en haut
    {
        ghost.posY --;
        ghost.dir = 'h';
        printf("haut\n");
        return ghost;
        }
    else
    {
        printf("randomidzaulbbbbbbbbbbbbbbbbbbbbblllllllllllllllllllllllllllllllllllllllllllllllllllll\n");
        return deplacement_fantome_rng(ghost, map);
        
    }
    };

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
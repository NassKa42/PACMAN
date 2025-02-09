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

int fantome_peut_avancer_dir(int ghostX, int ghostY, plateau map, char dir){//1 == peut avancer

    switch (dir)
    {
    case 'h':
        return !is_collision_e2b(ghostX, ghostY - 1, map) && !is_collision_e2b(ghostX + ghostsize - 1, ghostY - 1, map);
        break;
    
    case 'b':
        return !is_collision_e2b(ghostX, ghostY + ghostsize, map) && !is_collision_e2b(ghostX + ghostsize - 1, ghostY + ghostsize, map);
        break;
    case 'g':
        return !is_collision_e2b(ghostX - 1, ghostY, map) && !is_collision_e2b(ghostX - 1, ghostY + ghostsize - 1, map);
        break;
    case 'd':
        return !is_collision_e2b(ghostX + ghostsize, ghostY, map) && !is_collision_e2b(ghostX + ghostsize, ghostY + ghostsize - 1, map);
        break;        
    default:
        break;
    }

    return 0 ;
}

fantome deplacement_fantome_proche(Player pacman, fantome ghost, plateau map) {
    int bouge = 0; 
     
    if (ghost.posX < pacman.x && !is_collision_e2b(ghost.posX + ghostsize, ghost.posY, map) && !is_collision_e2b(ghost.posX + ghostsize, ghost.posY + ghostsize - 1, map)) {
        ghost.posX = ghost.posX + ghost_speed;
        ghost.dir = 'd';

    } else
    if (!bouge && ghost.posX > pacman.x &&  !is_collision_e2b(ghost.posX - 1, ghost.posY, map) && !is_collision_e2b(ghost.posX - 1, ghost.posY + ghostsize - 1, map)) {
        ghost.posX = ghost.posX - ghost_speed;
        ghost.dir = 'g';

    }else if (!bouge && ghost.posY < pacman.y &&  !is_collision_e2b(ghost.posX, ghost.posY + ghostsize, map) && !is_collision_e2b(ghost.posX + ghostsize - 1, ghost.posY + ghostsize, map)) {
        ghost.posY = ghost.posY + ghost_speed;
        ghost.dir = 'b';

    } else
    if (!bouge && ghost.posY > pacman.y &&  !is_collision_e2b(ghost.posX, ghost.posY - 1, map) && !is_collision_e2b(ghost.posX + ghostsize - 1, ghost.posY - 1, map)) {
        ghost.posY = ghost.posY - ghost_speed;
        ghost.dir = 'h';

    }
    return ghost;
}

fantome deplacement_fantome_proche_continue(Player pacman, fantome ghost, plateau map){
    int bouge = 0;
    switch(ghost.dir){
        case 'd':
            ghost.dir = 'h';
            if (fantome_peut_avancer(ghost, map) == 1){
                bouge ++;
            }
            ghost.dir = 'b';
            if (fantome_peut_avancer(ghost, map) == 1){
                bouge ++;
            }
            ghost.dir = 'd';
            if (bouge !=0){
                ghost = deplacement_fantome_proche(pacman, ghost, map);
            } else if (fantome_peut_avancer(ghost, map) == 1){
                ghost.posX = ghost.posX + ghost_speed;
            } else {
                ghost.dir = 'g';
                // ghost = deplacement_fantome_proche(pacman,ghost, map);
            }
            break;
        case 'g':
            ghost.dir = 'h';
            if (fantome_peut_avancer(ghost, map) == 1){
                bouge ++;
            }
            ghost.dir = 'b';
            if (fantome_peut_avancer(ghost, map) == 1){
                bouge ++;
            }
            ghost.dir = 'g';
            if (bouge !=0){
                ghost = deplacement_fantome_proche(pacman, ghost, map);
            } else if (fantome_peut_avancer(ghost, map) == 1){
                ghost.posX = ghost.posX - ghost_speed;
            } else {
                ghost.dir = 'd';
                // ghost = deplacement_fantome_proche(pacman,ghost, map);
            }
            break;
        case 'h':
            ghost.dir = 'd';
            if (fantome_peut_avancer(ghost, map) == 1){
                bouge ++;
            }
            ghost.dir = 'g';
            if (fantome_peut_avancer(ghost, map) == 1){
                bouge ++;
            }
            ghost.dir = 'h';
            if (bouge !=0){
                ghost = deplacement_fantome_proche(pacman, ghost, map);
            } else if (fantome_peut_avancer(ghost, map) == 1){
                ghost.posY = ghost.posY - ghost_speed;
            } else {
                ghost = deplacement_fantome_rng_intersection(ghost, map);
            }
            break;
        case 'b':
            ghost.dir = 'd';
            if (fantome_peut_avancer(ghost, map) == 1){
                bouge ++;
            }
            ghost.dir = 'g';
            if (fantome_peut_avancer(ghost, map) == 1){
                bouge ++;
            }
            ghost.dir = 'b';
            if (bouge !=0){
                ghost = deplacement_fantome_proche(pacman, ghost, map);
            } else if (fantome_peut_avancer(ghost, map) == 1){
                ghost.posY = ghost.posY + ghost_speed; 
            } else {
                ghost =deplacement_fantome_rng_intersection(ghost, map);
            }
            break;
        default :
            break;
    } return ghost; }
//     if (fantome_peut_avancer(ghost, map) == 1)
//     {
//         if (ghost.dir == 'h')
//         {
//             ghost.posY --;
//         }else if (ghost.dir == 'b')
//         {
//             ghost.posY ++;
//         }else if (ghost.dir == 'g')
//         {
//             ghost.posX --  ; 
//         }else
//         {
//             ghost.posX ++;
//         }
        
        
        
        
//     }else
//     {
//             ghost = deplacement_fantome_proche(pacman, ghost, map);
//     }
    
    
    
//     return ghost;
// }

fantome deplacement_fantome_rng_intersection(fantome ghost, plateau map){
    int bouge = 0;
    
    int compte = 0;
    char dir[4] = {'h', 'b',  'g','d'};
    int possible[5] = {0,0,0,0,0};  
    char nodemitour;
   
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
    }
    if (compte == 0)
    {
        switch (ghost.dir)
    {
    case 'h':
        ghost.posY = ghost.posY + ghost_speed;
        ghost.dir = 'b';
        break;
    case 'b':
        
        ghost.posY = ghost.posY - ghost_speed;
        ghost.dir = 'h';
        break;
    case 'g':
        ghost.posX = ghost.posX + ghost_speed;
        ghost.dir = 'd';
        break;
    case 'd':
        
        ghost.posX = ghost.posX - ghost_speed;
        ghost.dir = 'g';
        break;
    
    default:
        break;
    }
    }else
    {int index = 4;
    srand(time(NULL));
    while (possible[index] == 0)
    {
        index = rand()%4;
    }
    switch (dir[index])
    {
    case 'h':
        ghost.posY = ghost.posY - ghost_speed;
        ghost.dir = 'h';
        break;
    case 'b':
        ghost.posY = ghost.posY + ghost_speed;
        ghost.dir = 'b';
        break;
    case 'g':
        ghost.posX = ghost.posX - ghost_speed;
        ghost.dir = 'g';
        break;
    case 'd':
        ghost.posX = ghost.posX + ghost_speed;
        ghost.dir = 'd';
        break;
    
    default:
        break;
    }
         
    }
    
    
    
    return ghost;
    
    

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

fantome deplacement_fantome_proche_BFS(Player paku,fantome fantt, plateau map){
    /*Explication algo BFS 
    l'algo va créer une file d'attente des noeuds a visiter et va a chaque fois visiter ce noeud en annotant 
    les noeuds suivants, en conservant a chaque fois la distance parcourue depuis le noeud initial  FINIR EXPLICATIONS
    https://www.youtube.com/watch?v=rbYxbIMOZkE&t=42s


    
    */
    position pacman;
    position ghost;
    position current;
    pacman.x = paku.x;  
    pacman.y = paku.y;
    ghost.x = fantt.posX;
    ghost.y = fantt.posY;


    position queue[map.large*map.haut]; // "liste d'attente" des noeuds a parcourir
    position parent[map.haut][map.large]; // sert a reconstruire le chemin a lafin 
    
    int distance[map.haut][map.large];
    for (int i = 0; i < map.haut; i++)
    {
        for (int j = 0; j < map.large; j++)
        {
            distance[i][j] = -1;
            parent[i][j].x = -1;
            parent[i][j].y = -1;
            
            }}

    distance[ghost.y][ghost.x] = 0; // tableau repertoriant les distances au point initial
    int avant = 0; // endroit ou on va lire
    int arriere = 0; // endroit ou on écrit
    queue[arriere] = ghost;
    arriere++;
    
    int directionX[4] = {0,0,-1,1};
    int directionY[4] = {-1,1,0,0};
    char dir[4] = {'h', 'b', 'g','d'};
    
    printf("1");
    while (avant < arriere)//fini quand ou on lit = ou on écrit
    {
        current = queue[avant];
        avant ++;
        fantome virtuel;
        virtuel = initFantome(current.x, current.y, "osef");
        // definition d'un fantome temporaire et inutile pour voir si aux coordonnées current, il y a pacman
        if (is_collision_p2g(virtuel, paku)==1)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int dirx = current.x+ directionX[i];
            int diry = current.y+ directionY[i];

            if (is_collision_e2b(dirx, diry, map)==0 && distance[diry][dirx] == -1) {
                distance[diry][dirx] = distance[current.y][current.x] + 1;
                parent[diry][dirx] = current;  
                position tmp ;
                tmp.x = dirx;
                tmp.y = diry;
                queue[arriere] = tmp;
                arriere ++;
        }
        
    }   
    }
    printf("2");
    // MTN, retrouver le chemin le plus court
    current = pacman;
    position next ;
    printf("debut boucle\n");
for (int i = 0; i < map.haut; i++)
{
    for (int j = 0; j < map.large; j++)
    {
        printf("%d, %d\n", parent[i][j].x, parent[i][j].y);
    }
    
}


    while (!(parent[current.y][current.x].x == ghost.x && parent[current.y][current.x].y == ghost.y))
    {
        printf("dans la boucle\n");
        next = current;
        current = parent[current.y][current.x];
        printf("%d, %d\n", next.x, next.y);

    }
    printf("3");
    fantt.posX = next.x;
    fantt.posY = next.y;
    return fantt;
    
}

fantome deplacement_fantome_proche_BFS2(Player paku,fantome fantt, plateau map){
    /*Explication algo BFS 
    l'algo va créer une file d'attente des noeuds a visiter et va a chaque fois visiter ce noeud en annotant 
    les noeuds suivants, en conservant a chaque fois la distance parcourue depuis le noeud initial  FINIR EXPLICATIONS
    https://www.youtube.com/watch?v=rbYxbIMOZkE&t=42s


    
    */
    position pacman;
    position ghost;
    position current;
    pacman.x = paku.x/taillecase;  
    pacman.y = paku.y/taillecase;
    ghost.x = fantt.posX/taillecase; 
    ghost.y = fantt.posY/taillecase; //convertit sur la grille


    position queue[map.large*map.haut]; // "liste d'attente" des noeuds a parcourir
    position parent[map.haut][map.large]; // sert a reconstruire le chemin a lafin 
    
    int distance[map.haut][map.large];
    for (int i = 0; i < map.haut; i++)
    {
        for (int j = 0; j < map.large; j++)
        {
            distance[i][j] = -1;
            parent[i][j].x = -1;
            parent[i][j].y = -1;
            
            }}

    distance[ghost.y][ghost.x] = 0; // tableau repertoriant les distances au point initial
    int avant = 0; // endroit ou on va lire
    int arriere = 0; // endroit ou on écrit
    queue[arriere] = ghost;
    arriere++;
    
    int directionX[4] = {0,0,-1,1};
    int directionY[4] = {-1,1,0,0};
    //                   h,b,g,d

    paku.x = pacman.x*taillecase;
    paku.y = pacman.y*taillecase;
    while (avant < arriere)//fini quand ou on lit = ou on écrit
    {
        current = queue[avant];
       
        avant ++;
        fantome virtuel;
        virtuel = initFantome(current.x*taillecase, current.y*taillecase, "osef");
        // definition d'un fantome temporaire et inutile pour voir si aux coordonnées current, il y a pacman
        if (is_collision_p2g(virtuel, paku)==1)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int dirx = current.x+ directionX[i];
            int diry = current.y+ directionY[i];
            
            if (map.tab[diry][dirx] !=1 && distance[diry][dirx] == -1) {
               
                distance[diry][dirx] = distance[current.y][current.x] + 1;
                parent[diry][dirx] = current;  
                position tmp ;
                tmp.x = dirx;
                tmp.y = diry;
                queue[arriere] = tmp;
                arriere ++;
        }
        
    }   
    }
   
    // MTN, retrouver le chemin le plus court
    current = pacman;
    position next ;
  
// for (int i = 0; i < map.haut; i++)
// {
//     for (int j = 0; j < map.large; j++)
//     {
//         printf("%d, %d\n", parent[i][j].x, parent[i][j].y);
//     }
    
// }


    while (!(parent[current.y][current.x].x == ghost.x && parent[current.y][current.x].y == ghost.y))
    {
        // printf("dans la boucle\n");
        next = current;
        current = parent[current.y][current.x];
        // printf("%d, %d\n", next.x, next.y);

    }
   

    int dirx = ghost.x - next.x;
    int diry = ghost.y - next.y;
    if (dirx<0)
    {
        fantt.dir = 'd';
        fantt.posX = fantt.posX + ghost_speed;
    }else if (dirx>0)
    {
        fantt.dir = 'g';
        fantt.posX = fantt.posX - ghost_speed;
    }
    if (diry<0)
    {
        fantt.dir = 'b';
        fantt.posY = fantt.posY + ghost_speed;
    }else if (diry>0)
    {
        fantt.dir = 'h';
        fantt.posY = fantt.posY - ghost_speed;
    }
    
    
    
    return fantt;
    
}

fantome deplacement_fantome_proche_BFS2_new(Player paku,fantome fantt, plateau map){
    /*Explication algo BFS 
    l'algo va créer une file d'attente des noeuds a visiter et va a chaque fois visiter ce noeud en annotant 
    les noeuds suivants, en conservant a chaque fois la distance parcourue depuis le noeud initial  FINIR EXPLICATIONS
    https://www.youtube.com/watch?v=rbYxbIMOZkE&t=42s


    
    */
    position pacman;
    position ghost;
    position current;
    pacman.x = paku.x/taillecase;  
    pacman.y = paku.y/taillecase;
    ghost.x = fantt.posX/taillecase; 
    ghost.y = fantt.posY/taillecase; //convertit sur la grille
    int bouge = 0;

    position queue[map.large*map.haut]; // "liste d'attente" des noeuds a parcourir
    position parent[map.haut][map.large]; // sert a reconstruire le chemin a lafin 
    
    int distance[map.haut][map.large];
    for (int i = 0; i < map.haut; i++)
    {
        for (int j = 0; j < map.large; j++)
        {
            distance[i][j] = -1;
            parent[i][j].x = -1;
            parent[i][j].y = -1;
            
            }}

    distance[ghost.y][ghost.x] = 0; // tableau repertoriant les distances au point initial
    int avant = 0; // endroit ou on va lire
    int arriere = 0; // endroit ou on écrit
    queue[arriere] = ghost;
    arriere++;
    
    int directionX[4] = {0,0,-1,1};
    int directionY[4] = {-1,1,0,0};
    //                   h,b,g,d

    while (avant < arriere)//fini quand ou on lit = ou on écrit
    {
        current = queue[avant];
       
        avant ++;
        
        if (current.x == pacman.x && current.y == pacman.y)
        {
            break; // voir pour le guider plus simplement si ya pas eu de collision mais que ils sont sur la mm case
        }
        for (int i = 0; i < 4; i++)
        {
            int dirx = current.x+ directionX[i];
            int diry = current.y+ directionY[i];
            
            if (map.tab[diry][dirx] !=1 && distance[diry][dirx] == -1) {
               
                distance[diry][dirx] = distance[current.y][current.x] + 1;
                parent[diry][dirx] = current;  
                position tmp ;
                tmp.x = dirx;
                tmp.y = diry;
                queue[arriere] = tmp;
                arriere ++;
        }
        
    }   
    }
   
    // MTN, retrouver le chemin le plus court
    current = pacman;
    position next ;
  
// for (int i = 0; i < map.haut; i++)
// {
//     for (int j = 0; j < map.large; j++)
//     {
//         printf("%d, %d\n", parent[i][j].x, parent[i][j].y);
//     }
    
// }


    while (!(parent[current.y][current.x].x == ghost.x && parent[current.y][current.x].y == ghost.y))
    {
        // printf("dans la boucle\n");
        next = current;
        current = parent[current.y][current.x];
        // printf("%d, %d\n", next.x, next.y);

    }
   

    int dirx = ghost.x - next.x;
    int diry = ghost.y - next.y;
    printf("dirx : %d, diry, %d \n", dirx,diry);
    // if (dirx<0 )
    // {
    //     fantt.dir = 'd';
    //     fantt.posX = fantt.posX + 1;
    // }else if (dirx>0 )
    // {
    //     fantt.dir = 'g';
    //     fantt.posX = fantt.posX - 1;
    // }
    // else if (diry<0 )
    // {
    //     fantt.dir = 'b';
    //     fantt.posY = fantt.posY + 1;
    // }else if (diry>0 )
    // {
    //     fantt.dir = 'h';
    //     fantt.posY = fantt.posY - 1;
    // }
    


    if (dirx<0 && !is_collision_e2b(fantt.posX + ghostsize, fantt.posY, map) && !is_collision_e2b(fantt.posX + ghostsize, fantt.posY + ghostsize - 1, map)) {
        fantt.posX = fantt.posX + ghost_speed;
        fantt.dir = 'd';
        bouge ++;

    } else
    if (bouge == 0 && dirx > 0 &&  !is_collision_e2b(fantt.posX - 1, fantt.posY, map) && !is_collision_e2b(fantt.posX - 1, fantt.posY + ghostsize - 1, map)) {
        fantt.posX = fantt.posX - ghost_speed;
        fantt.dir = 'g';bouge ++;

    }else if (bouge == 0 && diry < 0 &&  !is_collision_e2b(fantt.posX, fantt.posY + ghostsize, map) && !is_collision_e2b(fantt.posX + ghostsize - 1, fantt.posY + ghostsize, map)) {
        fantt.posY = fantt.posY + ghost_speed;
        fantt.dir = 'b';
        bouge ++;

    } else
    if (bouge == 0 && diry > 0 &&  !is_collision_e2b(fantt.posX, fantt.posY - 1, map) && !is_collision_e2b(fantt.posX + ghostsize - 1, fantt.posY - 1, map)) {
        fantt.posY = fantt.posY - ghost_speed;
        fantt.dir = 'h';
        bouge ++;

    }
    if (bouge == 0)
    {
        fantt = deplacement_fantome_proche(paku, fantt, map);
        printf("bouge = 0");
    }
    
    
    
    return fantt;
    
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
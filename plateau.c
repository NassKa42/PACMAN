#include "plateau.h"




typedef struct plateauSt plateau;
plateau initPlateau(char map[21][19]){
    plateau plat;
    plat.haut = 21;
    plat.large = 19;
    for ( int i = 0; i<plat.haut; i++){
        for ( int j = 0; j<plat.large; j++){
            switch(map[i][j]){
                case 'v':
                    plat.tab[i][j] = 0;
                    break;
                case 'w':
                    plat.tab[i][j] = 1;
                    break;
                case 'g':
                    plat.tab[i][j] = 2;
                    break;
                case 'm':
                    plat.tab[i][j] = 3;
                    break;
                default:
                    break;
                }
        }
    }
    return plat;
}

int affichePlateau(plateau t){
    int i = 0;
    int j = 0;
    for ( i = 0; i<t.haut; i++){
        for (j = 0; j<t.large; j++){
            printf("%d", t.tab[i][j]);
        };
        printf("\n");
    };
    return 0;
}


SDL_Renderer* graphPlateau(SDL_Renderer* ren,plateau plat,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise){    
    for ( int i = 0; i<plat.haut; i++){
        for ( int j = 0; j<plat.large; j++){
            switch(plat.tab[i][j]){
                case 0:

                    break;
                case 1:
                    renderTexture(wall,ren,j*taillecase,i*taillecase,taillecase,taillecase);
                    break;
                case 2:
                    renderTexture(gum,ren,j*taillecase,i*taillecase,taillecase,taillecase);
                    break;
                case 3:
                    renderTexture(biggum,ren,j*taillecase,i*taillecase,taillecase,taillecase);
                    break;
                case 4:
                    renderTexture(cerise,ren,j*taillecase,i*taillecase,taillecase,taillecase);
                    break;
                default:
                    break;
                }

        }
    }
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    return ren;
}

// int is_collision_e2b(int e_x, int e_y, plateau map){ // test collision entitée to block
//     if (map.tab[e_y/taillecase][e_x/taillecase]==1)
//     {
//         return 1;
//     }else
//     {
//         return 0;
//     };
// }


int is_collision_e2b(int e_x, int e_y, plateau map) {
    // Vérifie si les coordonnées sont dans les limites de la carte
    if (e_x < 0 || e_x >= map.large * taillecase || e_y < 0 || e_y >= map.haut * taillecase) {
        return 1; // Hors limites = collision
    }

    // Calcule les indices de la case dans la carte
    int case_x = e_x / taillecase;
    int case_y = e_y / taillecase;

    // Vérifie si la case est un mur (1) ou un autre obstacle
    if (map.tab[case_y][case_x] == 1) {
        return 1; // Collision détectée
    }

    return 0; // Pas de collision
}
int is_collision_p2gmgc(int e_x, int e_y, plateau map){ // test collision pacman to gum/ megam gum / cherry
    if (map.tab[e_y/taillecase][e_x/taillecase]==2)
    {
        return 1;
    }else if(map.tab[e_y/taillecase][e_x/taillecase]==3){
        return 2;
    }else if(map.tab[e_y/taillecase][e_x/taillecase]==4){
        return 3;
    }else{
        return 0;
    };
}

plateau remove_gum(int e_x, int e_y, plateau map){
    int t_y = e_y/taillecase;
    int t_x = e_x/taillecase;
    switch(map.tab[t_y][t_x]){
        case 1:
            break;
        case 0:
            break;
        default:
            map.tab[t_y][t_x] = 0;
    }
    return map;
}

SDL_Renderer* aff_pac(int e_x, int e_y, SDL_Renderer* ren, char dir,SDL_Texture* texture_pac_0,SDL_Texture* texture_pac_1,SDL_Texture* texture_pac_2,SDL_Texture* texture_pac_3, SDL_Texture* texture_pac_5, int animation){
    switch(animation){
        case 2:
            switch(dir){
                case 'h':
                    renderTexture(texture_pac_1,ren,e_x,e_y,pacsize,pacsize);
                    break;
                case 'b':
                    renderTexture(texture_pac_3,ren,e_x,e_y,pacsize,pacsize);
                    break;
                case 'g':
                    renderTexture(texture_pac_2,ren,e_x,e_y,pacsize,pacsize);
                    break;
                case 'd':
                    renderTexture(texture_pac_0,ren,e_x,e_y,pacsize,pacsize);
                    break;
                default :
                    break;
            };
            break;
        case 0:
            renderTexture(texture_pac_5,ren,e_x,e_y,pacsize,pacsize);
            break;
        default:
            break;
    };
    return ren;
}

SDL_Renderer* aff_fantome(int e_x, int e_y, SDL_Renderer* ren, char dir, char ghost_name[10]){
    // char nom_doc[15];
    // nom_doc[0] = 'f';
    // printf("%s \n",nom_doc);
    // printf("%c , \\0 \n", nom_doc[14] );
    // char pos = ' ';
    // char ghost_number = ' ';
    char nom_doc[13];
    switch(dir){
        case 'h':
            switch(ghost_name[0]){
                case 'b':
                    strcpy(nom_doc, "ghost1_1.bmp");
                    break;
                case 'p':
                    strcpy(nom_doc, "ghost2_1.bmp");
                    break;
                case 'i':
                    strcpy(nom_doc, "ghost3_1.bmp");
                    break;
                case 'c':
                    strcpy(nom_doc, "ghost4_1.bmp");
                    break;
                default :
                    break;
            }
            break;
        case 'b':
            switch(ghost_name[0]){
                case 'b':
                    strcpy(nom_doc, "ghost1_3.bmp");
                    break;
                case 'p':
                    strcpy(nom_doc, "ghost2_3.bmp");
                    break;
                case 'i':
                    strcpy(nom_doc, "ghost3_3.bmp");
                    break;
                case 'c':
                    strcpy(nom_doc, "ghost4_3.bmp");
                    break;
                default :
                    break;
                }
                break;
        case 'g':
            switch(ghost_name[0]){
                case 'b':
                    strcpy(nom_doc, "ghost1_2.bmp");
                    break;
                case 'p':
                    strcpy(nom_doc, "ghost2_2.bmp");
                    break;
                case 'i':
                    strcpy(nom_doc, "ghost3_2.bmp");
                    break;
                case 'c':
                    strcpy(nom_doc, "ghost4_2.bmp");
                    break;
                default :
                    break;
                }
                break;
        case 'd':
            switch(ghost_name[0]){
                case 'b':
                    strcpy(nom_doc, "ghost1_0.bmp");
                    break;
                case 'p':
                    strcpy(nom_doc, "ghost2_0.bmp");
                    break;
                case 'i':
                    strcpy(nom_doc, "ghost3_0.bmp");
                    break;
                case 'c':
                    strcpy(nom_doc, "ghost4_0.bmp");
                    break;
                default :
                    break;
                }
                break;
        default :
            break;
    }
    SDL_Texture* text_ghost = loadTexture(nom_doc,ren);
    renderTexture(text_ghost,ren,e_x,e_y,ghostsize,ghostsize);
    // char ghost[5] = "ghost";
    // int compteur;
    // for (int i = 0; ghost[i]!='\0'; i++){
    //     nom_doc[compteur] = ghost[i];
    //     compteur ++;
    // }
    // compteur ++;
    // nom_doc[compteur] = ghost_number;
    // compteur ++;
    // nom_doc[compteur] = '_';
    // compteur ++;
    // nom_doc[compteur] = pos;
    // char bmp[4] = ".bmp";
    // for (int j = 0; bmp[j]!='\0';j++){
    //     nom_doc[compteur] = bmp[j];
    //     compteur ++;
    // }
    // printf("%s , final \n",nom_doc);

    return ren;
}

SDL_Renderer* aff_vies(int lives, SDL_Renderer* ren,SDL_Texture* vie){
    for (int i = 0; i< lives; i++){
        renderTexture(vie,ren,i * taillecase,12 * taillecase,taillecase,taillecase);
    }
    return ren;
}
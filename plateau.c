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
};


void graphPlateau(SDL_Renderer* ren,plateau plat){
    SDL_Texture* gum = loadTexture("gum.bmp",ren);
    SDL_Texture* wall = loadTexture("wall.bmp",ren);
    SDL_Texture* biggum = loadTexture("bigGum.bmp",ren);
    SDL_Texture* cerise = loadTexture("cherry.bmp",ren);
    // SDL_Texture* pacman_d = loadTexture("pakuman_0.bmp",ren);
    // SDL_Texture* pacman_h = loadTexture("pakuman_1.bmp",ren);
    
    for ( int i = 0; i<plat.haut; i++){
        for ( int j = 0; j<plat.large; j++){
            switch(plat.tab[i][j]){
                case 0:

                    break;
                case 1:
                    renderTexture(wall,ren,j*30,i*30,30,30);
                    break;
                case 2:
                    renderTexture(gum,ren,j*30,i*30,30,30);
                    break;
                case 3:
                    renderTexture(biggum,ren,j*30,i*30,30,30);
                    break;
                case 4:
                    renderTexture(cerise,ren,j*30,i*30,30,30);
                    break;
                // case 5:
                //     renderTexture(pacman_d,ren,j*30,i*30,30,30);
                //     break;
                default:
                    break;
                }

        }
    }
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    updateDisplay(ren);
    SDL_Delay(3000);
}

int is_collision_e2b(int e_x, int e_y, plateau map){ // test collision entitée to block
    for (int i = 0; i< map.large; i++){
        for (int j = 0; j< map.haut; j++){
            if (map.tab[i][j] == 1){
                if (e_x > (j*taillecase) && e_x < (j+1)*taillecase){
                    if (e_y > (i*taillecase) && e_y < (i+1)*taillecase){
                        return 1;
                    } 
                }
            }
        }
    }
    return 0;
}

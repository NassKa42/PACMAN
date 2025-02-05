/*
MAP : 
0 : vide
1:mur
2:gum
3:mega gum
4:fruit
5:pacman
6:fantome rouge
7:fantome orange
8:fantome bleu
9:fantome rose
*/
#include "fantome.h"
#include "plateau.h"
#include "ressources.h"
#include "pakuman.h"
#include "jeu.h"

int main(int argc, char** argv){
    int score = 0;  
    // caracfantome(inky);
    // caracfantome(blinky);
    // caracfantome(pinky);
    // caracfantome(clyde);
    char map[21][19]={
{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'},
{'w','v','v','v','v','v','v','v','v','w','v','v','v','v','v','v','v','v','w'},
{'w','v','w','w','v','w','w','w','v','w','v','w','w','w','v','w','w','v','w'},
{'w','v','w','w','v','w','w','w','v','w','v','w','w','w','v','w','w','v','w'},
{'w','v','v','v','v','v','v','v','v','v','v','v','v','v','v','v','v','v','w'},
{'w','v','w','w','v','w','v','w','w','w','w','w','v','w','v','w','w','v','w'},
{'w','v','v','v','v','w','v','v','v','w','v','v','v','w','v','v','v','v','w'},
{'w','w','w','w','v','w','w','w','v','w','v','w','w','w','v','w','w','w','w'},
{'w','w','w','w','v','w','v','v','v','v','v','v','v','w','v','w','w','w','w'},
{'w','w','w','w','v','w','v','w','w','v','w','w','v','w','v','w','w','w','w'},
{'w','w','w','w','v','v','v','w','v','v','v','w','v','v','v','w','w','w','w'},
{'w','w','w','w','v','w','v','w','w','w','w','w','v','w','v','w','w','w','w'},
{'w','w','w','w','v','w','v','v','v','v','v','v','v','w','v','w','w','w','w'},
{'w','w','w','w','v','w','w','w','v','w','v','w','w','w','v','w','w','w','w'},
{'w','v','v','v','v','w','v','v','v','w','v','v','v','w','v','v','v','v','w'},
{'w','v','w','w','v','w','v','w','w','w','w','w','v','w','v','w','w','v','w'},
{'w','v','v','v','v','v','v','v','v','v','v','v','v','v','v','v','v','v','w'},
{'w','v','w','w','v','w','w','w','v','w','v','w','w','w','v','w','w','m','w'},
{'w','v','w','w','v','w','w','w','v','w','v','w','w','w','v','w','w','v','w'},
{'w','v','v','v','v','v','v','v','v','w','v','v','v','g','g','g','g','g','w'},
{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'}};


    plateau t = initPlateau(map);
    //t.tab[start_y][start_x] = 4;
    initSDL();
    initTTF();
    SDL_Window * win = SDL_CreateWindow("My video game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 19*30, 21*30, SDL_WINDOW_RESIZABLE);
    SDL_Renderer * ren = createRenderer(win);
    SDL_Color Black ={0,0,0,0};
    SDL_Color White ={255,255,255,0};
    TTF_Font* font = createFont("./DejaVuSans-Bold.ttf", 20);
    graphPlateau(ren,t);
    updateDisplay(ren);
    int lives = 3;
    int finitopipo = 1;
    int hurt;
    char dir;
    char tempo;
    char secondaire;
    while (lives >0){
        hurt = 0;
        fantome inky = initFantome(10,10, "inky");
        fantome blinky = initFantome(6,12, "blinky");
        fantome pinky = initFantome(9,10, "pinky");
        fantome clyde = initFantome(8,10, "clyde");
        Player pacman = initPlayer("Perso1");
        dir = start(t, ren);
        while (finitopipo ==1 && hurt == 0){   
            tempo = processKeyboard();
            if (tempo != ' ') {
                if (PeutBouger(tempo, pacman, t)==1){
                    dir=tempo;
                }
                else {
                    secondaire=tempo;
                };
            }
            else{
                if(secondaire != ' ' && PeutBouger(secondaire, pacman, t)==1){
                    dir = secondaire;
                    secondaire=' ';
                };
            };
            // printf("%d \n", PeutBouger(dir, pacman, t));
            pacman = BougerAvecTest(pacman, dir, t);
            blinky = deplacement_fantome_proche(pacman, blinky, t);
            SDL_RenderClear(ren);
            score = score + score_gum(pacman, t);
            t = remove_gum(pacman.x,pacman.y,t);
            ren = graphPlateau(ren, t);
            ren = aff_pac(pacman.x, pacman.y, ren, dir);
            ren = aff_fantome(blinky.posX,blinky.posY,ren,dir,blinky.name);
            ren = aff_fantome(inky.posX,inky.posY,ren,dir,inky.name);
            ren = aff_fantome(pinky.posX,pinky.posY,ren,dir,pinky.name);
            ren = aff_fantome(clyde.posX,clyde.posY,ren,dir,clyde.name);
            char text[14];
            sprintf(text,"Score : %d",score);
            printText(0,9 * taillecase,text,4* taillecase,2 * taillecase,font,White,ren);
            if (is_collision_p2g(blinky, pacman) == 1){
                lives --;
                hurt = 1;
            }
            updateDisplay(ren);
            if (score == 100){
                finitopipo = 0;
            }
            SDL_Delay(5);
        }
    }
    
    SDL_Delay(1000);
    QuitSDL(win, ren);
    return 0;
}


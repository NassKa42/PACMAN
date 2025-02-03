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

int main(int argc, char** argv){
    fantome blinky = initFantome();
    fantome inky = initFantome();
    fantome pinky = initFantome();
    fantome clide = initFantome();
    Player pacman = initPlayer("Perso1");
    char map[21][19]={
{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'},
{'w','g','g','g','g','g','g','g','g','w','g','g','g','g','g','g','g','g','w'},
{'w','g','w','w','g','w','w','w','g','w','g','w','w','w','g','w','w','g','w'},
{'w','m','w','w','g','w','w','w','g','w','g','w','w','w','g','w','w','m','w'},
{'w','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','w'},
{'w','g','w','w','g','w','g','w','w','w','w','w','g','w','g','w','w','g','w'},
{'w','g','g','g','g','w','m','g','g','w','g','g','m','w','g','g','g','g','w'},
{'w','w','w','w','g','w','w','w','g','w','g','w','w','w','g','w','w','w','w'},
{'w','w','w','w','g','w','v','v','v','v','v','v','v','w','g','w','w','w','w'},
{'w','w','w','w','g','w','v','w','w','v','w','w','v','w','g','w','w','w','w'},
{'w','w','w','w','g','g','v','w','v','v','v','w','v','g','g','w','w','w','w'},
{'w','w','w','w','g','w','v','w','w','w','w','w','v','w','g','w','w','w','w'},
{'w','w','w','w','g','w','v','v','v','v','v','v','v','w','g','w','w','w','w'},
{'w','w','w','w','g','w','w','w','g','w','g','w','w','w','g','w','w','w','w'},
{'w','g','g','g','g','w','m','g','g','w','g','g','m','w','g','g','g','g','w'},
{'w','g','w','w','g','w','g','w','w','w','w','w','g','w','g','w','w','g','w'},
{'w','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','w'},
{'w','m','w','w','g','w','w','w','g','w','g','w','w','w','g','w','w','m','w'},
{'w','g','w','w','g','w','w','w','g','w','g','w','w','w','g','w','w','g','w'},
{'w','g','g','g','g','g','g','g','g','w','g','g','g','g','g','g','g','g','w'},
{'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'}};
    
    plateau t = initPlateau(map);
    //t.tab[start_y][start_x] = 4;
    initSDL();
    initTTF();
    SDL_Window * win = SDL_CreateWindow("My video game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 19*30, 21*30, SDL_WINDOW_RESIZABLE);
    SDL_Renderer * ren = createRenderer(win);
    TTF_Font* font = createFont("./DejaVuSans-Bold.ttf", 20);
    graphPlateau(ren,t);
    int finitopipo = 1;
    char dir = 'd';
    char tempo;
    while (finitopipo ==1)
    {   
        tempo = processKeyboard();
        if (tempo != ' ')
        {
            dir = tempo;
        }
        ;
        BougerAvecTest(pacman, dir, t);
        SDL_RenderClear(ren);
        graphPlateau(ren, t);
        aff_pac(pacman.x, pacman.y, ren, dir);
        printf("i was here");
    }

}


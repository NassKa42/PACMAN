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


int main(int argc, char** argv){
    fantome blinky = initFantome();
    fantome inky = initFantome();
    fantome pinky = initFantome();
    fantome clide = initFantome();
    char map[21][19]={
{'m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m'},
{'m','g','g','g','g','g','g','g','g','m','g','g','g','g','g','g','g','g','m'},
{'m','g','m','m','g','m','m','m','g','m','g','m','m','m','g','m','m','g','m'},
{'m','h','m','m','g','m','m','m','g','m','g','m','m','m','g','m','m','h','m'},
{'m','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','m'},
{'m','g','m','m','g','m','g','m','m','m','m','m','g','m','g','m','m','g','m'},
{'m','g','g','g','g','m','h','g','g','m','g','g','h','m','g','g','g','g','m'},
{'m','m','m','m','g','m','m','m','g','m','g','m','m','m','g','m','m','m','m'},
{'m','m','m','m','g','m','v','v','v','v','v','v','v','m','g','m','m','m','m'},
{'m','m','m','m','g','m','v','m','m','v','m','m','v','m','g','m','m','m','m'},
{'m','m','m','m','g','g','v','m','v','v','v','m','v','g','g','m','m','m','m'},
{'m','m','m','m','g','m','v','m','m','m','m','m','v','m','g','m','m','m','m'},
{'m','m','m','m','g','m','v','v','v','v','v','v','v','m','g','m','m','m','m'},
{'m','m','m','m','g','m','m','m','g','m','g','m','m','m','g','m','m','m','m'},
{'m','g','g','g','g','m','h','g','g','m','g','g','h','m','g','g','g','g','m'},
{'m','g','m','m','g','m','g','m','m','m','m','m','g','m','g','m','m','g','m'},
{'m','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','m'},
{'m','h','m','m','g','m','m','m','g','m','g','m','m','m','g','m','m','h','m'},
{'m','g','m','m','g','m','m','m','g','m','g','m','m','m','g','m','m','g','m'},
{'m','g','g','g','g','g','g','g','g','m','g','g','g','g','g','g','g','g','m'},
{'m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m','m'}};
    
    plateau t = initPlateau(map);
    t.tab[start_y][start_x] = 5;
    initSDL();
    initTTF();
    SDL_Window * win = SDL_CreateWindow("My video game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 19*30, 21*30, SDL_WINDOW_RESIZABLE);
    SDL_Renderer * ren = createRenderer(win);
    TTF_Font* font = createFont("./DejaVuSans-Bold.ttf", 20);
    graphPlateau(ren,t);
}
    //abc   


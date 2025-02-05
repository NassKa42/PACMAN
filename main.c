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

    fantome inky = initFantome(10,10, "inky");
    fantome blinky = initFantome(6,12, "blinky");
    fantome pinky = initFantome(9,10, "pinky");
    fantome clyde = initFantome(8,10, "clyde");
    Player pacman = initPlayer("Perso1");
    plateau t = initPlateau(map);
    //t.tab[start_y][start_x] = 4;
    initSDL();
    initTTF();
    SDL_Color Red ={255,0,0,0};
    SDL_Color White ={255,255,255,0};
    SDL_Window * win = SDL_CreateWindow("My video game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 19*30, 21*30, SDL_WINDOW_RESIZABLE);
    SDL_Renderer * ren = createRenderer(win);
    SDL_Texture* texture_pac_0 = loadTexture("pakuman_0.bmp",ren);
    SDL_Texture* texture_pac_1 = loadTexture("pakuman_1.bmp",ren);
    SDL_Texture* texture_pac_2 = loadTexture("pakuman_2.bmp",ren);
    SDL_Texture* texture_pac_3 = loadTexture("pakuman_3.bmp",ren);
    SDL_Texture* texture_pac_5 = loadTexture("pakuman_5.bmp",ren);
    SDL_Texture* gum = loadTexture("gum.bmp",ren);
    SDL_Texture* wall = loadTexture("wall.bmp",ren);
    SDL_Texture* biggum = loadTexture("bigGum.bmp",ren);
    SDL_Texture* cerise = loadTexture("cherry.bmp",ren);
    SDL_Color Black ={0,0,0,0};
    TTF_Font* font = createFont("./DejaVuSans-Bold.ttf", 20);
    graphPlateau(ren,t, gum, wall, biggum, cerise);
    updateDisplay(ren);
    int lives = 3;
    int finitopipo = 1;
    int hurt = 0;
    char dir;
    char tempo;
    int niv = 1;
    char secondaire;
    int compteurframes=0;
    int etapeanimation=0;
    int big_gum_on =0;
    int debut_gum = 0;
    int duree_gum = 500;
    int score;
    while (lives >0){
        dir = start(t, ren, font, Red, gum, wall, biggum, cerise);
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
            if(compteurframes%10 == 0){
                switch(etapeanimation){
                    case 0:
                        etapeanimation=2;
                        break;
                    case 2:
                        etapeanimation=0;
                        break;
                    default:
                        break;
                };
            };
            compteurframes++;

            // printf("%d \n", PeutBouger(dir, pacman, t));
            pacman = BougerAvecTest(pacman, dir, t);
            blinky = deplacement_fantome_proche(pacman, blinky, t);
            SDL_RenderClear(ren);
            score = score_gum(pacman, t);
            if (score == 50){
                big_gum_on = 1;
                debut_gum = compteurframes;
            }
            pacman.score = pacman.score + score;
            t = remove_gum(pacman.x,pacman.y,t);
            ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
            ren = aff_pac(pacman.x, pacman.y, ren, dir, texture_pac_0, texture_pac_1, texture_pac_2, texture_pac_3,texture_pac_5,etapeanimation);
            ren = aff_fantome(blinky.posX,blinky.posY,ren,dir,blinky.name);
            ren = aff_fantome(inky.posX,inky.posY,ren,dir,inky.name);
            ren = aff_fantome(pinky.posX,pinky.posY,ren,dir,pinky.name);
            ren = aff_fantome(clyde.posX,clyde.posY,ren,dir,clyde.name);
            ren = aff_vies(lives ,ren);
            char text[16];
            sprintf(text,"Score : %d",pacman.score);
            printText(0,9 * taillecase,text,4* taillecase,2 * taillecase,font,White,ren);
            if (is_collision_p2g(blinky, pacman) == 1){
                
                if (big_gum_on == 0){
                    hurt = 1;
                    lives --;
                }
                
            }
            updateDisplay(ren);
            if (pacman.score == 100 * niv){
                finitopipo = 0;
            }
            if (compteurframes - duree_gum > debut_gum){
                big_gum_on = 0; //fin big gum
            }
            SDL_Delay(16- niv);
        }
        if (hurt == 1){
            perte_vie(ren, lives, pacman,t, gum, wall, biggum, cerise,texture_pac_0,texture_pac_5);
            hurt = 0;
        } else if (finitopipo == 0){
            finitopipo = 1;
            niv ++;
            niveau_gagne(ren,pacman.score,pacman,t, font, White, gum, wall, biggum, cerise,texture_pac_0,texture_pac_2);
            t = initPlateau(map);
            SDL_RenderClear(ren);
            
        }
        inky = reset_fantome(inky,10,10);
        blinky = reset_fantome(blinky,6,12);
        pinky = reset_fantome(pinky,9,10);
        clyde = reset_fantome(clyde,8,10);
        pacman = reset_player(pacman);
    }
    perte_partie(ren, pacman.score, t, font, White, Red, gum, wall, biggum, cerise);
    SDL_Delay(1000);
    QuitSDL(win, ren);
    return 0;
}


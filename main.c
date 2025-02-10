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
    musique("calm1.wav", 0);
    // caracfantome(inky);
    // caracfantome(blinky);
    // caracfantome(pinky);
    // caracfantome(clyde);
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

    fantome inky = initFantome(10,10, "inky");
    // fantome blinky = initFantome(1,1, "blinky");
    fantome blinky = initFantome(9,9, "blinky");
    fantome pinky = initFantome(9,10, "pinky"); //9 10
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
    SDL_Texture* texture_pac_10 = loadTexture("pakuman_10.bmp",ren);
    SDL_Texture* texture_pac_11 = loadTexture("pakuman_11.bmp",ren);
    SDL_Texture* texture_pac_12 = loadTexture("pakuman_12.bmp",ren);
    SDL_Texture* texture_pac_13 = loadTexture("pakuman_13.bmp",ren);
    SDL_Texture* texture_pac_death_1 = loadTexture("pakuman_death_1.bmp",ren);
    SDL_Texture* texture_pac_death_2 = loadTexture("pakuman_death_2.bmp",ren);
    SDL_Texture* texture_pac_death_3 = loadTexture("pakuman_death_3.bmp",ren);
    SDL_Texture* texture_pac_death_4 = loadTexture("pakuman_death_4.bmp",ren);
    SDL_Texture* texture_pac_death_5 = loadTexture("pakuman_death_5.bmp",ren);
    SDL_Texture* texture_pac_death_6 = loadTexture("pakuman_death_6.bmp",ren);
    SDL_Texture* texture_pac_death_7 = loadTexture("pakuman_death_7.bmp",ren);
    SDL_Texture* texture_pac_death_8 = loadTexture("pakuman_death_8.bmp",ren);
    SDL_Texture* texture_pac_death_9 = loadTexture("pakuman_death_9.bmp",ren);
    SDL_Texture* texture_pac_death_10 = loadTexture("pakuman_death_10.bmp",ren);
    SDL_Texture* texture_pac_transparent = loadTexture("pakuman_transparent.bmp",ren);
    SDL_Texture* gum = loadTexture("gum.bmp",ren);
    SDL_Texture* wall = loadTexture("wall.bmp",ren);
    SDL_Texture* biggum = loadTexture("bigGum.bmp",ren);
    SDL_Texture* cerise = loadTexture("cherry.bmp",ren);
    SDL_Color Black ={0,0,0,0};
    TTF_Font* font = createFont("./DejaVuSans-Bold.ttf", 20);
    graphPlateau(ren,t, gum, wall, biggum, cerise);
    updateDisplay(ren);
    char dir;
    char tempo;
    char secondaire;
    char trash;
    int score_niv = calcul_score(t);
    int score_fruits = 0;
    int lives = 3;
    int finitopipo = 1;
    int hurt = 0;
    int niv = 1;
    int compteurframes=0;
    int etapeanimation=0;
    int big_gum_on =0;
    int debut_gum;
    int duree_gum = 500;
    int score = 0;
    int score_fantomes = 0;
    int fruit_spawned = 0;
    int entraindouvrirlabouche=0;
    while (lives >0){
        debut_gum = 200000000;
        big_gum_on = 0;
        secondaire = ' ';
        dir = ' ';
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
                if(secondaire != ' ' && PeutBouger(secondaire, pacman, t)==1 && (dir=='h' && secondaire!='b' || dir=='b' && secondaire!='h' || dir=='g' && secondaire!='d' || dir=='d' && secondaire!='g')){
                    dir = secondaire;
                    secondaire=' ';
                };
            };

            if(compteurframes%5 == 0){
                switch(etapeanimation){
                    case 0:
                        etapeanimation=1;
                        entraindouvrirlabouche=1;
                        break;
                    case 1:
                        if (entraindouvrirlabouche==1){
                            etapeanimation=2;
                        }
                        else {
                            etapeanimation=0;
                        };
                        break;
                    case 2:
                        etapeanimation=1;
                        entraindouvrirlabouche=0;
                        break;
                    default:
                        break;
                };
            };

            compteurframes++;

            // printf("%d \n", PeutBouger(dir, pacman, t));
            pacman = BougerAvecTest(pacman, dir, t);
            blinky = deplacement_fantome_proche_BFS(pacman, blinky, t);
            pinky = deplacement_fantome_proche_continue(pacman, pinky, t);
            inky = deplacement_fantome_proche_continue(pacman, inky, t);
            clyde = deplacement_fantome_rng_intersection(clyde, t);
            SDL_RenderClear(ren);
            score = score_gum(pacman, t);
            t = remove_gum(pacman.x,pacman.y,t);
            if (score == 50){
                big_gum_on = 1;
                debut_gum = compteurframes;
            }
            pacman.score = pacman.score + score;
            ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
            
            ren = aff_pac(pacman.x, pacman.y, ren, dir, texture_pac_0, texture_pac_1, texture_pac_2, texture_pac_3,texture_pac_10, texture_pac_11, texture_pac_12, texture_pac_13, texture_pac_5,etapeanimation);            
            ren = aff_fantome(blinky.posX,blinky.posY,ren,blinky.dir,blinky.name, big_gum_on);
            ren = aff_fantome(inky.posX,inky.posY,ren,inky.dir,inky.name,big_gum_on);
            ren = aff_fantome(pinky.posX,pinky.posY,ren,pinky.dir,pinky.name,big_gum_on);
            ren = aff_fantome(clyde.posX,clyde.posY,ren,clyde.dir,clyde.name,big_gum_on);
            ren = aff_vies(lives ,ren,texture_pac_transparent);
            aff_score(pacman.score, ren, font, White);
            if (is_collision_p2g(blinky, pacman) == 1){
                if (big_gum_on == 0){
                    hurt = 1;
                    lives --;
                } else {
                    blinky = reset_fantome(blinky,9,10);
                    score_fantomes = score_fantomes + 200;
                    pacman.score = pacman.score+200;
                }
            } else
            if (is_collision_p2g(inky, pacman) == 1){
                if (big_gum_on == 0){
                    hurt = 1;
                    lives --;
                } else {
                    inky = reset_fantome(inky,9,10);
                    score_fantomes = score_fantomes + 200;
                    pacman.score = pacman.score+200;
                }
            } else
            if (is_collision_p2g(pinky, pacman) == 1){
                if (big_gum_on == 0){
                    hurt = 1;
                    lives --;
                } else {
                    pinky = reset_fantome(pinky,9,10);
                    score_fantomes = score_fantomes + 200;
                    pacman.score = pacman.score+200;
                }
            } else
            if (is_collision_p2g(clyde, pacman) == 1){
                if (big_gum_on == 0){
                    hurt = 1;
                    lives --;
                } else {
                    clyde = reset_fantome(clyde,9,10);
                    score_fantomes = score_fantomes + 200;
                    pacman.score = pacman.score+200;
                }
            }
            updateDisplay(ren);
            if (pacman.score == (score_niv * niv) + score_fruits + score_fantomes){
                finitopipo = 0;
            }
            if (compteurframes - duree_gum > debut_gum - 100){
                if ((compteurframes/10)%2 ==0){
                    big_gum_on = 2;
                } else{
                    big_gum_on = 1;
                }
            }
            if (compteurframes - duree_gum > debut_gum){
                big_gum_on = 0; //fin big gum
            }
            if (compteurframes == 300 && fruit_spawned == 0){
                t.tab[start_y][start_x] = 4;
                score_fruits = score_fruits + 100;
                fruit_spawned = 1;
            }
            SDL_Delay(16- niv);
        }
        if (hurt == 1){
            if (t.tab[start_y][start_x] == 4){
                t.tab[start_y][start_x] = 0;
                score_fruits = score_fruits -100;    
            }
            perte_vie(ren, lives, pacman,t, gum, wall, biggum, cerise,texture_pac_death_1,texture_pac_death_2,texture_pac_death_3,texture_pac_death_4,texture_pac_death_5,texture_pac_death_6,texture_pac_death_7,texture_pac_death_8,texture_pac_death_9,texture_pac_death_10,texture_pac_transparent);
            hurt = 0;
            trash = processKeyboard();
            // SDL_Delay(1000);
            // musique("calm1.wav", 1);
            // musique("hit3.wav",0);
            // SDL_Delay(1000);
            // musique("hit3", 1);
            // musique("calm1.wav", 0);
        } else if (finitopipo == 0){
            finitopipo = 1;
            niv ++;
            niveau_gagne(ren,pacman.score,pacman,t, font, White, gum, wall, biggum, cerise,texture_pac_0,texture_pac_2);
            t = initPlateau(map);
            SDL_RenderClear(ren);
            trash = processKeyboard();
            fruit_spawned = 0;
        }
        inky = reset_fantome(inky,10,10);
        blinky = reset_fantome(blinky,9,9);
        pinky = reset_fantome(pinky,9,10);
        clyde = reset_fantome(clyde,8,10);
        pacman = reset_player(pacman);
        compteurframes = 0;
    }
    perte_partie(ren, pacman.score, t, font, White, Red, gum, wall, biggum, cerise);
    SDL_Delay(1000);
    musique("calm1.wav", 1);
    
    QuitSDL(win, ren);
    return 0;
}


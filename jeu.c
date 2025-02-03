#include "jeu.h"
#include "plateau.h"


char start(plateau t){
    char c=' ';
        while(c == ' '){
        c = processKeyboard();
        }
        SDL_Color Red ={255,0,0,0};
        printText(((taillecase*t.large)/2)-100,((taillecase*t.haut)/2)-40,"Tu as Gagne",200,80,font,Red, ren);
    return c
}
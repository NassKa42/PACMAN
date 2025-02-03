#include "jeu.h"
#include "plateau.h"


char start(plateau t, SDL_Renderer* ren){
    char c=' ';
    SDL_Color Red ={255,0,0,0};
    TTF_Font* font = createFont("./DejaVuSans-Bold.ttf", 20);
    printText(((taillecase*t.large)/2)-200,((taillecase*t.haut)/2)-40,"Appuyer pour demarrer",400,80,font,Red, ren);
    updateDisplay(ren);
    
        while(c == ' '){
        c = processKeyboard();
        }
        
        
    return c;
}
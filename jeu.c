#include "jeu.h"


char start(plateau t, SDL_Renderer* ren, TTF_Font* font, SDL_Color Red,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise){
    char c=' ';
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    printText(((taillecase*t.large)/2)-200,((taillecase*t.haut)/2)-40,"Appuyer pour demarrer",400,80,font,Red, ren);
    updateDisplay(ren);
    
        while(c == ' '){
        c = processKeyboard();
        }
        
        
    return c;
}

void perte_vie(SDL_Renderer* ren, int lives, Player pacman, plateau t,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise, SDL_Texture* ouvert, SDL_Texture* ferme, SDL_Texture* texture_pac_transparent){
    for (int i = 0; i<2; i++){
        SDL_RenderClear(ren);
        ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
        ren = aff_vies(lives +1 ,ren,texture_pac_transparent);
        renderTexture(ouvert,ren,pacman.x,pacman.y,pacsize,pacsize);
        updateDisplay(ren);
        SDL_Delay(500);
        SDL_RenderClear(ren);
        ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
        ren = aff_vies(lives ,ren,texture_pac_transparent);
        renderTexture(ferme,ren,pacman.x,pacman.y,pacsize,pacsize);
        updateDisplay(ren);
        SDL_Delay(500);
    }   
}

void niveau_gagne(SDL_Renderer* ren , int score , Player pacman, plateau t, TTF_Font* font, SDL_Color White,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise,SDL_Texture* droite, SDL_Texture* gauche){
    SDL_Delay(500);
    char text[16]; 
    sprintf(text,"Score : %d",score);
    for (int i = 0; i<2; i++){
        SDL_RenderClear(ren);
        ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
        printText(((taillecase*t.large)/2)-200,((taillecase*t.haut)/2)-40,text,400,80,font,White, ren);
        renderTexture(gauche,ren,pacman.x,pacman.y,pacsize,pacsize);
        updateDisplay(ren);
        SDL_Delay(500);
        SDL_RenderClear(ren);
        ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
        printText(((taillecase*t.large)/2)-150,((taillecase*t.haut)/2)-30,text,300,60,font,White, ren);
        renderTexture(droite,ren,pacman.x,pacman.y,pacsize,pacsize);
        updateDisplay(ren);
        SDL_Delay(500);
    }   
}

void perte_partie(SDL_Renderer* ren, int score, plateau t,TTF_Font* font, SDL_Color White, SDL_Color Red,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise){
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    char text[20]; 
    sprintf(text,"Score final : %d",score);
    for (int i = 0; i<2; i++){
        SDL_RenderClear(ren);
        ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
        printText(((taillecase*t.large)/2)-200,((taillecase*t.haut)/2)-40,"Vous avez Perdu !",400,80,font,Red, ren);
        updateDisplay(ren);
        SDL_Delay(500);
        SDL_RenderClear(ren);
        ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
        printText(((taillecase*t.large)/2)-200,((taillecase*t.haut)/2)-40,"Vous avez Perdu !",400,80,font,Red, ren);
        printText(((taillecase*t.large)/2)-150,((taillecase*t.haut)/2)-30 +100,text,300,60,font,White, ren);
        updateDisplay(ren);
        SDL_Delay(500);
    }   
}
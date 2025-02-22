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

void perte_vie(SDL_Renderer* ren, int lives, Player pacman, plateau t,SDL_Texture* gum,SDL_Texture* wall , SDL_Texture* biggum, SDL_Texture* cerise, SDL_Texture* mort1, SDL_Texture* mort2, SDL_Texture* mort3, SDL_Texture* mort4, SDL_Texture* mort5, SDL_Texture* mort6, SDL_Texture* mort7, SDL_Texture* mort8, SDL_Texture* mort9, SDL_Texture* mort10, SDL_Texture* texture_pac_transparent){
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives +1 ,ren,texture_pac_transparent);
    renderTexture(mort1,ren,pacman.x,pacman.y,pacsize,pacsize);
    updateDisplay(ren);
    SDL_Delay(500);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort1,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort2,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort3,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort4,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort5,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort6,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort7,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort8,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort9,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    renderTexture(mort10,ren,pacman.x,pacman.y,pacsize,pacsize);
    SDL_Delay(50);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    ren = graphPlateau(ren, t, gum, wall, biggum, cerise);
    ren = aff_vies(lives ,ren,texture_pac_transparent);

    SDL_Delay(500);
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

int musique(char nom_doc[10], int fin){
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        //printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    if (fin ==1){
        SDL_FreeWAV(wavBuffer);
        SDL_CloseAudio();
        return 0;
    }
    if (SDL_LoadWAV(nom_doc, &wavSpec, &wavBuffer, &wavLength) == NULL) {
        //printf("Error loading WAV file: %s\n", SDL_GetError());
        return -1;
    }
    if (SDL_OpenAudio(&wavSpec, NULL) < 0) {
        // printf("SDL_OpenAudio failed: %s\n", SDL_GetError());
        return -1;
    }
    SDL_PauseAudio(0);
    SDL_QueueAudio(1, wavBuffer, wavLength);
    
}

char start_choix(plateau t, SDL_Renderer* ren, TTF_Font* font, SDL_Color Red){
    char c=' ';
    printText(((taillecase*t.large)/2)-250,((taillecase*t.haut)/2)-40,"Fleche de droite pour le Pacman",500,80,font,Red, ren);
    printText(((taillecase*t.large)/2)-250,((taillecase*t.haut)/2)+50,"Fleche de gauche pour le Minecraft",500,80,font,Red, ren);
    updateDisplay(ren);
    SDL_RenderClear(ren);
    
        while(c == ' ' || c == 'h' || c == 'b'){
        c = processKeyboard();
        }
        
        
    return c;
}
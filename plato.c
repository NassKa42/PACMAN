#include "plato.h"



void graphPlateau(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < HAUT; i++)
    {
        SDL_RenderDrawLine(renderer, 0, i*TAILLE_CASE, TAILLE_CASE*LARG, i*TAILLE_CASE);
    }
    for (int j = 0; j < LARG; j++)
    {
        SDL_RenderDrawLine(renderer,  j*TAILLE_CASE,0,  j*TAILLE_CASE,TAILLE_CASE*HAUT);
    };
};
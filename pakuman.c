#include <stdio.h>
#include <SDL2/SDL.h>
#include "pakuman.h"
#include <string.h>
#include "ressources.h"
#include "plateau.h"



Player initPlayer(char* name){
    Player personnage;
    personnage.x = start_x*taillecase;
    personnage.y = start_y*taillecase;
    personnage.orientation = 'd';
    personnage.score = 0;
    return personnage;
};

Player BougerAvecTest(Player pakuman,char direction, plateau tableau){
    int PosTableauX=pakuman.x/taillecase;
    int PosTableauY=pakuman.y/taillecase;
    int PosTableauXOpp=(pakuman.x+pacsize-1)/taillecase;
    int PosTableauYOpp=(pakuman.y+pacsize-1)/taillecase;
    int PosDansCaseX=pakuman.x%taillecase;
    int PosDansCaseY=pakuman.x%taillecase;
    switch (direction){
        case 'g' :
            if (tableau.tab[PosTableauY][PosTableauX-1]!=1 && tableau.tab[PosTableauYOpp][PosTableauXOpp-1]!=1 && PosDansCaseX!=0){
                pakuman.x= pakuman.x-5;
            };
            break;
        case 'd':
            if (tableau.tab[PosTableauY][PosTableauX+1]!=1 && tableau.tab[PosTableauYOpp][PosTableauXOpp+1]!=1 && PosDansCaseX!=0){
                pakuman.x= pakuman.x+5;
            };
            break;
        case 'h':
            if (tableau.tab[PosTableauY-1][PosTableauX]!=1 && tableau.tab[PosTableauYOpp-1][PosTableauXOpp]!=1 && PosDansCaseY!=0){
                pakuman.y= pakuman.y-5;
            };
            break;
        case 'b':
            if (tableau.tab[PosTableauY+1][PosTableauX]!=1 && tableau.tab[PosTableauYOpp+1][PosTableauXOpp]!=1 && PosDansCaseY!=0){
                pakuman.y= pakuman.y+5;
            };
            break;
    };
return pakuman;
};


// int CollisionAvecFantome(Player pakuman, fantome ghost){

// }
// char regarderVers(){
//     while (direction=' '){
//         direction=processKeyboard();
//     };
//     return direction
// ;}
/*
int bouger(char direction, Player pakuman, plateau tabl){
    if (direction='d') {
        if (plateau[pakuman.x][pakuman.y+1]!=1){
            pakuman.y= pakuman.y+5
        ;}
    ;};
    if (direction='g') {
        if (plateau[pakuman.x][pakuman.y-1]!=1){
            pakuman.y= pakuman.y-5
        ;}
    ;};
    if (direction='h') {
        if (plateau[pakuman.x-1][pakuman.y]!=1){
            pakuman.x= pakuman.x-5
        ;}
    ;};
    if (direction='b') {
        if (plateau[pakuman.x+1][pakuman.y+1]!=1){
            pakuman.x= pakuman.x+5
        ;}
    ;}

}

Player bougerdirect(char direction, Player name){
    switch (direction)
    {
    case 'd':
        name.y= name.x+5;
        break;
    case 'g':
        name.y= name.x-5;
        break;
    case 'h':
        name.x= name.y-5;
        break;
    case 'b':
        name.x= name.y+5;
        break;
    default:
        break;
    }
    return name;
}*/
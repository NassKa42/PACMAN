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
    int PosDansCaseY=pakuman.y%taillecase;
    int PosOppDansCaseX=(pakuman.x+pacsize-1)%taillecase;
    int PosOppDansCaseY=(pakuman.y+pacsize-1)%taillecase;
    switch (direction){
        case 'g' :
            if ( (tableau.tab[PosTableauY][PosTableauX]!=1 && PosDansCaseY==0 && tableau.tab[PosTableauY][(pakuman.x-1)/taillecase]!=1) || (tableau.tab[PosTableauY][PosTableauX-1]!=1 && tableau.tab[PosTableauYOpp][PosTableauXOpp-1]!=1 && PosDansCaseX!=0) ){
                pakuman.x= pakuman.x-5;
            };
            break;
        case 'd':
            if ( (tableau.tab[PosTableauY][PosTableauX+1]!=1 && PosDansCaseY==0 ) || (tableau.tab[PosTableauY][PosTableauX+1]!=1 && tableau.tab[PosTableauYOpp][PosTableauXOpp+1]!=1 && PosDansCaseX!=0) ){
                pakuman.x= pakuman.x+5;
            };
            break;
        case 'h':
            if ( (tableau.tab[PosTableauY][PosTableauX]!=1 && PosDansCaseX==0 && tableau.tab[(pakuman.y-1)/taillecase][PosTableauX]!=1 ) || (tableau.tab[PosTableauY-1][PosTableauX]!=1 && tableau.tab[PosTableauYOpp-1][PosTableauXOpp]!=1 && PosDansCaseY!=0) ){
                pakuman.y= pakuman.y-5;
            };
            break;
        case 'b':
            if ( (tableau.tab[PosTableauY+1][PosTableauX]!=1 && PosDansCaseX==0 ) || (tableau.tab[PosTableauY+1][PosTableauX]!=1 && tableau.tab[PosTableauYOpp+1][PosTableauXOpp]!=1 && PosDansCaseY!=0) ){
                pakuman.y= pakuman.y+5;
            };
            break;
    };
return pakuman;
};

int PeutBouger(char direction, Player pakuman, plateau tableau){
    int PosTableauX=pakuman.x/taillecase;
    int PosTableauY=pakuman.y/taillecase;
    int PosDansCaseX=pakuman.x%taillecase;
    int PosDansCaseY=pakuman.y%taillecase;
    int PosTableauXOpp=(pakuman.x+pacsize-1)/taillecase;
    int PosTableauYOpp=(pakuman.y+pacsize-1)/taillecase;
    int oui=0;
    switch (direction){
        case 'g' :
            if ( (tableau.tab[PosTableauY][PosTableauX]!=1 && PosDansCaseY==0 && tableau.tab[PosTableauY][(pakuman.x-1)/taillecase]!=1) || (tableau.tab[PosTableauY][PosTableauX-1]!=1 && tableau.tab[PosTableauYOpp][PosTableauXOpp-1]!=1 && PosDansCaseX!=0) ){
                oui=1;
            };
            break;
        case 'd':
            if ( (tableau.tab[PosTableauY][PosTableauX+1]!=1 && PosDansCaseY==0 ) || (tableau.tab[PosTableauY][PosTableauX+1]!=1 && tableau.tab[PosTableauYOpp][PosTableauXOpp+1]!=1 && PosDansCaseX!=0) ){
                oui=1;
            };
            break;
        case 'h':
            if ( (tableau.tab[PosTableauY][PosTableauX]!=1 && PosDansCaseX==0 && tableau.tab[(pakuman.y-1)/taillecase][PosTableauX]!=1 ) || (tableau.tab[PosTableauY-1][PosTableauX]!=1 && tableau.tab[PosTableauYOpp-1][PosTableauXOpp]!=1 && PosDansCaseY!=0) ){
                oui=1;
            };
            break;
        case 'b':
            if ( (tableau.tab[PosTableauY+1][PosTableauX]!=1 && PosDansCaseX==0 ) || (tableau.tab[PosTableauY+1][PosTableauX]!=1 && tableau.tab[PosTableauYOpp+1][PosTableauXOpp]!=1 && PosDansCaseY!=0) ){
                oui=1;
            };
            break;
    };
return oui;
};

Player BougerFinal(Player pakuman, char direction) {
    switch(direction){
        case 'g':
            pakuman.x= pakuman.x-5;
            break;
        case 'd':
            pakuman.x= pakuman.x+5;
            break;
        case 'b':
            pakuman.y= pakuman.y+5;
            break;
        case 'h':
            pakuman.y= pakuman.y-5;
            break;
    };
    return pakuman;
};
int score_gum(Player pacman, plateau t){
    int gum = is_collision_p2gmgc(pacman.x,pacman.y,t);
    switch(gum){
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 50;
        case 3:
            return 100;
        default:
            break;
    }
    return 0;
}

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
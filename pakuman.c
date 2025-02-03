#include <stdio.h>
#include <SDL2/SDL.h>
#include "pakuman.h"
#include <string.h>
#include "plato.h"



Player initPlayer(char* name){
    Player personnage;
    personnage.Pos_X = 0;
    personnage.Pos_Y = 0;
    personnage.orientation = 0;
    personnage.score = 0;
    return personnage;
};



// char regarderVers(){
//     while (direction=' '){
//         direction=processKeyboard();
//     };
//     return direction
// ;}

int bouger(char direction, Player pakuman){
    if (direction='d') {
        if (plateau[pakuman.Pos_X][pakuman.Pos_Y+1]!=1){
            pakuman.Pos_Y= pakuman.Pos_Y+5
        ;}
    ;};
    if (direction='g') {
        if (plateau[pakuman.Pos_X][pakuman.Pos_Y-1]!=1){
            pakuman.Pos_Y= pakuman.Pos_Y-5
        ;}
    ;};
    if (direction='h') {
        if (plateau[pakuman.Pos_X-1][pakuman.Pos_Y]!=1){
            pakuman.Pos_X= pakuman.Pos_X-5
        ;}
    ;};
    if (direction='b') {
        if (plateau[pakuman.Pos_X+1][pakuman.Pos_Y+1]!=1){
            pakuman.Pos_X= pakuman.Pos_X+5
        ;}
    ;}

}

Player bougerdirect(char direction, Player name){
    // if (direction='d') {
    //         name.Pos_Y= name.Pos_Y+5
    // ;};
    // if (direction='g') {
    //         name.Pos_Y= name.Pos_Y-5
    // ;};
    // if (direction='h') {
    //         name.Pos_X= name.Pos_X-5
    // ;};
    // if (direction='b') {
    //         name.Pos_X= name.Pos_X+5
    //         ;printf("azertyuio")
    // ;};
    switch (direction)
    {
    case 'd':
        name.Pos_Y= name.Pos_X+5;
        break;
    case 'g':
        name.Pos_Y= name.Pos_X-5;
        break;
    case 'h':
        name.Pos_X= name.Pos_Y-5;
        break;
    case 'b':
        name.Pos_X= name.Pos_Y+5;
        break;
    default:
        break;
    }
    return name;
}
//Mykell Spencer
//Student ID: U0000008054
//COP 4415.01FX
//Project 1: Irma Movement

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "IrmaMoves.h"

char **createMapBoard(void) {
    char **board = malloc(sizeof(char *) * 8); //allocating the memory for the board
    for (int i = 0; i < 8; i++) {
        board[i] = malloc(sizeof(char) * 8);
    }

    strncpy(board[0], "FF      ", 8);
    strncpy(board[1], " F      ", 8);
    strncpy(board[2], " FF     ", 8);
    strncpy(board[3], "  F     ", 8);
    strncpy(board[4], "  K     ", 8);
    strncpy(board[5], "C  B    ", 8);
    strncpy(board[6], " CC D   ", 8);
    strncpy(board[7], "  C  DD ", 8);
    return board;   //This function created every single coordinate in the 2D array 8x8 board with accurate placements of the letters
                    //It also saved a lot of space and time from having to create 64 lines of individual coordinates
};


int charToNum(char x_axis) { // Converting the letters of the axis to numbers to make it easier to predict Irma's changes later
    switch(x_axis) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        default:
            return 0;
    }
}


void printMapBoard (char **board) {
    int i;
    printf("========\n");
    for (i = 0; i < 8; i++){    //Creating the map board into the terminal, one row at a time
        printf("%.8s", board[i]);
        printf("\n");
    }
    printf("========\n");
};

char **destroyMapBoard(char **board) {
    for (int i = 0; i < 8; i++) {
        free(board[i]);
    }
    free(board); //Destroying the board if it fails
    return NULL;
};

char **predictIrmaChange(char *str, Move *irmaMove) {
    char **board = createMapBoard();

    parseNotationString(str, irmaMove);
    board[irmaMove->from_loc.row][charToNum(irmaMove->from_loc.col)] = 'I'; //Denoting the hurricane as I
    printMapBoard(board);

    irmaMove->current_loc.col = irmaMove->from_loc.col;
    irmaMove->current_loc.row = irmaMove->from_loc.row;

    //Moving horizontally and seeing if Irma is either on land or ocean
    if (charToNum(irmaMove->from_loc.col) > charToNum(irmaMove->to_loc.col)) {  //Moving to the right
        for(int i = 0; i < (charToNum(irmaMove->from_loc.col) - charToNum(irmaMove->to_loc.col)); i++) {
            if (isalpha(board[irmaMove->current_loc.row][charToNum(irmaMove->current_loc.col)-1])) {
                irmaMove->irma.ws -= 15;
                irmaMove->irma.wg -= 10;
                irmaMove->current_loc.col -= 1;
            } else {
                irmaMove->irma.ws += 10;
                irmaMove->irma.wg += 5;
                irmaMove->current_loc.col -= 1;
            }
        }
    } else if(charToNum(irmaMove->from_loc.col) < charToNum(irmaMove->to_loc.col)) {    //Moving to the left
        for(int i = 0; i < (charToNum(irmaMove->to_loc.col) - charToNum(irmaMove->from_loc.col)); i++) {
            if (isalpha(board[irmaMove->current_loc.row][charToNum(irmaMove->current_loc.col)+1])) {
                irmaMove->irma.ws -= 15;
                irmaMove->irma.wg -= 10;
                irmaMove->current_loc.col += 1;
            } else {
                irmaMove->irma.ws += 10;
                irmaMove->irma.wg += 5;
                irmaMove->current_loc.col += 1;
            }
        }
    }

    // Moving vertically and seeing if Irma is on land or the ocean
    if (irmaMove->from_loc.row > irmaMove->to_loc.row) {    //Moving down
        for (int i = 0; i < (irmaMove->from_loc.row - irmaMove->to_loc.row); i++) {
            if (isalpha(board[irmaMove->current_loc.row-1][charToNum(irmaMove->current_loc.col)])) {
                irmaMove->irma.ws -= 2;
                irmaMove->irma.wg -= 1;
                irmaMove->current_loc.row -= 1;
            } else {
                irmaMove->irma.ws += 6;
                irmaMove->irma.wg += 3;
                irmaMove->current_loc.row -= 1;
            }
        }
    } else if (irmaMove->from_loc.row < irmaMove->to_loc.row) { //Moving up
        for (int i = 0; i < (irmaMove->to_loc.row - irmaMove->from_loc.row); i++) {
            if (isalpha(board[irmaMove->current_loc.row+1][charToNum(irmaMove->current_loc.col)])) {
                irmaMove->irma.ws -= 2;
                irmaMove->irma.wg -= 1;
                irmaMove->current_loc.row += 1;
            } else {
                irmaMove->irma.ws += 6;
                irmaMove->irma.wg += 3;
                irmaMove->current_loc.row += 1;
            }
        }
    }
    board[irmaMove->from_loc.row][charToNum(irmaMove->from_loc.col)] = ' '; // Return the old character
    board[irmaMove->current_loc.row][charToNum(irmaMove->current_loc.col)] = 'I'; //Tells us where Irma moved to
    printMapBoard(board);
    return board; //Returns the updated board
};

void parseNotationString(char *str, Move *Irma) {
    sscanf(str, "%c%d %d %d %c%d", &Irma->from_loc.col, &Irma->from_loc.row, &Irma->irma.ws, &Irma->irma.wg, &Irma->to_loc.col, &Irma->to_loc.row);
    Irma->current_loc.col = 'x';
    Irma->current_loc.row = -1;
};

double difficultyRating(void) {
    return 4; //It took a long time to figure everything out, and was a big challenge to me.
}

double hoursSpent(void) {
    return 12;
}

/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 *-----------------------------------------------------------------------------
 * Exercise Number: 123456789
 * File: battleship.c
 * Author(s): Felix Rieser
 *-----------------------------------------------------------------------------*/

#include <stdio.h>

#include "battleship.h"


static CellContent myField[10][10];
static CellContent enemyField[10][10];
static CellContent guesses[10][10];

void load_game()
{
    FILE* ownFile = fopen("battleship.my", "r");
    FILE* enemyFile = fopen("battleship.op", "r");

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            fread(&myField[i][j], 4, 1, ownFile);
            fread(&enemyField[i][j], 4, 1, enemyFile);
            guesses[i][j] = Unknown;
        }
    }
    fclose(ownFile);
    fclose(enemyFile);
}


CellContent get_shot(int row, int col)
{
    return row> -1 && row< 10 && col>-1&&col<10 ? myField[row][col]: OutOfRange;
}


bool shoot(int row, int col)
{
    if(!(row> -1 && row< 10 && col>-1&&col<10 ))return false;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if(row+i> -1 && row+i< 10 && col+j>-1&&col+j<10)guesses[row+i][col+j] = enemyField[row+i][col+j];
        }
    }
    return true;
}


CellContent get_my_guess(int row, int col)
{
    return row> -1 && row< 10 && col>-1&&col<10 ? guesses[row][col]: OutOfRange;
}

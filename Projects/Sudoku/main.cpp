// Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sudoku.h"
#include "Util.h"
using namespace SudokuNamespace;

int main()
{
    LOGLN("Starting sudoku: ");

    Sudoku s = Sudoku();
    int grid[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 8, 5},
        {0, 0, 1, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 5, 0, 7, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 1, 0, 0},
        {0, 9, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 0, 7, 3},
        {0, 0, 2, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 9}
    };

    if (s.solveSudoku(grid)) {
        s.printResult(grid);
    } else {
        LOGLN("No Solutions found!");
    }
    return 0;
}
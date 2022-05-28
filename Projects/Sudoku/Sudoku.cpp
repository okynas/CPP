#include "Sudoku.h"
#include "Util.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace SudokuNamespace;
using namespace std;

bool Sudoku::solveSudoku(int grid[N][N]) {
	int row, col;
	if (!isEmptyLocation(grid, row, col)) {
		return true;
	}
	for (int num = 1; num <= 9; num++) {
		if (isGridSafe(grid, row, col, num)) {
			grid[row][col] = num;
			if (solveSudoku(grid)) {
				return true;
			}
			grid[row][col] = Empty;
		}
	}
	return false;
}

bool Sudoku::isEmptyLocation(int grid[N][N], int &row, int &col) {
	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			if (grid[row][col] == Empty) {
				return true;
			}
		}
	}
	return false;
}

bool Sudoku::usedInBox(int grid[N][N], int boxBeginRow, int boxBeginCol, int number) {
	bool inBox = false;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (grid[row + boxBeginRow][col + boxBeginCol] == number) {
				inBox = true;
			}
		}
	}
	return inBox;
}

bool Sudoku::usedInRow(int grid[N][N], int pRow, int num) {
	for (int col = 0; col < N; col++) {
		if (grid[pRow][col] == num) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool Sudoku::usedInCol(int grid[N][N], int pCol, int num) {
	for (int row = 0; row < N; row++) {
		if (grid[row][pCol] == num) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool Sudoku::isGridSafe(int grid[N][N], int prow, int pcol, int number) {
	return !usedInRow(grid, prow, number)
		&& !usedInCol(grid, pcol, number)
		&& !usedInBox(grid, prow - prow % 3, pcol - pcol % 3, number);
}

void Sudoku::printResult(int finalGrid[N][N]){
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			LOG(finalGrid[row][col] << "  ");
		}
		LOGLN("");
	}
}
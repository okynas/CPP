#pragma once

namespace SudokuNamespace {

#define N 9
#define Empty 0

	class Sudoku {
	public:
		bool isEmptyLocation(int grid[N][N], int &row, int &col);
		bool isGridSafe(int grid[N][N], int row, int col, int num);
		bool solveSudoku(int grid[N][N]);
		void printResult(int grid[N][N]);
		bool usedInBox(int grid[N][N], int boxBeginRow, int boxBeginCol, int number);
		bool usedInRow(int grid[N][N], int pRow, int num);
		bool usedInCol(int grid[N][N], int pCol, int num);
	};
}
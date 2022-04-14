// MineSweaper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
// #include <stdc++.h>
#include <stdio.h>

// constant value and computed at compile time
constexpr int BEGINNER = 0;
constexpr int INTERMEDIATE = 1;
constexpr auto ADVANCED = 2;
constexpr auto MAXSIDE = 25;
constexpr auto MAXMINES = 99;
constexpr auto MOVESIZE = 526; // 25 * 25 - 99;

int SIDE;
int MINES;


//bool isValid() {};
//bool isMine() {};
//void makeMove() {};
//void printBoard() {};
//int countAdjacentMines() {};
//bool playMinesweeperUntil() {};
//void placeMines() {};
//void initialise() {};
//void cheatMinesweeper() {};
//void replaceMine() {};
//void playMinersweeper() {};

void chooseDifficultyLevel() {

	int level;

	printf("Enter the Difficulty Level\n");
	printf("0: Beginner (9*9 Cells and 10 Mines\n");
	printf("1: Beginner (16*16 Cells and 40 Mines\n");
	printf("2: Beginner (24*24 Cells and 99 Mines\n");

	scanf_s("%d", &level);

	if (level == BEGINNER) {
		SIDE = 9;
		MINES = 10;
	}

	if (level == INTERMEDIATE) {
		SIDE = 16;
		MINES = 40;
	}

	if (level == ADVANCED) {
		SIDE = 24;
		MINES = 99;
	}

	return;
};

int main()
{
	chooseDifficultyLevel();
	//playMinersweeper();

	printf("TGE");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

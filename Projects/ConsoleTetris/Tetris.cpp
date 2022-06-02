// VIDEO: https://youtu.be/8OK8_tHeCIA?t=1096
// 21:25

#include <iostream>
#include <thread>
#include <vector>
using namespace std;

#include <stdio.h>
#include <Windows.h>

using namespace std;

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char* pField = nullptr;

int nScreenWidth = 80;				// Console screen size X (columns)
int nScreenHeight = 30;				// Console Screen Size Y (rows)

int Rotate(int px, int py, int r) {
	int pi = 0;
	switch (r % 4) {
		case 0:
			pi = py * 4 + px;
			break;
		case 1: 
			pi = 12 + py - (px * 4);
			break;
		case 2: 
			pi = 15 - (py * 4) - px;
			break;
		case 3: 
			pi = 3 + py + (px * 4);
			break;
		default:
			pi = 0;
	}
	return pi;
}

bool DoesPlaceFit(int nTetromino, int nRotation, int nPosX, int nPosY) {
	for (int x = 0; x < nFieldWidth; x++) {
		for (int y = 0; y < nFieldHeight; y++) {
			// get index into piece
			int pi = Rotate(x, y, nRotation);

			// get index into field
			int fi = (nPosY + y) * nFieldWidth + (nPosX + x);

			if (nPosX + x >= 0 && nPosX + x < nFieldWidth) {
				if (nPosY + y >= 0 && nPosY + y < nFieldHeight) {
					if (tetromino[nTetromino][pi] == L'X' && pField[fi] != 0) {
						return false; // fail on first hit
					}
				}
			}
		}
	}
	return true;
}

int main() {
	// create assets

	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");

	tetromino[1].append(L"..X.");
	tetromino[1].append(L".XX.");
	tetromino[1].append(L".X..");
	tetromino[1].append(L"....");

	tetromino[2].append(L".X..");
	tetromino[2].append(L".XX.");
	tetromino[2].append(L"..X.");
	tetromino[2].append(L"....");

	tetromino[3].append(L"....");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L"....");

	tetromino[4].append(L"..X.");
	tetromino[4].append(L".XX.");
	tetromino[4].append(L"..X.");
	tetromino[4].append(L"....");

	tetromino[5].append(L"....");
	tetromino[5].append(L".XX.");
	tetromino[5].append(L"..X.");
	tetromino[5].append(L"..X.");

	tetromino[6].append(L"....");
	tetromino[6].append(L".XX.");
	tetromino[6].append(L".X..");
	tetromino[6].append(L".X..");


	pField = new unsigned char[nFieldWidth * nFieldHeight];
	for (int x = 0; x < nFieldWidth; x++) {
		for (int y = 0; y < nFieldHeight; y++) {
			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;
		}
	}

	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	for (int i = 0; i < nScreenWidth * nScreenHeight; i++) {
		screen[i] = L' ';
	}

	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	// Game logic stuff
	bool bGameOver = false;

	bool bKey[4];
	int nCurrentPiece = 0;
	int nCurrentRotation = 0;
	int nCurrentX = nFieldWidth / 2;
	int nCurrentY = 0;

	while (!bGameOver) {

		// Game timing ====================================
		this_thread::sleep_for(50ms);


		// Input ==========================================
		for (int k = 0; k < 4; k++) {
			bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;
		}

		// GAME LOGIC =====================================


		// RENDER OUTPUT ==================================

		// Draw field
		for (int x = 0; x < nFieldWidth; x++) {
			for (int y = 0; y < nFieldHeight; y++) {
				screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
			}
		}

		// Draw Current piece
		for (int px = 0; px < 4; px++) {
			for (int py = 0; py < 4; py++) {
				if (tetromino[nCurrentPiece][Rotate(px, 0, nCurrentRotation)] != L'.') {
					screen[(nCurrentY + py + 2) * nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;
				}
			}
		}

		// Display frame
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0}, &dwBytesWritten);
	}

	return 0;
}
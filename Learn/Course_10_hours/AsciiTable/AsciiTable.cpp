// AsciiTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{

    // ASCII values from characters.
    // cout << (int)'a' << endl; // returns 97
    // cout << int('a') << endl; // returns also 97.
    // cout << int('A') << endl; // returns 65.

    // char B = char('A') + 1; // = char(65);
    // cout << B;

    // does not take spaces inn to calculations!
    char c1, c2, c3, c4, c5;
    cout << "Enter 5 letters: " << endl;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    cout << "ASCII message: " << int(c1) << " " << int(c2) << " " << int(c3) << " " << int(c4) << " " << int(c5);




    system("pause>0");
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
 
/*
A POINTER = INTEGER that stores a memory address
A linear one dimentional line, like 1 road with multiple houses. Every house has a house number / address.
EACH address is 1 BYTE of data = 8 BIT
*/

#include <iostream>
using namespace std;

#define LOG(X) cout << x << endl;

int main()
{
    int var = 8;

    // void pointer = typeless pointer.
    void* ptr = &var;
    cin.get();
}

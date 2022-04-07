/*
A POINTER = INTEGER that stores a memory address
A linear one dimentional line, like 1 road with multiple houses. Every house has a house number / address.
EACH address is 1 BYTE of data = 8 BIT
*/

#include <iostream>
using namespace std;

#define LOG(x) cout << x << endl;

void Increment(int& value) {
    value++;
}

int main()
{
    /*int var = 8;

    // void pointer = typeless pointer.
    int* ptr = &var;
    *ptr = 10;
    LOG(var);*/

    // allocate 8 bytes of memory to a buffer char-array.
    
    /* char* buffer = new char[8];
    memset(buffer, 0, 8); */
    
    // pnt to a pnt
    /* char** ptr = &buffer; */

    // delete / remove the allocated 8 bytes for memory
    /* delete[] buffer; */

    int a = 5;
    int b = 8;

    int& ref = a;
    ref = b;
    
    Increment(a);
    LOG(a);

    cin.get(); 
}


#include <iostream>
using namespace std;

int main()
{
    // atithimetic operators
    // +, -, *, /, %

    // ++, --

    // needs to be on different level, or it will increate numbers first, then print. 
    // like: counter = 8 , after increase 7,
    // counter = 7, after decrease 8;
    int counter = 7;
    cout << "Incrementing counter: " << counter << endl;
    cout << "after increment: " << ++counter << endl;
    cout << "Decreasing operator: " << counter << endl;
    cout << "after decrease: " << --counter << endl;

    system("cls");

    // relational: <, >, <=, >=, ==, !=
    int a = 5, b = 8;
    cout << (a > b);
    // 5<7 => 1
    // 5>7 => 0
    // 5<=7 => 1
    // 5>=7 => 0
    // 5==7 => 0
    // 5!=7 => 1

    system("cls");

    // logical: &&, ||, !
    cout << (a == 5 && b == 5);

    // assignment:
    system("cls");

    // =, +=, -=, *=, /=, %=
    int x = 5;
    x += 7; // x = x + 7;
    cout << x << endl;


    system("pause>0");
}

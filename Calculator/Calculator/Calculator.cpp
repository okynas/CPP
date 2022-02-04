// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

double calculate(int a, int b, char op) {
    int result;
    if (op == '+') {
        // add
        result = a + b;
    }
    else if (op == '-') {
        // sub
        result = a - b;
    }
    else if (op == '*') {
        // mult
        result = a * b;
    }
    else if (op == '/') {
        // div
        result = a / b;
    }
    else {
        // op is not supported
        cout << "Operations not supported!\n";
        // throw new exceptions("Not supported");
        return 0;
    }

    return result;
}

void oldCalc() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << num1 + num2;
}

int main(){
    
    cout << calculate(10, 20, '%');

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

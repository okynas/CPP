// TheFundamentals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <string>

using namespace std;


/*
drawing a symbol of a triangle
*/
void symbol() {

    cout << "   /|\n";
    cout << "  / |\n";
    cout << " /  |\n"; // dette er det samme som cout << " /  |\n";
    cout << "/___|\n";

}

/*
Learning variables.
*/
void printVariables() {
    string characterName = "Ole-Jorgen";
    int characterAge = 21;
    cout << "There was a man named " << characterName << "\n";
    cout << "He was " << characterAge << " years old\n";
    cout << "He liked the name " << characterName << "\n";
    cout << "But he did not like the age " << characterName << "\n";
}


/*
* List of some of the datatypes!
*/
void dataTypes()
{
    char grade = 'A';
    string phrase = "Giraffe Academy";
    int age = 50;
    double gpa = 2.3;
    bool isMale = true;


    cout << ( double( age) > gpa);
}


/*
* working with strings
*/
void stringManipulations()
{

    string phrase = "Hello world!\n";
    cout << phrase << endl;
    cout << phrase.length() << endl;
    cout << phrase[0] << endl;
    phrase[1] = 'B';
    cout << phrase << endl;
    cout << phrase.find("Bllo", 1) << endl;
}

void workingWithNumbers() {
    cout << 5 * 42 << "\n";
    cout << 40 << "\n";

    cout << 5.5 <<  "\n";
}

void userInput() {
    int age;
    string name;
    // cout << "Enter your age: ";
    // cin >> age;

    // cout << "Your age is " << age << " years old";

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello " << name << "\n";
}

void arrays() {
    int luckyNumbers[] = {4,8,16,32,64,128,256,512};
    cout << luckyNumbers[1] << "\n";

    luckyNumbers[1] = 22222;
    cout << luckyNumbers[1] << "\n";
}

void sayHi(string name, int age) {
 cout << "Hello, My name is " << name << ", and I am " << age << " years old!" << "\n";
}

double result(int a, int b) {
    return a * b;
}

void ifStatements(int a, int b) {
    if (a > b) {
        cout << "A is greate than B \n";
    }
    else if (a < b) {
        cout << "A is less than B \n";
    }
    else {
        cout << "A is equal to B \n";
    }
}

int main(){
    /*cout << result(10, 4) << "\n";
    ifStatements(10, 20);*/
    int i = 0;

    while (i < 10) {
        cout << "i: " << i << ": is less than 10 \n";
        i++;
    }

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

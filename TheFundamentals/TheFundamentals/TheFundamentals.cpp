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

/*
*
* Learning to work with numbers
*/
void workingWithNumbers() {
    cout << 5 * 42 << "\n";
    cout << 40 << "\n";

    cout << 5.5 <<  "\n";
}
/*
*
* User input
*/
void userInput() {
    // int age;
    string name;
    // cout << "Enter your age: ";
    // cin >> age;

    // cout << "Your age is " << age << " years old";

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello " << name << "\n";
}

/*
* Working with arrays
*/

void arrays() {
    int luckyNumbers[] = {4,8,16,32,64,128,256,512};
    cout << luckyNumbers[1] << "\n";

    luckyNumbers[1] = 22222;
    cout << luckyNumbers[1] << "\n";
}

/*
* Working with strings
*/

void sayHi(string name, int age) {
 cout << "Hello, My name is " << name << ", and I am " << age << " years old!" << "\n";
}

/*
* Basic maths
*/
double result(int a, int b) {
    return a * b;
}


/*
* If statements
*/
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


/*
* string function that return day of week, by using case
*/

string getDayOfWeek(int dayNum) {
    string dayName;

    switch (dayNum){
    case 0:
        dayName = "Monday";
        break;
    case 1:
        dayName = "Thirsday";
        break;
    case 2:
        dayName = "Wednesday";
        break;
    case 3:
        dayName = "Thursday";
        break;
    case 4:
        dayName = "Friday";
        break;
    case 5:
        dayName = "Saturday";
        break;
    case 6:
        dayName = "Sunday";
        break;
    default:
        dayName = "Invalid Day Number";
        break;
    }
    return dayName;
}

/*
* working with while loops
*/

void div() {

    int i = 0;

    while (i < 10) {
        cout << "i: " << i << ": is less than 10 \n";
        i++;
    }

    i = 0;

    do {
        cout << "Hello \n";
        i++;
    } while (i < 5);
}


/*
* Testing while loops with arrays
*/
void testingOutLoops() {
    int index = 1;
    while (index <= 5) {
        cout << index << endl;
        index++;
    }

    // for loops

    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    int arrSize = sizeof(numbers) / sizeof(numbers[0]);


    /*
    *
    * (&numbers + 1) points to the memory address right after the end of the array
    *
    * *(&numbers + 1) casts the adress above to en int *.
    * And by subtractign the adress of the start from the adress at the end, it gives us the length.
    *
    */
    int arrSize2 = *(&numbers + 1) - numbers;

    for (int i = 0; i < arrSize2; i++) {
        cout << numbers[i] << endl;
    }
}

/*
* Exponential functions
*/

int power(int baseNum, int powNum) {
    int result = 1;

    for (int i = 1; i <= powNum; i++) {
        result *= baseNum;
    }

    return result;
}


/*
* How arrays work
*/
void Arrays2D(int row, int col) {

    const int r = 10, c = 10;

    int numberGrid[r][c];

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            numberGrid[x][y] = 1;
        }
    }


    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            cout << numberGrid[x][y] << ", ";
        }
        cout << "\n";
    }
}


/*
* Trying on dynamic arrays, with pointers.
*/

void Arrays2D_2(int row, int col) {
    //allocate the array
    int** arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }

    // use the array

    //deallocate the array
    for (int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;
}

/*
* How pointers works
*/

void ptr() {
    int age = 19;
    double gpa = 2.7;
    string name =  "Stian";

    cout << &age;
}


int main(){
    // cout << result(10, 4) << "\n";
    // ifStatements(10, 20);
    // cout << getDayOfWeek(4) << "\n";

    // testingOutLoops();

    // cout << power(3, 4); 3^4=81

    // Arrays2D_2(2,2);
    ptr();

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

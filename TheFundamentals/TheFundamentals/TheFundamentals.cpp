// TheFundamentals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
// using namespace std;


/*
drawing a symbol of a triangle
*/
void symbol() {

    std::cout << "   /|\n";
    std::cout << "  / |\n";
    std::cout << " /  |\n"; // dette er det samme som std::cout << " /  |\n";
    std::cout << "/___|\n";

}

/*
Learning variables.
*/
void printVariables() {
    std::string characterName = "Ole-Jorgen";
    int characterAge = 21;
    std::cout << "There was a man named " << characterName << "\n";
    std::cout << "He was " << characterAge << " years old\n";
    std::cout << "He liked the name " << characterName << "\n";
    std::cout << "But he did not like the age " << characterName << "\n";
}


/*
* List of some of the datatypes!
*/
void dataTypes()
{
    char grade = 'A';
    std::string phrase = "Giraffe Academy";
    int age = 50;
    double gpa = 2.3;
    bool isMale = true;


    std::cout << ( double( age) > gpa);
}


/*
* working with strings
*/
void stringManipulations()
{

    std::string phrase = "Hello world!\n";
    std::cout << phrase << std::endl;
    std::cout << phrase.length() << std::endl;
    std::cout << phrase[0] << std::endl;
    phrase[1] = 'B';
    std::cout << phrase << std::endl;
    std::cout << phrase.find("Bllo", 1) << std::endl;
}

int main()
{
    stringManipulations();
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

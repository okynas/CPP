# C++ (CPP)

C++ is a programming language pased on C. It was written in 1990s and used to create many types of programs, and is one of the most used. It was developed by [Bjarne Stroustrup](https://simple.wikipedia.org/wiki/C%2B%2B#:~:text=was%20developed%20by-,Bjarne%20Stroustrup,-at%20Bell%20Labs) and was named "C with classes", and was intended to improve C by adding features based on object-oriented programming.

Sample programs:

```cpp

// This is a comment. It's for *people* to read, not computers. It's usually used to describe the program.

// Make the I/O standard library available for use in the program.
#include <iostream>
using namespace std;
// We are now defining the main function; it is the function run when the program starts.
int main()
{
    // Printing a message to the screen using the standard output stream std::cout.
    cout << "Hello World!";
}

```

```cpp
// This program is similar to the last, except it will add 3 + 2 and print the answer instead of "Hello World!".
#include <iostream>

int main()
{
    // Print a simple calculation.
    std::cout << 3 + 2;
}
```

```cpp
// This program subtracts, multiplies, divides and then prints the answer on the screen.
#include <iostream>

int main()
{
    // Create and initialize 3 variables, a, b, and c, to 5, 10, and 20.
    int a = 5;
    int b = 10;
    int c = 20;

    // Print calculations.
    std::cout << a-b-c;
    std::cout << a*b*c;
    std::cout << a/b/c;
}
```
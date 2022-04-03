
#include <iostream>
using namespace std;

bool isNumberEven(int number) {
    int even(number % 2);

    if (even == 0) {
        return true;
    }

    return false;
}

/*
User should enter side length of a triangle (a,b,c)
Program should write out wheter the triangle is equilateral, isosceles or scalene

if : 
    num a == num b, and num b == num c => equilateral triangle
else if:
    num a != b && a != c && b != c => scalene
else : 
    => isosceles
*/

void calculateTypeOfTriangle(int a, int b, int c) {
    if ((a == b) && (b == c) )
        cout << "The triangle is eqilateral" << endl;
    
    else {
        if ((a != b) && (a != c) && (b != c)) 
            cout << "Triangle is scalene" << endl;
        
        else 
            cout << "The triangle is isosceles" << endl;
        
    }
}

int main()
{
    int num = 2;
    int n1, n2, n3;
    cout << isNumberEven(num) << endl;

    cout << "Enter three numbers" << endl;
    cin >> n1 >> n2 >> n3;
    calculateTypeOfTriangle(n1, n2, n3);

    
}



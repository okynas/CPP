
#include <iostream>
using namespace std;

void calculateBMI() {
    /*
   BMI Calculator:

   weight (kg) / height * height (m)
   Underweight < 18.5
   Normal weight 18.5-24.9
   Overweight > 25
   */

    float weight;
    float height;

    cout << "Enter your weight in kilogram (kg), e.g. (75): " << endl;
    cin >> weight;

    cout << "Enter your height in meter (m), e.g. (1.72): " << endl;
    cin >> height;

    float bmi = weight / (height * height);

    if (bmi < 18.5) 
        cout << "You are underweight!" << endl;
    else if (bmi > 25) 
        cout << "You are overweight!" << endl;
    else 
        cout << "You are normal weight!" << endl;

}

int main()
{
    calculateBMI();

    system("pause>0");
}


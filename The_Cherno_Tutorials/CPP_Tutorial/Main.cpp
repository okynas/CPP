// CPP_Tutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "Util.h"
#include "Spicies.h"

int main()
{
    Person stian = Person("Stian", "Martinsen", 21, 1);

    LOG(stian.name);



}

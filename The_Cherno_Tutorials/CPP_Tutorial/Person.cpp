#include "Person.h"
#include <iostream>

using namespace std;

std::string Person::getName()
{
	return first_name + " " + last_name;
}

Person::~Person() {
	std::cout << "Person destroyed!" << std::endl;
}

std::string Person::spicies = "Humanity";

enum Person::e_gender {
	Male = 0,
	Female = 1
};

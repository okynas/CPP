#include "Person.h"
#include <iostream>

using namespace std;

//std::string Person::getName()
//{
//	return name;
//}

Person::~Person() {
	std::cout << "Person destroyed!" << std::endl;
}

enum Person::e_gender {
	Male = 0,
	Female = 1
};

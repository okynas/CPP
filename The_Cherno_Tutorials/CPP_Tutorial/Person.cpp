#include "Person.h"
using namespace std;

//Person::spicies = "Human";

std::string Person::getName()
{
	return first_name + " " + last_name;
}

std::string Person::spicies = "Humanity";

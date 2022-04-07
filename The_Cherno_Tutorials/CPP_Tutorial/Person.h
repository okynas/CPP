#pragma once
#include <string>
#include "Spicies.h"

using namespace std;

class Person : public Spicies{
private:
	// string name;
	int age;
	int gender;

public:
	Person(string _name, string _last_name, int _age, int _gender) : Spicies(_name) {
		age = _age;
		gender = _gender;
	}
	// destructor
	~Person();

	//Person(string name, string last_name, int age);

	// string getName();
	enum e_gender : int;

};
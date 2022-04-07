#pragma once
#include <string>

using namespace std;

class Person {
	string first_name;
	string last_name;
	int age;

public:
	Person(string _first_name, string _last_name, int _age) {
		first_name = _first_name;
		last_name = _last_name;
		age = _age;
	}

public:
	std::string getName();
	static std::string spicies;

};
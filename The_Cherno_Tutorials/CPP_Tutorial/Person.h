#pragma once
#include <string>

using namespace std;

class Person {
	string first_name;
	string last_name;
	int age;
	int gender;

public:
	Person(string _first_name, string _last_name, int _age, int _gender) {
		first_name = _first_name;
		last_name = _last_name;
		age = _age;
		gender = _gender;
	}
	
	~Person();

	string getName();
	static string spicies;
	enum e_gender : int;

};
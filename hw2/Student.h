#pragma once
#include <iostream>
#include <string>
using namespace std;

// Declare StudentClub above to avoid any problems
class StudentClub;

// Class Student Declaration
class Student
{
public:
	Student(string n) {
		name = n;
	}

	string get_name() {
		return name;
	};

private:
	string name;
};

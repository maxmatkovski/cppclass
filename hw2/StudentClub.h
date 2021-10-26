#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
using namespace std;
class StudentClub {

public:

	// Constructor
	StudentClub(Student* p, Student* v, Student* s, Student* t,
		vector<Student*> m);


	// Functions return position
	Student* get_president() const;
	Student* get_vice_president() const;
	Student* get_secretary() const;
	Student* get_treasurer() const;

	// Returns all members
	vector<Student*> get_members() const;

	// Adds a new student
	void add_member(Student* s);

	// How many total members there are
	size_t number_members() const;

private:
	// Fields (pointers to a student object)
	Student* president;
	Student* vice_president;
	Student* secretary;
	Student* treasurer;
	vector<Student*>members; 

};

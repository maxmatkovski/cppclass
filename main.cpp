#include <iostream>
#include <string>
#include "Student.h"
#include "StudentClub.h"
#include <typeinfo>
using namespace std;

/*
PIC 10B 2A, Homework 2
Purpose: StudentClub Project
Author: Max Matkovski
Date: 10/25/21
*/

int main() {

	// Introductory Statements

	cout << "President: " << flush;
	string president_name;
	cin >> president_name;

	cout << "Vice-President: " << flush;
	string vice_president;
	cin >> vice_president;

	cout << "Secretary: " << flush;
	string secretary;
	cin >> secretary;

	cout << "Treasurer: " << flush;
	string treasurer;
	cin >> treasurer;


	// Create new instances of Student using the inputs
	// Stores them in pointers of Student Class

	Student* p = new Student(president_name);
	Student* vp = new Student(vice_president);
	Student* s = new Student(secretary);
	Student* t = new Student(treasurer);
	
	// Vector of Pointers of Student Class
	vector<Student*>members = {};


	while (true) {
		// Loop will break once 'Q' is entered into console
		cout << "New member (Q to Quit): " << flush;
		string input;
		cin >> input;
		if (input == "Q") {
			break;
		}
		else {
			Student* new_member = new Student(input);
			members.push_back(new_member);
		}
	}

	// Create club which utilizes the Student Club Constructor
	StudentClub* club = new StudentClub(p, vp, s, t, members);


	cout << "MATHLETES (" << club->number_members() << " total members )" << endl;
	cout << "President: " << club->get_president()->get_name() << endl;
	cout << "Vice-President: " << club->get_vice_president()->get_name() << endl;
	cout << "Secretary: " << club->get_secretary()->get_name() << endl;
	cout << "Treasurer: " << club->get_treasurer()->get_name() << endl;

	// number_member function not working
	// need a way to print out club to see if 
	// double name entry is double counted

	return 0;

}
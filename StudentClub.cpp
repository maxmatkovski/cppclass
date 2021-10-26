#include <string>
#include "Student.h"
#include "StudentClub.h"
using namespace std;

// Constructor Function

StudentClub::StudentClub(Student* p, Student* v, Student* s, Student* t,
	vector<Student*> m) {

	president = p;
	vice_president = v;
	secretary = s;
	treasurer = t;
	members = m;
};

// Function definitions

Student* StudentClub::get_president() const {
	return president;
}


Student* StudentClub::get_vice_president() const {
	return vice_president;
}


Student* StudentClub::get_secretary() const {
	return secretary;
}

Student* StudentClub::get_treasurer() const {
	return treasurer;
}


vector<Student*> StudentClub::get_members() const {
	return members;
}


void StudentClub::add_member(Student* new_member) {
	members.push_back(new_member);
}


size_t StudentClub::number_members() const {


	vector<Student*> people;

	// Ensures that people consists of unique people
	people.push_back(president);

	/*
	I called get name function onto all of the comparisons
	to ensure that using a duplicate name in one of the four 
	positions
	
	*/

	if (president->get_name() != vice_president->get_name()) {
		people.push_back(vice_president);
	}
	if (vice_president->get_name() != secretary->get_name() && president->get_name() != secretary->get_name()) {
		people.push_back(secretary);
	}
	if (president->get_name() != treasurer->get_name() && vice_president->get_name()
		!= treasurer->get_name() && secretary->get_name() != treasurer->get_name()) {
		people.push_back(treasurer);
	}

	// Loops over members and people to ensure that
	// size of members only counts unique names

	for (auto& m : members) {
		bool found = false;
		for (auto& p : people) {
			if (m->get_name() == p->get_name()) {
				found = true;
			}
		}

		if (!found) {
			people.push_back(m);
		}
	}
	
	return people.size();
}

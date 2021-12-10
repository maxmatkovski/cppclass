#include "P1.h";

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;


//vectors
vector<int> combination;

// define a vector of vectors
vector<vector<int>>stuff;

vector<vector<int>> helper(int offset, int k, int n) {


	if (k == 0 && combination.size()!=0) {
		stuff.push_back(combination);
		return stuff;
	}

	for (int i = offset; i <= n/* - k*/; ++i) {
		combination.push_back(i);
		helper(i + 1, k - 1, n);
		combination.pop_back();
		if (offset == 0) { return stuff; }
	}

	return stuff;
}

vector<vector<int>> combinations(int n, int k) {


	// {1,2,3,4,..., n} of size k

	//for (int i = 1; i <= n; ++i) {
	//	stuff.push_back(combination);
	//}
	/*helper (1, k, n);*/

	return helper(1, k, n);
}



//// if k is zero return empty vector
//if (k == 0) {
//	return stuff;
//}
//
//// fill inner vector then insert into outer vector
//for (int i = n; i < n - k; i++) {
//	vector<int> temporary;
//
//	for (int j = 0; j < 3; j++) {
//		temporary.push_back(i);
//	}
//	stuff.push_back(temporary);
//}
//
//return stuff;

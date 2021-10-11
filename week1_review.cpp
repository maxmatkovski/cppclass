#include <iostream>
using namespace std;

int main() {
	
	double y = 9.7;
	cout << y << endl;
	
	double x = static_cast<int>(y);
	cout << x << endl;

	cout << "this is the program!" << endl;

	return 0;
}

//

double myFunction(double x) {
// assert used to check parameter condition
	assert(x >= 0);
	double result = sqrt(x);
	return result;
}

int main()
{
	double x;
	cout << "enter a double : " << flush;
	cin >> x;
	cout << "result of the function is " << myFunction(x) << endl;
	return 0;
}

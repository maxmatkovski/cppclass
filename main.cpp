#include <iostream>
#include <string>
#include <fstream>	

#include "textfile.h"

using namespace std;


int main() {

string file1, file2;
cout << "enter the name of file 1: " << flush;
cin >> file1;
cout << "enter the name of file 2: " << flush;
cin >> file2;

textfile t1 = textfile(file1);
textfile t2 = textfile(file2);


t1.writeToFile(t1, t2);

}

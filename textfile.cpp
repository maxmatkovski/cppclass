#include "textfile.h"

using namespace std;


// setter and getter functions
void textfile::setName(string name) {
		Name = name;
	}
string textfile:: getName() {
		return Name;
	}
void textfile:: setCharacterCount(int charCount) {
		CharacterCount = charCount;
	}
int textfile:: getCharacterCount() {
		return CharacterCount;
	}
void textfile:: setWordCount(int wordCount) {
		WordCount = wordCount;
	}
int textfile:: getWordCount() {
		return WordCount;
	}
void textfile::setLineCount(int lineCount) {
	LineCount = lineCount;
}
int textfile::getLineCount() {
	return LineCount;
}

// counter function
void textfile::countCharacters(textfile tfobject) {

	ifstream indata;
	char ch;
	int lines = 0, words = 0, characters = 0;

	indata.open(tfobject.getName());
	if (indata.fail())
		cout << "fail" << endl;


	indata.get(ch);
	while (indata) {
		if (ch == '\n')
			lines++;
		else if (ch == ' ')
			words++;
		else
			characters++;
		indata.get(ch);
	}

	setCharacterCount(characters);
	setWordCount(words);
	setLineCount(lines);

	
	cout << endl;
	cout << "File Name: " << getName() << endl;
	cout << "Number of characters : " << getCharacterCount() << endl;
	cout << "Number of words:  " << getWordCount() << endl;

}

// comparison function
void textfile::compareAmounts(textfile t1, textfile t2) {
	if (t1.getLineCount() < t2.getLineCount()) {
		cout << "The file name " << t1.getName() << " has less lines than" << t2.getName() << endl;
	}
	else if (t1.getLineCount() > t2.getLineCount()) {
		cout << "The file name " << t2.getName() << " has less lines than" << t1.getName() << endl;

	}
}

// write to file function
void textfile::writeToFile(textfile t1, textfile t2) {

	
	// count characters execute on functions
	t1.countCharacters(t1);
	t2.countCharacters(t2);

	// comparison function
	string lesser, greater;
	if (t1.getLineCount() < t2.getLineCount()) {
		lesser = t1.getName();
		greater = t2.getName();
	}
	else if (t1.getLineCount() > t2.getLineCount()) {
		lesser = t2.getName();
		greater = t1.getName();
	}

	ofstream myfile;
	myfile.open("Properties.txt");
	myfile << "File Name: " << t1.getName() << endl <<
		"Number of characters: " << t1.getCharacterCount() << endl <<
		"Number of words: " << t1.getWordCount() << endl
		<< endl <<
		"File Name: " << t2.getName() << endl <<
		"Number of characters: " << t2.getCharacterCount() << endl <<
		"Number of words: " << t2.getWordCount() << endl
		<< endl <<
		"The file named \"" << lesser << "\" has less lines than \"" << greater << "\"." << endl

		;

	myfile.close();
}


// constructor
textfile::textfile(string name) {
	Name = name;
};
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class textfile
{
private:
	string Name;
	int CharacterCount;
	int WordCount;
	int LineCount;

public:
	void setName(string name);
	string getName();
	void setCharacterCount(int charCount);
	int getCharacterCount();
	void setWordCount(int wordCount);
	int getWordCount();
	int getLineCount();
	void setLineCount(int lineCount);
	void countCharacters(textfile tfobject);
	void compareAmounts(textfile t1, textfile t2);
	void writeToFile(textfile t1, textfile t2);
	textfile(string name);
};


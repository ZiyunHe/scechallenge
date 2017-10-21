/*
 * main.cpp
 * find longest sentence
 * find how many palindromes
 * find longest palindrome
 *
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	ifstream inFile;

	// open file
	inFile.open("input.txt");

	// if file cannot open
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	string str;
	string longeststr;
	string longestpali;
	int max = 0;
	int palindromeNum = 0;
	int palimax = 0;

	// Get the first line from the file, if any
	getline(inFile, str);

	// Continue if the line was successfully read
	while (inFile) {

		// check longest sentence
		if (str.length() > max) {
			max = str.length();
			longeststr = str;
		}

		string temp = str;

		// make sentence all lower case
		transform(str.begin(), str.end(), str.begin(),::tolower);

		// remove all punctuations
		for(int i=0; i <str.length(); i++) {
			if(ispunct(str.at(i))) {
				str.at(i)= ' ';
			}
		}

		// erase all spaces
		str.erase( std::remove_if( str.begin(), str.end(), ::isspace ), str.end() );

		// compare from beginning to last if sentece is palindrome
		if( equal(str.begin(), str.begin() + str.size()/2, str.rbegin()) ) {
			palindromeNum++;
			if(temp.length() > palimax) {
				palimax = temp.length();
				longestpali = temp;
			}
		}

		// get another line.
		getline(inFile, str);
	}

	// close file
	inFile.close();

	// print out result
	cout << "Longest sentence: " << longeststr << endl;
	cout << "Number of Palindromes: " << palindromeNum << endl;
	cout << "Longest Palindrome: " << longestpali << endl;

	return 0;
}

//
// Created by KimJammer on 11/20/2021.
//

/*
 * A variety of helper functions for the main program to use.
 */
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

string getUserString(string prompt){
	//Print the prompt
	cout << prompt;

	string rawInput;
	getline(cin,rawInput);
	return rawInput;
}

int getUserInt(string prompt){
	//Print the prompt
	cout << prompt;

	string rawInput;
	getline(cin, rawInput);
	stringstream inputStream;
	inputStream << rawInput;

	int userInt = 0;
	inputStream >> userInt;
	return userInt;
}

//Checks if a given string only contains alphabets and spaces.
bool isAlphabetic(string text){
	bool valid = true;
	for (int i = 0; i < text.length(); i++){
		//If not ((is lowercase) or (is uppercase) or (is space))
		if (!((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90) || (text[i] == 32))){
			valid = false;
		}
	}
	return valid;
}

string lowerCase(string text){
	string newText = text;
	transform(newText.begin(), newText.end(), newText.begin(), ::tolower);
	return newText;
}

string upperCase(string text){
	string newText = text;
	transform(newText.begin(), newText.end(), newText.begin(), ::toupper);
	return newText;
}
#include <iostream>
#include <string>
#include "helperFuncs.h"

using namespace std;

void oneRun();
void encodeMode();
string encode(string plaintext, int key);
void decodeMode();
string decode(string ciphertext, int key);

//TODO:Add mode to support a greater charset, add encrypting breaking mode.

int main() {
	cout << "Welcome to Caesar Cipher!" << endl;

	//Ask user for mode, and run the mode until the user quits.
	bool userInputValid = false;
	while (!userInputValid){
		string userChoice = getUserString("Encode (e), Decode (d), or Quit (q)? > ");
		if (userChoice == "e" || userChoice == "E"){
			encodeMode();
		}else if (userChoice == "d" || userChoice == "D"){
			decodeMode();
		}else if (userChoice == "q" || userChoice == "Q"){
			break;
		}
		else{
			cout << "That's not a valid option try again.\n";
			userInputValid = false;
		}
	}

	return 0;
}

//Runs the Encoding code, getting and encrypting some plaintext using a provided key.
void encodeMode(){
	bool plainTextValid = false;
	string plainText;
	while (!plainTextValid) {
		plainText = lowerCase(getUserString("Enter your plaintext: "));

		if (isAlphabetic(plainText)) {
			cout << "Your plain text: " << plainText << endl;
			plainTextValid = true;
		}else{
			cout << "That is invalid, please try again." << endl;
		}
	}

	bool keyValid = false;
	int key;
	while (!keyValid){
		key = getUserInt("Enter your encoding key: ");

		//Key must be between negative 26 and positive 26.
		//Don't wrap the key (subtract/add 26 until it's in normal range) for user, since I don't know if the int overflowed or not.
		if (!(key < -26 || key > 26)){
			cout << "Your key: " << key << endl;
			keyValid = true;
		}else{
			cout << "That is invalid, please try again." << endl;
		}
	}

	string cipherText = encode(plainText, key);

	cout << "Your encrypted ciphertext:\n" << cipherText << endl;
}

string encode(string plaintext, int key){
	string ciphertext;

	for (int i = 0; i < plaintext.length(); i++){
		char character = plaintext[i];
		int newCharIndex;

		//If it's a space, don't do anything
		if (plaintext[i] == 32){
			ciphertext.push_back(' ');
			continue;
		}else{
			//Shift character forward.
			newCharIndex = static_cast<int>(character) + key;
		}

		//If character goes past index of lowercase characters, subtract/add 26 to bring back to front.
		//Assumes key never goes past +- 26, which is validated earlier.
		if (newCharIndex > 122){
			newCharIndex -= 26;
		}else if (newCharIndex < 97){
			newCharIndex += 26;
		}

		ciphertext.push_back(static_cast<char>(newCharIndex));
	}

	return ciphertext;
}

//Runs the Decoding code, getting an encrypted string and key to turn it into plaintext.
//This is basically identical to encoding code, and it could be one function. They are separate for clarity.
void decodeMode(){
	bool cipherTextValid = false;
	string cipherText;
	while (!cipherTextValid) {
		cipherText = lowerCase(getUserString("Enter your ciphertext: "));

		if (isAlphabetic(cipherText)) {
			cout << "Your cipher text: " << cipherText << endl;
			cipherTextValid = true;
		}else{
			cout << "That is invalid, please try again." << endl;
		}
	}

	bool keyValid = false;
	int key;
	while (!keyValid){
		key = getUserInt("Enter your decoding key: ");

		//Key must be between negative 26 and positive 26.
		//Don't wrap the key (subtract/add 26 until it's in normal range) for user, since I don't know if the int overflowed or not.
		if (!(key < -26 || key > 26)){
			cout << "Your key: " << key << endl;
			keyValid = true;
		}else{
			cout << "That is invalid, please try again." << endl;
		}
	}

	string plainText = decode(cipherText, key);

	cout << "Your decrypted plaintext:\n" << plainText << endl;
}

string decode(string ciphertext, int key){
	string plaintext;

	for (int i = 0; i < ciphertext.length(); i++){
		char character = ciphertext[i];
		int newCharIndex;

		//If it's a space, don't do anything
		if (ciphertext[i] == 32){
			plaintext.push_back(' ');
			continue;
		}else{
			//Shift character backward.
			newCharIndex = static_cast<int>(character) - key;
		}

		//If character goes past index of lowercase characters, subtract/add 26 to bring back to front.
		//Assumes key never goes past +- 26, which is validated earlier.
		if (newCharIndex < 97) {
			newCharIndex += 26;
		}else if (newCharIndex > 122){
			newCharIndex -= 26;
		}

		plaintext.push_back(static_cast<char>(newCharIndex));
	}

	return plaintext;
}
// Giovanni Cortese
// Random password generator

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	srand(time(0));

	int size;
	char* pwd;

	// This part takes input from user to determine pwd length and does not continue unless pwd is >= 7 characters.
	cout << "\nEnter desired password length: (Minimum 7 chars) ";
	cin >> size;

	while (size < 7) {
		cout << "\nPassword must be at least 7 characters!\n";
		cin >> size;
	}
	system("cls");

	pwd = new char[size];

	// This part begins by determining the frist element of the char array to be a capital letter (ascii code between 65 & 90 inclusive) and 
	// the rest of the elements are any combination of random characters (ascii code between 33 & 126 inclusive)
	cout << "\nYour random password is: ";
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			pwd[i] = 65 + (rand() % (90 - 65 + 1));				// To get correct range of chars in ascii: low + (rand() % (high - low + 1)) 
		}
		else {
			pwd[i] = 33 + (rand() % (126 - 33 + 1));
		}
		cout << pwd[i];
	}

	// Outputs each character (pwd[i]) with its respective ASCII code using int(pwd[i])
	cout << "\n\nThe ASCII character values are: \n";
	for (int i = 0; i < size; i++) {
		cout << pwd[i] << " -- " << int(pwd[i]) << endl;
	}

	return 0;
}
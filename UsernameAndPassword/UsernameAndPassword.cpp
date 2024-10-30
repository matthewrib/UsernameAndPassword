/*
	UsernameAndPassword.cpp
	Matthew Bersalona
	CSCI 123 C
	10/29/2024
*/

#include <iostream>
#include <string>

using namespace std;

bool checkUsername(string name);
bool checkPassword(string pass);

int main() {
	string username, password;

	cout << "Enter a username. It should only contain letters and numbers and not start with a number: ";
	cin >> username;
	while (checkUsername(username) == false) {
		cout << "Enter a username. It should only contain letters and numbers and not start with a number: ";
		cin >> username;
	}
	cout << "Enter a password. It should contain at least 1 special character, one uppercase letter, one lowercase letter, and at least one number: ";
	cin >> password; 
	while (checkPassword(password) == false) {
		cout << "Enter a password. It should contain at least 1 special character, one uppercase letter, one lowercase letter, and at least one number: ";
		cin >> password;
	}
	cout << "Account Created!" << endl;

	return 0;
}

//returns true if username only contains letters and numbers and starts with a letter
bool checkUsername(string name) {
	if (isalpha(name[0]) == false) {
		cout << "Your username needs to start with a letter." << endl;
		return false;
	}
	for (int i = 0; i < name.length(); i++) {
		if (isalnum(name[i]) == false) {
			cout << "Your username needs to only have letters and numbers." << endl;
			return false;
		}
	}
	return true;
}

//returns true if password contains at least 1 special character, one uppercase letter, one lowercase letter, and at least one number
bool checkPassword(string pass) {
	bool hasSpecial = false; 
	bool hasLowercase = false;
	bool hasUppercase = false;
	bool hasNumber = false; 
	int repeatCount = 1;

	for (int i = 0; i < pass.length(); i++) {
		if (!isalnum(pass[i]) && !isspace(pass[i])) {
			hasSpecial = true;
		}
		if (islower(pass[i])) {
			hasLowercase = true;
		}
		if (isupper(pass[i])) {
			hasUppercase = true;
		}
		if (isdigit(pass[i])) {
			hasNumber = true;
		}

		if (i > 0) {
			if (isalpha(pass[i])) {
				if (tolower(pass[i]) == tolower(pass[i - 1])) {
					repeatCount++;
				}
				else {
					repeatCount = 1;
				}
			}
		}

		if (repeatCount == 3) {
			cout << "You cannot repeat the same letter 3 times. " << endl;
			return false;
		}
		if (hasSpecial && hasLowercase && hasUppercase && hasNumber) {
			break;
		}
	}
	if (hasSpecial && hasLowercase && hasUppercase && hasNumber) {
		return true;
	}
	if (!hasSpecial) {
		cout << "Your password needs a special character." << endl;
	}
	if (!hasLowercase) {
		cout << "Your password needs a lowercase letter." << endl;
	}
	if (!hasUppercase) {
		cout << "Your password needs a uppercase letter." << endl;
	}
	if (!hasNumber) {
		cout << "Your password needs a number." << endl;
	}
	return false;
}
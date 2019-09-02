//============================================================================
// Name        : cpphelloo.cpp
// Author      : owennet
// Version     :
// Copyright   : Your copyright notice
// Description : Simple bank account system
//============================================================================

#include <iostream>
#include <vector>
#include <string>

#define OPTION_VIEW_HISTORY 1
#define OPTION_CHANGE_PIN 2
using namespace std;

bool session = true;


struct Transaction {

	string target;
	unsigned int amount;

	string toString() {
		return "[TRANSACTION] " + std::to_string(amount) + " given to " + target;
	}
};


/**
 * Structure representing a Account
 */
struct Account {

	string name;
	unsigned int pin = 0000;

	vector<Transaction> history;

	Account(string name, unsigned int pin) {
		this->name = name;
		this->pin = pin;

		// just to test the print of transactions
		history.push_back(makeTransaction(3000, "good server"));
		history.push_back(makeTransaction(100, "Teacher lessons of c++"));
	}

	Transaction makeTransaction(int amount, string target) {
		Transaction tr;
		tr.amount = amount;
		tr.target = target;
		return tr;
	}
};

void changePIN(Account& account, int newpin);
void viewHistory(Account& account);

int main() {

	int option;
	Account owenaccount("Owen Madeira", 1020);

	cout << "Welcome to our Bank" << endl
		 << "What would you like to do?" << endl
		 << "1 - View History" << endl
		 << "2 - Change PIN" << endl
		 << "Please choose your option by selection the number" << endl;

	while (session) {

		cin >> option;

		// i will add more options here
		switch(option) {
			case OPTION_VIEW_HISTORY:
				viewHistory(owenaccount);
				break;
			default:
				cout << "invalid input, please choose a different option" << endl;
		}

		cout << "Please choose another option" << endl;
	}

	return 0;
}

void changePIN(Account& account, int newpin) {
	account.pin = newpin;
	cout << "PIN has been changed" << endl;
}

void viewHistory(Account& account) {
	for (unsigned int i = 0; i < account.history.size(); i++){
		cout << account.history.at(i).toString() << endl;
	}
}

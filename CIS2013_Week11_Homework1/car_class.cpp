#include <iostream>
#include <cstring>
#define DEBUG false
using namespace std;




class Car {
	string color, make, model;
	int year, speed;

};


int main() {
	if (DEBUG) { cout << "Debug is on."; }
	char input = 'y';

	do {
		cout << "Select an action:\n(M)Set make\n(O)Set model\n(Y)Set year\n(S)Start car\n(S)Stop car\n(P)Print\n(X)Exit\n\nWhat would you like to do?\n";
		cin >> input;
	} while (input != 'x' || input != 'X');
	

	
	return 0;
}


#include <iostream>
#include <cstring>
#include <string>
#define DEBUG false
using namespace std;




class Car {
public:
	string color, make, model;
	int year, speed;
	char direction;
	bool driverIn, stopStart;

	void default() {
		color = "Gold";
		make = "Crystler";
		model = "Pacifica";
		year = 2006;
		speed = 0;
		direction = 'N';
		driverIn = false;
		stopStart = false;
	}

	void print(){
		if (driverIn) { 
			cout << "You are in a " << year << ", " << color << " " << make << " " << model << ". It is moving at " << speed << "mph and the compass says " << direction << ".";
		}
		else { 
			cout << "Your car is a " << year << ", " << color << " " << make <<" " << model << " and the compass says " << direction << ".";
		}
	}
};

void logic(char in, Car &a) {
	string temp;
	int tempint;
	//set make
	if (in == 'm' || in == 'M') {
		cout << "\nPlease enter the cars make\n";
		getline(cin, temp);
		a.make = temp;
		cout << "Your cars make is now :" << a.make << endl;
	}
	//set model
	else if (in == 'o' || in == 'O') {
		cout << "\nPlease enter the cars model\n";
		getline(cin, temp);
		a.model = temp;
		cout << "Your cars model is now :" << a.model << endl;
	}
	//set year
	else if (in == 'y' || in == 'Y') {
		cout << "\nPlease enter the cars year\n";
		cin >> tempint;
		a.year = tempint;
		cout << "Your cars make is year :" << a.year << endl;
	}
	//start or stop car
	else if (in == 's' || in == 'S') {
		if (a.speed == 0 && a.driverIn) {
			if (a.stopStart) {
				a.stopStart = false;
				cout << "Your car is now stopped.\n";
			}
			else {
				a.stopStart = true;
				cout << "Your car is now started.\n";
			}
		}
		else {
			cout << "The car should be stopped and driver inside before starting or stopping.\n";
		}
	}
	//drive car
	else if (in == 'd' || in == 'D') {
		if (a.speed == 0) {
			if (a.driverIn) {
				a.driverIn = false;
				cout << "You get out of the car.\n";
			}
			else {
				a.driverIn = true;
				cout << "You get in to the car.\n";
			}
		}
		else {
			cout << "The car should be stopped before exiting.\n";
		}
	}
	//speed up
	else if (in == 'a' || in == 'A') {
		if (a.stopStart && a.driverIn) {
			a.speed += 10;
			cout << "Your car is now moving at " << a.speed << " mph.\n";
		}
	}
	//brake
	else if (in == 'b' || in == 'B') {
		if (a.stopStart && a.driverIn) {
			if (a.speed > 10){
				a.speed -= 10;
				cout << "Your car is now moving at " << a.speed << " mph.\n";
			}
			else {
				cout << "You are stopped\n";
			}
		}
	}
	//print out car
	else if (in == 'p' || in == 'P') {
		a.print();
	}
	//turn left
	else if (in == 'l' || in == 'L') {
		if(a.stopStart && a.driverIn && a.speed > 10){
			if (a.direction == 'N') {
				a.direction = 'W';
				cout << "You are now pointing " << a.direction << endl;
			}
			else if (a.direction == 'W') {
				a.direction = 'S';
				cout << "You are now pointing " << a.direction << endl;
			}
			else if (a.direction == 'S') {
				a.direction = 'E';
				cout << "You are now pointing " << a.direction << endl;
			}
			else if (a.direction == 'E') {
				a.direction = 'N';
				cout << "You are now pointing " << a.direction << endl;
			}

		}
		else { 
			cout << "You must be moving to turn. \n";
		}
	}
	//turn right
	else if (in == 'r' || in == 'R') {
		if (a.stopStart && a.driverIn && a.speed > 10) {
			if (a.direction == 'N') {
				a.direction = 'E';
				cout << "You are now pointing " << a.direction << endl;
			}
			else if (a.direction == 'E') {
				a.direction = 'S';
				cout << "You are now pointing " << a.direction << endl;
			}
			else if (a.direction == 'S') {
				a.direction = 'W';
				cout << "You are now pointing " << a.direction << endl;
			}
			else if (a.direction == 'W') {
				a.direction = 'N';
				cout << "You are now pointing " << a.direction << endl;
			}

		}
		else {
			cout << "You must be moving to turn. \n";
		}
	}
	//eject
	else if (in == 'e' || in == 'E') {
		if (a.stopStart && a.driverIn && a.speed > 50) {
			cout << "You eject from the car, watching as it careens off a cliff and explodes in a fireball.";
			a.color = "burned";
			a.make = "hunk of";
			a.model = "metal";
			a.year = 2018;
			a.speed = 0;
			a.direction = 'N';
			a.driverIn = false;
			a.stopStart = false;

		} 
		else { cout << "You must be going fast enough to eject.\n"; }

	}
	//exit
	else if (in == 'x' || in == 'X') {

	}
	else {
		cout << "Invalid command.";
	}
}

int main() {
	if (DEBUG) { cout << "Debug is on."; }
	char input = 'y';
	string temp;
	Car one;
	one.default();

	do {
		//get input from user
		cout << "\nSelect an action:\n(M)Set make\n(O)Set model\n(Y)Set year\n(S)Start or stop car\n(D)Dive your car\n(A)Speed up\n(B)Brake\n(P)Print\n(L)Turn left\n(R)Turn right\n(E)Eject!\n(X)Exit\n\nWhat would you like to do?\n";
		getline(cin, temp);
		input = temp[0];
		logic(input, one);

	} while (input != 'x' && input != 'X');
	
	return 0;
}


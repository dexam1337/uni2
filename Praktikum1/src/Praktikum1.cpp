//============================================================================
// Name        : Praktikum1.cpp
// Author      : Sebastian Schuch
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "PrioQueue.h"
#include "Ticket.h"
using namespace std;

bool menue();

int main() {

	return 0;
}

bool menue(PrioQueue<Ticket> queue) {
	cout << "1. new ticket \n2. clear \n3. next \n4. EXIT \n" << endl;
	int input;
	Ticket t;
	cin >> input;
	switch (input) {
	case 1:

		return 1;
	case 2:
		queue = new PrioQueue<Ticket>();
		return 1;
	case 3:
		t = queue.pop();
		t.print();
		return 1;
	case 4:
		return 0;
	default:
		cout << "Invalid input. Exiting"
		return 0;
	}
	return 0;
}

//============================================================================
// Name        : Praktikum1.cpp
// Author      : Sebastian Schuch
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "PrioQueue.h"
using namespace std;

bool menue(PrioQueue* queue) {
	cout << "1. new ticket \n2. clear \n3. next \n4. EXIT \n" << endl;
	int input;
	cin >> input;
	Ticket t ;
	switch (input) {
	case 1:

		return 1;
	case 2:
		queue = new PrioQueue();
		return 1;
	case 3:
		t = queue->pop();
		t.print();
		return 1;
	case 4:
		return 0;
	default:
		cout << "Invalid input. Exiting";
		return 0;
	}
	return 0;
}

int main() {
	PrioQueue queue = new PrioQueue();
	queue.push(new Ticket("Seb","Alleadsj. asedl. asdasd . asdi . asdasd. . . asd ... asdasd."));
	queue.push(new Ticket("Du", "Tolle Arbeit! :)."));
	queue.push(new Ticket("Du", "Einfach mal ein Satz ohne Punkt!"));
	queue.push(new Ticket("Er", ""));
	while (menue(queue))
		;
	return 0;
}

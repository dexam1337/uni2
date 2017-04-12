/*
 * PrioQueue.h
 *
 *  Created on: 04.04.2017
 *      Author: sebastian
 */

#include <vector>
#include "Ticket.h"
using namespace std;

#ifndef PRIOQUEUE_H_
#define PRIOQUEUE_H_

class PrioQueue{
private:
	vector<Ticket> m_obj;

public:
	PrioQueue();
	void push(Ticket* newObj);
	Ticket* pop();
	//T get(int i);
};



#endif /* PRIOQUEUE_H_ */

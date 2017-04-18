/*
 * PrioQueue.h
 *
 *  Created on: 04.04.2017
 *      Author: sebastian
 */

#include <vector>

using namespace std;

#ifndef PRIOQUEUE_H_
#define PRIOQUEUE_H_



template<class T>
class PrioQueue{
private:
	vector<T> m_obj;

public:
	PrioQueue();
	void push(T newObj);
	T pop();
	//T get(int i);
};



#endif /* PRIOQUEUE_H_ */
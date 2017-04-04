/*
 * PrioQueue.cpp
 *
 *  Created on: 04.04.2017
 *      Author: sebastian
 */

#include "PrioQueue.h"

template<class T>
PrioQueue<T>::PrioQueue(){
	m_obj = new vector<T>();
}

template<class T>
void PrioQueue<T>::push(T newObj){
	m_obj.push_back(newObj);
}

template<class T>
T PrioQueue<T>::pop(){
	T obj = m_obj.front();
	m_obj.erase(m_obj.begin());
	return obj;
}

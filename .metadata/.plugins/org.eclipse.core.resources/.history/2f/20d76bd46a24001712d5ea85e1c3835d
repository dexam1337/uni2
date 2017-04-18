/*
 * Ticket.cpp
 *
 *  Created on: 04.04.2017
 *      Author: sebastian
 */

#include "Ticket.h"



Ticket::Ticket() {
	m_text = "NULL";
	m_owner = "NOONE";
	m_status = invalid;
	m_id = id_counter;

	id_counter++;
}

Ticket::Ticket(string ownerName, string description) {
	m_text = description;
	m_owner = ownerName;
	m_status = open;
	m_id = id_counter;

	id_counter++;
}

string Ticket::getText() const{
	return m_text;
}

string Ticket::getOwner() const{
	return m_owner;
}

int Ticket::getId() const{
	return m_id;
}

Status Ticket::getStatus() const{
	return m_status;
}

string Ticket::getShort() const{
	return m_text.substr(0,m_text.find('.'));
}

string Ticket::getStatusAsString() const /*throw(string)*/ {
	switch(m_status){
	case 0:
		return "open";
	case 1:
		return "closed";
	case 2:
		return "duplicate";
	default:
		//throw "Invalid type";
		return "NONE";
	}
}

void Ticket::print() const{
	cout << "ID: " << m_id << "\nStatus: " << getStatusAsString() << "\nErsteller: " << m_owner << "\n" << m_text << endl;
}


/*************************************************
* ADS Praktikum 1.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:
Ring::Ring(){
	int m_countNodes = 0;
	RingNode* m_anker = nullptr;
}

Ring::~Ring() {
}

void Ring::addNewNode(std::string beschreibung, std::string daten){
/*	if(this->m_countNodes == 0) {
		m_anker->setDescription(beschreibung);
		m_anker->setSymbolicData(daten);
		m_anker->setOldAge(0);
		m_countNodes++;
	} else if(this->m_countNodes < 6) {
		RingNode* tmp = m_anker;
		RingNode* newNode = new RingNode();
		newNode->setDescription(beschreibung);
		newNode->setSymbolicData(daten);
		newNode->setOldAge(0);
		
		while(tmp->getNext() != m_anker) {
			tmp->setOldAge(tmp->getOldAge() + 1);
			tmp = tmp->getNext();
		}

		tmp->setOldAge(tmp->getOldAge() + 1);
		newNode->setNext(m_anker->getNext());
		m_anker->setNext(newNode);
		m_anker = newNode;
		m_countNodes++;
	}*/
}

bool Ring::search(std::string daten){
	/*RingNode* tmp = m_anker;
	RingNode* searchNode = new RingNode();
	searchNode->setSymbolicData(daten);
	for(int i = 0; i < m_countNodes; i++){
		if(tmp->getSymbolicData() == searchNode->getSymbolicData()) {
			return true;
		} else {
			tmp->getNext();
		}
		return false;
	}*/
	return true;
}

void print(){
	std::cout << "print die Daten Bro";
}

//
////////////////////////////////////
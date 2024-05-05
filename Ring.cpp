/*************************************************
* ADS Praktikum 1.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:
Ring::Ring() : m_countNodes(0), m_anker(nullptr){

}

Ring::~Ring() {
    RingNode* tmp = m_anker;
    RingNode* delNode;
    for(int i = 0; i < m_countNodes; i++) {
        delNode = m_anker->getNext();
        m_anker->setNext(delNode->getNext());
        delete delNode;
    }
}

void Ring::addNewNode(std::string description, std::string data){
	if(this->m_countNodes == 0) {
		m_anker = new RingNode();
		m_anker->setDescription(description);
		m_anker->setSymbolicData(data);
		m_anker->setOldAge(0);
		m_anker->setNext(m_anker);
		m_countNodes++;
	} else if(this->m_countNodes < 6) {
		RingNode* tmp = m_anker;
		RingNode* newNode = new RingNode();
		newNode->setDescription(description);
		newNode->setSymbolicData(data);
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
	}
}

bool Ring::search(std::string data){
	RingNode* tmp = m_anker;
	RingNode* searchNode = new RingNode();
	searchNode->setSymbolicData(data);
	for(int i = 0; i < m_countNodes; i++){
		if(tmp->getSymbolicData() == data) {
            std::cout << "gefunden";
			return true;
		} else {
			tmp->getNext();
		}
        std::cout << "nicht gefunden";
		return false;
	}
    return false;
}



void print(){
	std::cout << "print die Daten Bro";
}

//
////////////////////////////////////
/*************************************************
* ADS Praktikum 1.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:

Ring::~Ring() {
    // RingNode* tmp = m_anker;
    // RingNode* delNode;
    // for(int i = 0; i < m_countNodes; i++) {
    //     delNode = m_anker->getNext();
    //     m_anker->setNext(delNode->getNext());
    //     delete delNode;
    // }
}

// void Ring::addFirstNode(std::string description, std::string data){
// 		//Listenanfang/leerer Puffer
// 		m_countNodes++;
// 		m_anker->setNext(m_anker);
// 		std::cout << "addfirstnode hinzugefügt" << std::endl;
// }

// void Ring::addNode(std::string description, std::string data){
// 		//weder leere oder volle Liste
// 		newNode->setNext(m_anker->getNext());
// 		RingNode* tmp = newNode;

// 		while(tmp->getNext() != m_anker) {
// 			tmp = tmp->getNext();
// 			tmp->setOldAge(tmp->getOldAge() + 1);
// 		}

// 		tmp->setNext(newNode);
// 		m_anker = newNode;
// 		m_countNodes++;

// }

// void Ring::addLastNode(std::string description, std::string data){
// 		//Puffer voll
// 		newNode->setNext(m_anker->getNext());
// 		RingNode* tmp = newNode;

// 		do{
// 			tmp->setOldAge(tmp->getOldAge()+1);
// 			tmp = tmp->getNext();
// 		}while(tmp->getNext() != m_anker);
// 		delete m_anker->getNext();
// 		m_anker->setNext(newNode);
// 		m_anker = newNode;
// }



void Ring::addNewNode(std::string description, std::string data){
	RingNode* newNode = new RingNode(0, description, data);
    //Falls die Liste leer ist

    if(m_anker == nullptr)
    {
        m_anker = newNode;
        newNode->setNext(newNode);
        m_countNodes++;
        return;
    }

    // Falls die list voll ist

    if(m_countNodes == 6)
    {
        newNode->setNext(m_anker->getNext()->getNext());
        RingNode* tmp = newNode;
        do
        {
            tmp = tmp->getNext();
            tmp->setOldAge(tmp->getOldAge()+1);
        } while (tmp != m_anker);
        delete m_anker->getNext();
        m_anker->setNext(newNode);
        m_anker = newNode;
        return;
    }

    //Falls liste weder voll, noch leer ist

    newNode->setNext(m_anker->getNext());
    RingNode* tmp = newNode;
    do
    {
        tmp = tmp->getNext();
        tmp->setOldAge(tmp->getOldAge()+1);
    } while (tmp != m_anker);
    tmp->setNext(newNode);
    m_anker = newNode;
    m_countNodes++;
    return;
}

bool Ring::search(std::string data){
	RingNode* tmp = m_anker;
	do{
		if(tmp->getSymbolicData() == data) {
			std::cout << tmp->getSymbolicData() <<" gefunden." << std::endl;
			return true;
		} else {
			std::cout << "am suchen.. " << std::endl;
		}
		tmp = tmp->getNext();
	}while(tmp != m_anker);
	std::cout << "nicht gefunden" << std::endl;
    return false;
}



void Ring::print(){
	std::cout << "print die Daten Bro" << std::endl;

	RingNode* tmp = m_anker;
    do
    {
        tmp = tmp->getNext();
        std::cout << "alter: " << tmp->getOldAge() 
		<< " beschreibung: " << tmp->getDescription() 
		<< " data: " << tmp->getSymbolicData() << std::endl;
    } while (tmp != m_anker);
}

//
////////////////////////////////////
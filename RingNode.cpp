/*************************************************
* ADS Praktikum 1.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"

////////////////////////////////////
// Ihr Code hier:
    
RingNode::RingNode(){
	int m_oldAge = 0;
	std::string m_description = "";
	std::string m_symbolicData = "";
	RingNode* m_next = nullptr;
}

RingNode::RingNode(int oldAge, std::string description, std::string data){
	int m_oldAge = oldAge;
	std::string m_description = description;
	std::string m_symbolicData = data;
	RingNode* m_next = nullptr;
}

RingNode::~RingNode(){
}

int RingNode::getOldAge(){
	return this->m_oldAge;
}

void RingNode::setOldAge(int oldAge){
	this->m_oldAge = oldAge;
}

std::string RingNode::getSymbolicData(){
	return this->m_symbolicData;
}

void RingNode::setSymbolicData(std::string data){
	this->m_symbolicData = data;
}

RingNode* RingNode::getNext(){
	return this->m_next;
}

void RingNode::setNext(RingNode* node){
	node = node->m_next;
}
// 
////////////////////////////////////
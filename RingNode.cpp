/*************************************************
* ADS Praktikum 1.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"

////////////////////////////////////
// Ihr Code hier:
   
RingNode::RingNode(): m_oldAge(0), m_description(""), m_symbolicData(""), m_next(nullptr){
	
}

RingNode::RingNode(int oldAge, std::string description, std::string data):
 m_oldAge{ oldAge }, m_description{ description }, m_symbolicData {data}, m_next {nullptr}{
}

RingNode::~RingNode(){
}

int RingNode::getOldAge(){
	return this->m_oldAge;
}

void RingNode::setOldAge(int oldAge){
	this->m_oldAge = oldAge;
}

std::string RingNode::getDescription(){
    return this->m_description;
}

void RingNode::setDescription(std::string description){
    this->m_description = description;
}

std::string RingNode::getSymbolicData(){
	return this->m_symbolicData;
}

void RingNode::setSymbolicData(std::string data){
	m_symbolicData = data;
}

RingNode* RingNode::getNext(){
	return this->m_next;
}

void RingNode::setNext(RingNode* node){
	m_next = node;
}
// 
////////////////////////////////////
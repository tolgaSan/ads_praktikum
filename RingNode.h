/*************************************************
* ADS Praktikum 1.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode{
	
private:
	//
	int m_oldAge;
	std::string m_description;
	std::string m_symbolicData;
	RingNode* m_next;
	//	
public:
	//
	RingNode();
	RingNode(int, const std::string, const std::string);
	~RingNode();

	int getOldAge();
	void setOldAge(int);
	std::string getDescription();
	void setDescription(std::string);
	std::string getSymbolicData();
	void setSymbolicData(std::string);
	RingNode* getNext();
	void setNext(RingNode*); 
	//
};

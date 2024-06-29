/*************************************************
* ADS Praktikum 3
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"


class Tree {
	
private: 
	TreeNode * m_anker;
	int m_CurrentNodeChronologicalID;
			
public:
	Tree();
	bool addNode(std::string Name, int Age, double Income, int PostCode);	
	bool searchNode(std::string);
	void printAll();
	
	// friend-Funktionen sind f�r die Tests erforderlich und m�ssen unangetastet bleiben! 
	friend TreeNode * get_anker(Tree& TN);
};

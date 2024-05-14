/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////
// Ihr Code hier:

TreeNode::TreeNode(int    nNodePos,
                   int    id,
                   string name,
                   int    alter,
                   double einkommen,
                   int    plz){
    this->m_NodeOrderID	= nNodePos;
    this->m_NodeChronologicalID = id;
    this->m_Name = name;
    this->m_Age	= alter;
    this->m_Income = einkommen;
    this->m_PostCode = plz;
    this->m_left = nullptr;
    this->m_right = nullptr;
}
/*
TreeNode::~TreeNode() {
    if (m_left) delete m_left;
    if (m_right) delete m_right;
}
*/


void TreeNode::setNodeOrderID(int age, int income, int postCode){
    this->m_NodeOrderID = age+income+postCode;
}
void TreeNode::setNodeChronologicalID(int m_NodeChronologicalID){
    this->m_NodeChronologicalID = m_NodeChronologicalID;
}
void TreeNode::setName(string name){
    this->m_Name = name;
}
void TreeNode::setAge(int age){
    this->m_Age = age;
}
void TreeNode::setIncome(double income){
    this->m_Income = income;
}
void TreeNode::setPostCode(int postCode){
    this->m_PostCode = postCode;
}
void TreeNode::setLeft(TreeNode* treeLeftNode){
    this->m_left = treeLeftNode;
}
void TreeNode::setRight(TreeNode* treeRigthNode){
    this->m_right = treeRigthNode;

}

int TreeNode::getNodeOrderID(){
    return this->m_NodeOrderID;
}
int TreeNode::getNodeChronologicalID(){
    return this->m_NodeChronologicalID;
}
string TreeNode::getName(){
    return this->m_Name;
}
int TreeNode::getAge(){
    return this->m_Age;
}
double TreeNode::getIncome(){
    return this->m_Income;
}
int TreeNode::getPostCode(){
    return this->m_PostCode;
}
TreeNode* TreeNode::getLeft(){
    return this->m_left;
}
TreeNode* TreeNode::getRight(){
    return this->m_right;
}


void TreeNode::print(){
    cout << "name: " << m_Name << " - age: " << m_Age << " - income: " << m_Income << " - postCode: " << m_PostCode << endl;
}


//
////////////////////////////////////

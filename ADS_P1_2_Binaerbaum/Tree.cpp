/*************************************************
 * ADS Praktikum 1.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include <iostream>
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <queue>
using namespace std;

////////////////////////////////////
// Ihr Code hier:
Tree::Tree(): m_anker(nullptr), m_currentNodeChronologicalID(0) {

}
Tree::~Tree() {
    if(m_anker == nullptr) return;
    while(m_anker != nullptr) {
        TreeNode* delNode = m_anker;
        if(m_anker->getLeft() == nullptr && m_anker->getRight() == nullptr) break;

        while(true) {
            if(delNode->getLeft() != nullptr){
                delNode = delNode->getLeft();
            } else if(delNode->getRight() != nullptr) {
                delNode = delNode->getRight();
            } else if(delNode->getLeft() && delNode->getRight() == nullptr) {
                delete delNode;
                break;
            }
        }
        delete m_anker;
    }
}
    
void Tree::addNode(string name, int age, double income, int postCode){
    
    int nodeOrderID = age + income + postCode;

    TreeNode* newTreeNode = new TreeNode(nodeOrderID, m_currentNodeChronologicalID, name, age, income, postCode);
    TreeNode* parent = m_anker;
    TreeNode* child;

    // Fall Baum leer
    if(m_anker == nullptr){
        m_anker = newTreeNode;
    } 
    //Fall Baum nicht leer
    //Wenn NodeOrder kleiner als parent, dann links. Ansonsten rechts
    else {
        if(m_anker->getNodeOrderID() > newTreeNode->getNodeOrderID()) {
            child = parent->getLeft();
        }
        else {
            child = parent->getRight();
        }
        //tmperse bis zum Blatt
        while(child != nullptr) {
            parent = child;

            if(child->getNodeOrderID() > newTreeNode->getNodeOrderID()) {
                child = child->getLeft();
            } else {
                child = child->getRight();
            }
        }

        if(parent->getNodeOrderID() > newTreeNode->getNodeOrderID()) {
            parent->setLeft(newTreeNode);
        } else {
            parent->setRight(newTreeNode);
        }
        //Eventuell Stack hinzufügen?

        tree.push_back(newTreeNode);
        m_currentNodeChronologicalID++;
    }
}



bool Tree::deleteNode(int nodeOrderID){

    for(auto start = tree.begin(); start != tree.end();){
        if((*start)->getNodeOrderID() == nodeOrderID){
            tree.erase(start); 
        } else ++start;
    } 
    //tmp stellt den aktuellen Verweis dar. Parent zeigt auf den Elternknoten des aktuellen Knotens
    TreeNode* tmp = m_anker;
    TreeNode* parent = nullptr;

    while (tmp != nullptr && tmp->getNodeOrderID() != nodeOrderID) {
        parent = tmp;
        if(tmp->getNodeOrderID() > nodeOrderID){
            tmp = tmp->getLeft();
        } else {
            tmp = tmp->getRight();
        }
    }

    //Falls nicht fündig
    if(tmp == nullptr) return false;

    //Kein Nachfolger
    if(tmp->getLeft() == nullptr && tmp->getRight() == nullptr){
        if(parent == nullptr) m_anker = nullptr;
        else {
            if(parent->getLeft() == tmp) parent->setLeft(nullptr);
            else parent->setRight(nullptr);
        }
        delete tmp;
        cout << "ist gelöscht!" << endl;
        m_currentNodeChronologicalID--;
        return true;
    //ein Nachfolger entweder links oder rechts
    } else if((tmp->getLeft() == nullptr && tmp->getRight() != nullptr) || (tmp->getLeft() != nullptr && tmp->getRight() == nullptr)) {
        //Changer stellt den ersetzer dar (von childChild zu parent)
        TreeNode* changer;

        if(tmp->getLeft() != nullptr) changer = tmp->getLeft();
        else changer = tmp->getRight();

        if(parent == nullptr) m_anker = changer;
        else{
            if(parent->getLeft() == tmp) parent->setLeft(changer);
            else parent->setRight(changer);
        }
        delete tmp;
        cout << "ist gelöscht!" << endl;
        m_currentNodeChronologicalID--;
        return true;
    //2 Nachfolger
    } else {
        TreeNode* parentMinNode;
        TreeNode* minNode;
        parentMinNode = tmp;
        minNode = tmp->getRight();

        while(minNode->getLeft() != nullptr) {
            parentMinNode = minNode;
            minNode = minNode->getLeft();
        }

        minNode->setLeft(tmp->getLeft());

        if(parentMinNode != tmp) {
            parentMinNode->setLeft(minNode->getRight());
            minNode->setRight(tmp->getRight());
        } 
        if(parent == nullptr) m_anker = minNode;
        else {
            if(parent->getLeft() == tmp) parent->setLeft(minNode);
            else parent->setRight(minNode);
        }
        cout << "ist gelöscht!" << endl;
        delete tmp;
        m_currentNodeChronologicalID--;
        return true;
    }
}

bool found = false;
bool Tree::searchNode(string name){
    /**/
    if(m_anker == nullptr) {
        cout << "Liste ist leer!";
        return false;
    }
    if(m_anker != nullptr) {
        searchNodeHilfsFunktion(m_anker,name);
    }
    if(!found) {
        cout << "Nicht gefunden!";
        return false;
    }
    found = false; 
    cout << "gefunden!";
    return true;

}

void Tree::searchNodeHilfsFunktion(TreeNode* treeNode, string name) {
    if(treeNode->getName() == name) found = true;
    if(treeNode->getLeft() != nullptr) searchNodeHilfsFunktion(treeNode->getLeft(), name);
    if(treeNode->getRight() != nullptr) searchNodeHilfsFunktion(treeNode->getRight(), name);
}



void Tree::levelOrder(){
    TreeNode* root = m_anker;
    queue<TreeNode*> treeLevelOrder;
    queue<int> level;

    //Fall Baum leer
    if(root == nullptr) return;

    //ansetzen
    treeLevelOrder.push(root);
    level.push(0);

    int prev = -1;
    int current = 0;
    cout << setw(4) << "ID " << "|"
        << setw(20) << "Name: " << "|"
        << setw(8) << "Age: "<< "|"
        << setw(8) << "Income: "<< "|"
        << setw(10) << "PostCode: "<< "|"
        << setw(15) << "NodeOrderID: "<< "|"
        << setw(5) << "Level: " << endl; 
    while (!treeLevelOrder.empty()) {
        TreeNode* s = treeLevelOrder.front();
        treeLevelOrder.pop();
        current = level.front();
        level.pop();

        if(prev != current) prev = current;
        
        cout 
        << setw(4) << s->getNodeChronologicalID() << "|"
        << setw(20) << s->getName() << "|"
        << setw(8) << s->getAge()<< "|"
        << setw(8) << s->getIncome()<< "|"
        << setw(10) << s->getPostCode()<< "|"
        << setw(15) << s->getNodeOrderID()<< "|"
        << setw(5) << current << endl;
        

        if(s->getLeft() != nullptr) {
            treeLevelOrder.push(s->getLeft());
            level.push(current+1);
        }
        if(s->getRight() != nullptr) {
            treeLevelOrder.push(s->getRight());
            level.push(current+1);
        }
    }
    return;
}



 void Tree::printLevelOrder(){
     levelOrder();
 }

// //
////////////////////////////////////

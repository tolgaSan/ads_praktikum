/*************************************************
 * ADS Praktikum 1.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

////////////////////////////////////
// Ihr Code hier:
Tree::Tree(): m_anker(nullptr), m_currentNodeChronologicalID(counter) {

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
        //Traverse bis zum Blatt
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
        counter++;
    }
}



bool Tree::deleteNode(int nodeOrderID){

    for(auto start = tree.begin(); start != tree.end();){
        if((*start)->getNodeOrderID() == nodeOrderID){
            tree.erase(start); 
            return true;
        } else ++start;
    } 

    TreeNode* trav = m_anker;
    TreeNode* parent = nullptr;

    while (trav != nullptr && trav->getNodeOrderID() != nodeOrderID) {
        parent = trav;
        if(trav->getNodeOrderID() > nodeOrderID){
            trav = trav->getLeft();
        } else {
            trav = trav->getRight();
        }
    }

    //Falls nicht fündig
    if(trav == nullptr) return false;

    //Kein Nachfolger
    if(trav->getLeft() == nullptr && trav->getRight() == nullptr){
        if(parent == nullptr) m_anker = nullptr;
        else {
            if(parent->getLeft() == trav) parent->setLeft(nullptr);
            else parent->setRight(nullptr);
        }
        delete trav;
        counter--;
        return true;
    //ein Nachfolger entweder links oder rechts
    } else if((trav->getLeft() == nullptr && trav->getRight() != nullptr) || (trav->getLeft() != nullptr && trav->getRight() == nullptr)) {
        TreeNode* changer;

        if(trav->getLeft() != nullptr) changer = trav->getLeft();
        else changer = trav->getRight();

        if(parent == nullptr) m_anker = changer;
        else{
            if(parent->getLeft() == trav) parent->setLeft(changer);
            else parent->setRight(changer);
        }
        delete trav;
        counter--;
        return true;
    //2 Nachfolger
    } else {
        TreeNode* parentMinNode;
        TreeNode* minNode;
        parentMinNode = trav;
        minNode = trav->getRight();

        while(minNode->getLeft() != nullptr) {
            parentMinNode = minNode;
            minNode = minNode->getLeft();
        }

        minNode->setLeft(trav->getLeft());

        if(parentMinNode != trav) {
            parentMinNode->setLeft(minNode->getRight());
            minNode->setRight(trav->getRight());
        } 
        if(parent == nullptr) m_anker = minNode;
        else {
            if(parent->getLeft() == trav) parent->setLeft(minNode);
            else parent->setRight(minNode);
        }
        delete trav;
        counter--;
        return true;
    }
}

bool Tree::searchNode(string name){
    vector<TreeNode*> trav;
    for(unsigned int i = 0; i < tree.size(); i++){
        if (tree[i]->getName() == name) trav.push_back(tree[i]);
    }
    if(trav.size() == 0) return false;
    else return true;

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
    while (!treeLevelOrder.empty()) {
        TreeNode* s = treeLevelOrder.front();
        treeLevelOrder.pop();
        current = level.front();
        level.pop();

        if(prev != current) prev = current;

        cout << setw(4) << s->getNodeChronologicalID() << " "
        << setw(20) << s->getName() << " " 
        << setw(8) << s->getAge() << " "
        << setw(8) << s->getIncome() << " "
        << setw(10) << s->getPostCode() << " "
        << setw(9) << s->getNodeOrderID() << " "
        << setw(5) << current << " " << endl;
        

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
//
////////////////////////////////////

/*************************************************
 * ADS Praktikum 1.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Tree
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode* m_anker = nullptr;
    static int counter;
    int m_currentNodeChronologicalID;

    vector<TreeNode*> tree;

    void printPreOrder(TreeNode* tree){
        if(tree != nullptr) {
            cout << tree->getNodeOrderID() << " - ";
            printInOrder(tree->getLeft());
            printInOrder(tree->getRight());
        }
    }
    void printInOrder(TreeNode* tree){
        if(tree != nullptr) {
            printInOrder(tree->getLeft());
            cout << tree->getNodeOrderID() << " - ";
            printInOrder(tree->getRight());
        }   
    }
    void printPostOrder(TreeNode* tree){
        if(tree != nullptr) {
            printInOrder(tree->getLeft());
            printInOrder(tree->getRight());
            cout << tree->getNodeOrderID() << " - ";
        }
    }
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree();
    ~Tree();
    void addNode(string, int, double, int);
    bool deleteNode(int);
    bool searchNode(string);
    void searchNodeHilfsFunktion(TreeNode*, string);
    void printAll(){
        cout << "1) für PreOrder " << endl
        << "2) für InOrder " << endl
        << "3) für PostOrder " << endl
        << "4) für Print All" << endl;
        int auswahl;
        cin >> auswahl;
        switch(auswahl) {
            case 1:
                printInOrder(m_anker);
                break;
            case 2:
                printPostOrder(m_anker);
                break;
            case 3: 
                printPreOrder(m_anker);
                break;
            case 4: 
                cout << "Inorder: ";
                printInOrder(m_anker);
                cout << endl << endl;
                cout << "PostOrder: ";
                printPostOrder(m_anker);
                cout << endl << endl;
                cout << "PreOrder ";
                printPreOrder(m_anker);
                cout << endl << endl;
                break;
            default:
                break;
        }

        
    }
    void levelOrder();
    void printLevelOrder();

    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};

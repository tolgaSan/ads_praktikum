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

    void printPreOrder(){}
    void printInOrder(){}
    void printPostOrder(){}
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
    void printAll() { 
        printPreOrder();
        printInOrder();
        printPostOrder();
    }
    void levelOrder();
    void printLevelOrder();

    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};

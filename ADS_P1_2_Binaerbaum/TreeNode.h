/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int m_NodeOrderID;
    int m_NodeChronologicalID;
    string m_Name;
    int m_Age;
    double m_Income;
    int m_PostCode;
    TreeNode* m_left;
    TreeNode* m_right;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode(int, int, string, int, double, int);
    TreeNode();


    void setNodeOrderID(int,int,int);
    void setNodeChronologicalID(int);
    void setName(string);
    void setAge(int);
    void setIncome(double);
    void setPostCode(int);
    void setLeft(TreeNode*);
    void setRight(TreeNode*);

    int getNodeOrderID();
    int getNodeChronologicalID();
    string getName();
    int getAge();
    double getIncome();
    int getPostCode();
    TreeNode* getLeft();
    TreeNode* getRight();


    void print();

    //
    ////////////////////////////////////
};

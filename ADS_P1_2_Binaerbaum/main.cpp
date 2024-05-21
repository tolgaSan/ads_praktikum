/*************************************************
 * ADS Praktikum 1.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:

/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV" 
 
Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/

void mainscreen_addTreeCSV(Tree*& ref)
{
    char j;
    cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
            "importieren(j / n) ? >";
    cin >> j;
    if (j == 'j')
    {
        ifstream csvread;
        csvread.open("ExportZielanalyse.csv", ios::in);
        if (!csvread.is_open())
        {
            cout << "Fehler beim Lesen!" << endl;
            return;
        }
        else
        {
            string name, age, postcode, income;

            while (!csvread.eof())
            {
                getline(csvread, name, ';');
                getline(csvread, age, ';');
                getline(csvread, income, ';');
                getline(csvread, postcode, '\n');
                ref->addNode(name, stoi(age), stod(income), stoi(postcode));
            }
            csvread.close();
        }
        cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
    }
}

Tree* tree = new Tree();

void menuAuswahl(){

    cout << endl << "1) Datensatz einfuegen, manuell" << endl
        << "2) Datensatz einfuegen, CSV Datei" << endl
        << "3) Datensatz loeschen" << endl
        << "4) Datensatz suchen" << endl 
        << "5) Datenstruktur anzeigen (pre/post/in)" << endl
        << "6) Level-Order Ausgabe" << endl
        << "7) Beenden" << endl;

    int auswahl;
    cin >> auswahl;
    string name;
    int age, income, postCode;
    int nodeOrderID;
    switch(auswahl) {
        case 1:
            cout << "Name: " << endl;
            cin  >> name;
            cout << "age: " << endl;
            cin >> age;
            cout << "income: " << endl;
            cin >> income;
            cout << "postCode: " << endl;
            cin >> postCode;
            tree->addNode(name, age, income, postCode);
            cout << "hinzugefuegt" << endl;
            menuAuswahl();
            break;
        case 2:
            cout << "[Programm um Datensatz zu importieren]" << endl;
            mainscreen_addTreeCSV(tree);
            menuAuswahl();
            break;
        case 3:
            cout << "welcher Datensatz soll gelöscht werden??? " << endl;
            cin >> nodeOrderID;
            tree->deleteNode(nodeOrderID);
            menuAuswahl();
            break;
        case 4:
            cout << "Welcher Datensatz soll gefunden werden???" << endl;
            cin >> name;
            tree->searchNode(name);
            menuAuswahl();
            break;
        case 5:
            tree->printAll();
            menuAuswahl();
            break;
        case 6:
            tree->printLevelOrder();
            menuAuswahl();
            break;
        case 7:
            cout << "[Einfach beenden]" << endl;
            return;
    }
}

int Tree::counter = 0;
//
///////////////////////////////////////
int main()
{

    int result = Catch::Session().run();
    ///////////////////////////////////////
    // Ihr Code hier:
    tree->addNode("A", 30, 50000, 12345);
    tree->addNode("B", 25, 60000, 23456);
    tree->addNode("C", 35, 70000, 34567);
    tree->addNode("d", 32, 12312, 12345);
    tree->addNode("E", 21, 31234, 23456);
    tree->addNode("F", 10, 30023, 34567);
    menuAuswahl();
    //
    ///////////////////////////////////////
    system("PAUSE");

    return 0;
}

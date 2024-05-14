/*************************************************
 * ADS Praktikum 1.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

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

void menuAusgabe(){

    cout << "1) Datensatz einfuegen, manuell" << endl
        << "2) Datensatz einfuegen, CSV Datei" << endl
        << "3) Datensatz loeschen" << endl
        << "4) Datensatz suchen" << endl 
        << "5) Datenstruktur anzeigen (pre/post/in)" << endl
        << "6) Level-Order Ausgabe" << endl
        << "Beenden" << endl;

    int auswahl;
    cin >> auswahl;
    switch(auswahl) {
        case '1':
            cout << "[Programm um Datensatz einfügen]" << endl;
            break;
        case '2':
            cout << "[Programm um Datensatz zu importieren]" << endl;
            break;
        case '3':
            cout << "[Programm Datensatz löschen]" << endl;
            break;
        case '4':
            cout << "[Programm Suchen]" << endl;
            break;
        case '5':
            cout << "[Datenstruktur anzeigen Programm]" << endl;
            break;
        case '6':
            cout << "[Level Order Ausgabe]" << endl;
            break;
        case '7':
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
    menuAusgabe();
    //
    ///////////////////////////////////////
    system("PAUSE");

    return 0;
}

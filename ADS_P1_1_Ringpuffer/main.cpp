/*************************************************
* ADS Praktikum 1.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

void print_menu()
{
    cout << "====================================" << endl
        << " SuperBackUp-Organizer over 9000, by. Son Goku" << endl
        << "====================================" << endl
        << "1) Backup anlegen" << endl
        << "2) Backup suchen" << endl
        << "3) Alle Backups ausgeben" << endl
        << "4) Programm beenden" << endl
        << "?> ";
}

Ring* ring = new Ring;    

void menu_auswahl(){
    cout << "====================================" << endl 
        << "Bitte waehle eine Ziffer (1, 2, 3, 4) aus!" << endl;

    char auswahl;
    cin >> auswahl;
    string beschreibung="", data="";
    switch (auswahl) {
        case '1':
            cout << "+Neuen Datensatz anlegen" << endl;
            cout << "Beschreibung ?> " << endl;
            cin >> beschreibung;
            cout << "Daten ?> " << endl;
            cin >> data;
            ring->addNewNode(beschreibung, data);
            cout << "Backup: " << "???" << "wurde hinzugefügt" << endl;
            menu_auswahl();
            break;   
        case '2':
            cout << "nach welchen Daten soll gesucht werden?" << endl;
            cout << "?> ";
            cin >> data;
            ring->search(data);
            menu_auswahl();
            break;
        case '3':
            cout << "[Programm einfügen, dass Datensätze nach Alter sortiert ausgibt]" << endl;
            ring->print(); 

            menu_auswahl();
            break;
        case '4':
            cout << "Programm wird durch die Auswahl '4' beendet"<<endl;
            break;
        default:
            cout << "Keine gültige Eingabe. Gültige Eingabe sind Ziffern 1-4" << endl;
            menu_auswahl();
            break;
    }

}

int main()
{
	int result = Catch::Session().run();
	// Ihr Code hier:
    print_menu();
    menu_auswahl();

	//
	///////////////////////////////////////
	system("Pause");
	return result;
}
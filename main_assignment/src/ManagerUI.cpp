#include "ManagerUI.h"


ManagerUI::ManagerUI()
{
    startUI();
}

ManagerUI::~ManagerUI()
{
    //dtor
}

void ManagerUI::startUI()
{
    char choice = '\0';
    while(choice != 'b') {
        system("CLS");
        cin.ignore();
        cout << "Manager: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Current orders |" << endl;
        cout << " |2. Old orders     |" << endl;
        cout << " |3. Edit menu      |" << endl;
        cout << " |4. Location       |" << endl;
        cout << " |5. Back           |" << endl;
        cout << " |6. Quit           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-6): ";

        choice = cin.get();



    }
}

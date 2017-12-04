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
    while(choice != '5') {
        system("CLS");
        cout << "Manager: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Current orders |" << endl;
        cout << " |2. Old orders     |" << endl;
        cout << " |3. Edit menu      |" << endl;
        cout << " |4. Location       |" << endl;
        cout << " |5. Back           |" << endl;
        cout << " +------------------+" << endl;

        cout << " (1-5): ";

        cin >> choice;

        if(choice == '1'){
            ///Current orders
        } else if(choice == '2') {
            ///Old orders
        } else if(choice == '3') {
            ///Edit menu
        } else if(choice == '4') {
            ///Location
        } else if (choice == '7') {
            ToppingUI toppingui;
            toppingui.startUI();
        }
    }
}

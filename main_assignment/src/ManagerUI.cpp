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
    char user1 = '\0';
    while(user1 != '5') {
        system("CLS");
        cout << "Manager: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Current orders |" << endl;
        cout << " |2. Old orders     |" << endl;
        cout << " |3. Edit menu      |" << endl;
        cout << " |4. Location       |" << endl;
        cout << " |5. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-6): ";

        cout << " (1-5): ";

        cin >> user1;

        if(user1 == '1'){
            ///Current orders
        } else if (user1 == '2') {
            ///Old orders
        } else if (user1 == '3') {
            ///Edit menu
        } else if (user1 == '4') {
            ///Location
        } else if (user1 == '7') {
            ToppingUI toppingui;
            toppingui.startUI();
        }

    }
}

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
<<<<<<< HEAD
        cout << " (1-6): ";

        cout << " (1-5): ";

        cin >> user1;

        if(user1 == '1'){
=======
        cout << " (1-5): ";

        choice = cin.get();

        if(choice == '1'){
>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
            ///Current orders
        } else if(choice == '2') {
            ///Old orders
        } else if(choice == '3') {
            ///Edit menu
        } else if(choice == '4') {
            ///Location
<<<<<<< HEAD
        } else if (user1 == '7') {
            ToppingUI toppingui;
            toppingui.startUI();
=======
>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
        }
    }
}

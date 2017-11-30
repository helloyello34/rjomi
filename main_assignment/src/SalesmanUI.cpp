#include "SalesmanUI.h"



SalesmanUI::SalesmanUI()
{
    startUI();
}

SalesmanUI::~SalesmanUI()
{
    //dtor
}

void SalesmanUI::startUI()
{
<<<<<<< HEAD
=======

>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
    char choice = '\0';
    while(choice != '3') {
        system("CLS");
        cout << "Salesman: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Orders         |" << endl;
        cout << " |2. Comments       |" << endl;
        cout << " |3. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-4): ";
        cin >> choice;

        if(choice == '1') {
            PizzaUI pizzaui;
            pizzaui.startUI();
        } else if(choice == '2') {
<<<<<<< HEAD

        }
=======

        }
>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
    }
}

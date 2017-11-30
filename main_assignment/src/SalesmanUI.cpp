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

        }
    }
}

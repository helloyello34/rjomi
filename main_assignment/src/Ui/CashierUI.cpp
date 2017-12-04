#include "CashierUI.h"

CashierUI::CashierUI()
{
    startUI();
}

CashierUI::~CashierUI()
{
    //dtor
}

void CashierUI::startUI()
{
    char choice = '\0';
    while(choice != '3') {
        system("CLS");
        cout << "Cashier: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Your location  |" << endl;
        cout << " |2. Charge order   |" << endl;
        cout << " |3. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-3): ";
        cin >> choice;
    }
}

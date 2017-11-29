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
    while(choice != 'b') {
    system("CLS");
    int choice;
    cout << "Cashier: " << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Your location  |" << endl;
    cout << " |2. Back           |" << endl;
    cout << " |3. Quit           |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-3): ";
    cin >> choice;
    }
}

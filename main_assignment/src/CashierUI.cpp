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
    while(choice != '2') {
    system("CLS");
    cout << "Cashier: " << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Your location  |" << endl;
    cout << " |2. Back           |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-3): ";
    cin >> choice;
    }
}

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
    while(choice != 'b') {
    system("CLS");
    int choice;
    cout << "Salesman: " << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Make order     |" << endl;
    cout << " |2. Charge order   |" << endl;
    cout << " |3. Comments       |" << endl;
    cout << " |4. Back           |" << endl;
    cout << " |5. Quit           |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-5): ";
    cin >> choice;
    }
}

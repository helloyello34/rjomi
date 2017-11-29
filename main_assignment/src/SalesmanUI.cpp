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
    char user = '\0';
    while(user != '4') {
    system("CLS");
    cout << "Salesman: " << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Make order     |" << endl;
    cout << " |2. Change order   |" << endl;
    cout << " |3. Comments       |" << endl;
    cout << " |4. Back           |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-4): ";
    cin >> user;


    if(user == '1'){
            ///Make Order
        } else if (user == '2') {
            ///Change order
        } else if (user == '3') {
            ///Comments
        }

    }
}

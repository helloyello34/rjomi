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
            OrderUI orders;
            orders.startUI();
        } else if(choice == '2') {

=======
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
>>>>>>> 9f470b07c31e34cd568712454043094db96f8835
        }

    }
}

#include "OrderUI.h"

OrderUI::OrderUI()
{

}

OrderUI::~OrderUI()
{
    //dtor
}

void OrderUI::startUI(){
    char choice = '\0';
    while(choice != '2') {
    system("CLS");
    cout << "Baker: " << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Your location  |" << endl;
    cout << " |2. Back           |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-2): ";
    cin >> choice;
    }
}

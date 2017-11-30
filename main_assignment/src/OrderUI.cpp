#include "OrderUI.h"

OrderUI::OrderUI()
{
    this->numberOfOrders = 0;
    this->orders = new Order[this->numberOfOrders];
}

OrderUI::~OrderUI()
{
    delete[] this->orders;
}

void OrderUI::startUI()
{
    char choice = '\0';
    while(choice != '4') {
        system("CLS");
        cout << "Order: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Show orders    |" << endl;
        cout << " |2. Make orders    |" << endl;
        cout << " |3. Change orders  |" << endl;
        cout << " |4. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-4): ";
        cin >> choice;

        if(choice == '1'){
            show_order();
        }else if(choice == '2'){
            make_order();
        }
    }
}

void OrderUI::make_order()
{
    /// Create a new order

}

void OrderUI::show_order()
{
    /// Show orders that have yet been carried out
}

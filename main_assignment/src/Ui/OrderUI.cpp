#include "OrderUI.h"

OrderUI::OrderUI()
{
    /// blyat
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
    Order order;
    cout << "What would you like to add to the Order?" << endl;
    cout << "1. Pizza " << endl;
    cout << "2. Sides " << endl;
    cout << "3. Drinks " << endl;
    cout << "4. Make pizza" << endl;

    char choise;
    try{
    cin >> choise;

    if(cin.fail()) {
        cin.clear();
        throw InvalidIdException();
    }
    switch (choise) {
    case '1':break;
    case '2':break;
    case '3':break;
    case '4':break;
    default:break;

    }


    } catch (InvalidIdException) {
        cout << "Error: Invalid id" << endl;
    }
}

void add_pizza()
{
    Pizza pizza;

}

void add_sides()
{

}

void add_drink()
{

}

void OrderUI::show_order()
{
    /// Show orders that have yet been carried out
}

#include "PizzaUI.h"

#include "Pizza.h"

using namespace std;


PizzaUI::PizzaUI()
{
    //ctor
}

PizzaUI::~PizzaUI()
{
    //dtor
}

void PizzaUI::startUI()
{
    char choice = '\0';
    while(choice != '3') {
        system("CLS");
        cout << "Pizza: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. View Pizzas    |" << endl;
        cout << " |2. Create Pizza   |" << endl;
        cout << " |3. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-3): ";
        cin >> choice;

        if(choice == '1') {
            /// View avaliable pizzas
        } else if (choice == '2') {
            Pizza pizza;
            cin >> pizza;
            cout << pizza;
            cin >> choice;
        }
    }
}

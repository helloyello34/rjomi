#include "PizzaUI.h"


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
        //system("CLS");
        cout << "Pizza: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. View Pizzas    |" << endl;
        cout << " |2. Create Pizza   |" << endl;
        cout << " |3. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-3): ";
        cin >> choice;

        if(choice == '1') {
            view_pizza_menu();
        } else if (choice == '2') {
            add_temp_pizza();
        }
    }
}



void PizzaUI::add_temp_pizza()
{
    Pizza pizza;
    cin >> pizza;
    cout << pizza;
    PizzaRepo pizzarepo;
    pizzarepo.write_pizza(pizza);
}


void PizzaUI::view_pizza_menu()
{
    retrieve_pizza();
    for(unsigned int i = 0; i < this->pizzas.size(); i++){
        cout << i + 1 << ". " <<  this->pizzas[i] << endl;
    }
}

void PizzaUI::retrieve_pizza()
{
    PizzaRepo fill_array;
    this->pizzas = fill_array.read_pizza();
}


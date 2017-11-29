#include "PizzaUI.h"

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

    char selection = '\0';

    while(selection != 'b') {
        cout << "m: make pizza" << endl;
        cout << "r: read pizza" << endl;
        cout << "q: back" << endl;
        cin >> selection;

        if(selection == 'm') {
            int topCnt;
            cout << "How many toppings: ";
            cin >> topCnt;

            Pizza pizza(topCnt);

            for(int i = 0; i < topCnt; i++) {

                Topping topping;
                cin >> topping;
                pizza.addTopping(topping);

            }

            PizzaRepository repo;
            repo.store_Pizza(pizza);
            cout << pizza;
        } else if (selection == 'r') {
            PizzaRepository repo;
            Pizza pizza = repo.retrieve_Pizza();
            cout << pizza;
            cout << endl;
        }
    }

}

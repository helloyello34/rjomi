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
    int topCnt;
    cout << "How many toppings: ";
    cin >> topCnt;

    Pizza pizza(topCnt);

    for(int i = 0; i < topCnt; i++){

        Topping topping;
        cin >> topping;
        pizza.addTopping(topping);

    }

    cout << pizza;
}

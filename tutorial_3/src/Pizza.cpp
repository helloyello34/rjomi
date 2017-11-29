#include "Pizza.h"

Pizza::Pizza()
{
    this->toppingCount = 0;
    this->toppings = NULL;
    this->currentToppingNum = 0;
}

Pizza::Pizza(int numberOfToppings)
{
    this->toppingCount = numberOfToppings;
    this->toppings = new Topping[this->toppingCount];
    this->currentToppingNum = 0;
}

Pizza::~Pizza()
{
    if(this->toppings != NULL) {
        delete[] this->toppings;
    }
}

void Pizza::addTopping(Topping topping)
{
    if(currentToppingNum < toppingCount) {
        this->toppings[this->currentToppingNum] = topping;
        this->currentToppingNum++;
    }
}

ostream& operator << (ostream& out, const Pizza& pizza)
{

    out << "Pizza with toppings: " << endl;

    for(int i = 0; i < pizza.toppingCount; i++) {
        out << pizza.toppings[i] << endl;
    }

    return out;
}

istream& operator >> (istream& in, Pizza& pizza)
{


    return in;
}

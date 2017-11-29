#include "Pizza.h"

Pizza::Pizza()
{
    this->toppingCount = 0;
    this->toppings = 0;
    this->currentToppingNum = 0;
}

Pizza::Pizza(int numberOfToppings)
{
    this->toppingCount = 0;
    this->toppings = 0;
    this->currentToppingNum = 0;
    init(numberOfToppings);
}

Pizza::~Pizza()
{
    this->toppingCount = 0;
    this->toppings = NULL;
    this->currentToppingNum = 0;
    clean_mem();
}

void Pizza::addTopping(Topping topping)
{
    if(currentToppingNum < toppingCount) {
        this->toppings[this->currentToppingNum] = topping;
        this->currentToppingNum++;
    }
}

void Pizza::init(int numberOfToppings)
{
    clean_mem();
    this->toppingCount = numberOfToppings;
    this->toppings = new Topping[this->toppingCount];
    this->currentToppingNum = 0;
}

void Pizza::clean_mem()
{
    if(this->toppings != 0) {
        delete[] this->toppings;
        this->toppingCount = 0;
        this->toppings = NULL;
        this->currentToppingNum = 0;
    }

}

ostream& operator << (ostream& out, const Pizza& pizza)
{

    //out << "Pizza with toppings: " << endl;
    out << pizza.toppingCount << " ";

    for(int i = 0; i < pizza.toppingCount; i++) {
        out << pizza.toppings[i] << endl;
    }

    return out;
}

istream& operator >> (istream& in, Pizza& pizza)
{
    in >> pizza.toppingCount;
    pizza.init(pizza.toppingCount);
    Topping topping;
    for(int i = 0; i < pizza.toppingCount; i++) {
        in >> topping;
        pizza.addTopping(topping);
    }

    return in;
}

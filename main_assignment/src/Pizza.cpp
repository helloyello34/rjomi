#include "Pizza.h"

Pizza::Pizza()
{
    this->numberOfToppings = 0;
}

Pizza::Pizza(int numberOfToppings)
{
    this->numberOfToppings = 0;
    clean_mem();
    this->numberOfToppings = numberOfToppings;
    if(this->numberOfToppings > 0){
        this->toppings = new Topping[this->numberOfToppings];
    }
    this->currentTopping = 0;
}

Pizza::~Pizza()
{
    clean_mem();
}


void Pizza::clean_mem()
{
    if(this->numberOfToppings != 0){
        delete[] toppings;
    }
}

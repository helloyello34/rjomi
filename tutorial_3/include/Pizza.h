#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include "Topping.h"

using namespace std;

class Pizza
{
    public:
        Pizza();
        Pizza(int numberOfToppings);
        ~Pizza();

        void addTopping(Topping topping);
        void init(int numberOfToppings);
        void clean_mem();

        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);
    private:
        Topping * toppings;
        int toppingCount;

        int currentToppingNum;
};

#endif // PIZZA_H

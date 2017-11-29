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

        virtual ~Pizza();

        void add_topping(int currentTopping);
        void clean_mem();

    private:
        Topping* toppings;
        int numberOfToppings;
        int currentTopping;
};

#endif // PIZZA_H

#ifndef PIZZAUI_H
#define PIZZAUI_H

#include <stdlib.h>
#include <iostream>

#include "Pizza.h"

class PizzaUI
{
    public:
        PizzaUI();
        virtual ~PizzaUI();
        void startUI();
    private:
        vector<Pizza>pizzas;
};

#endif // PIZZAUI_H

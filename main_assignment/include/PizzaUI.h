#ifndef PIZZAUI_H
#define PIZZAUI_H

#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Pizza.h"
#include "PizzaRepo.h"

class PizzaUI
{
    public:
        PizzaUI();
        virtual ~PizzaUI();
        void startUI();
        void add_temp_pizza();
        void view_pizza_menu();
        void retrieve_pizza();
    private:
        vector<Pizza>pizzas;
};

#endif // PIZZAUI_H

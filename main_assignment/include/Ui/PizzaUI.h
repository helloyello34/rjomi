#ifndef PIZZAUI_H
#define PIZZAUI_H

#include "ToppingUI.h"

#include "Pizza.h"
#include "PizzaService.h"

class PizzaUI
{
    public:
        PizzaUI();

        void add_pizza();
        void view_pizza();
        void edit_pizza();
        void delete_pizza();
        void input_pizza(Pizza& pizza);

        Pizza get_pizza(size_t id);
        size_t get_vector_size();

    private:
        vector<Pizza>pizzas;
        PizzaService pizza_service;
        ToppingUI topping_ui;
};

#endif // PIZZAUI_H

#ifndef PIZZAUI_H
#define PIZZAUI_H

#include "ToppingUI.h"

#include "Pizza.h"
#include "PizzaService.h"

class PizzaUI
{
public:
    PizzaUI();

    //////////////////////////////////
    /// Add pizza to the menu
    void add_pizza();

    /// View all avaliable pizzas on the menu
    void view_pizza();

    /// Edit/Change pizza on the menu
    void edit_pizza();

    /// Delete any avaliable pizzas on the menu
    void delete_pizza();

    /// Input toppings to pizza
    void input_pizza(Pizza& pizza);
    //////////////////////////////////

    //////////////////////////////////
    /// Returns a pizza from menu
    Pizza get_pizza(size_t id);

    /// Returns the number of pizzas on the menu
    size_t get_vector_size();
    //////////////////////////////////

private:
    vector<Pizza>pizzas;
    PizzaService pizza_service;
    ToppingUI topping_ui;
};

#endif // PIZZAUI_H

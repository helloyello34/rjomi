#ifndef TOPPINGUI_H
#define TOPPINGUI_H

#include <iostream>
#include <VECTOR>
#include <stdlib.h>

#include "ToppingService.h"
#include "Topping.h"

using namespace std;

class ToppingUI
{
    public:
        /// Constructor for toppingUI
        ToppingUI();

        /// Add new topping to menu
        void add_topping();

        /// View all avaliable toppings
        void view_topping();

        /// Delete toppings from menu
        void delete_topping();

        /// Edit/change abaliable toppings
        void edit_topping();

        /// Get toppings from file to vector
        void fill_topping_vector();

        /// Get the number of toppings in menu
        size_t get_topping_size();

        /// return topping in the seat id
        Topping getTopping(size_t id);
    private:
        vector<Topping>toppings;
        ToppingService topping_service;
};

#endif // TOPPINGUI_H

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
        ToppingUI();
        void add_topping();
        void view_topping();
        void delete_topping();
        void edit_topping();
        void fill_topping_vector();
        size_t get_topping_size();
//        void delete_topping();
//        void store_topping(Topping& newTop);
//        void retrive_topping();
//        void view_toppings();
//        void list_toppings();

        Topping getTopping(size_t id);
    private:
        vector<Topping>toppings;
        int numberOfToppings;
        ToppingService topping_service;
};

#endif // TOPPINGUI_H

#ifndef TOPPINGUI_H
#define TOPPINGUI_H

#include <iostream>
#include <VECTOR>

#include "ToppingRepo.h"
#include "Topping.h"

using namespace std;

class ToppingUI
{
    public:
        ToppingUI();
        virtual ~ToppingUI();
        void startUI();
        void add_new_topping();
        void delete_topping();
        void store_topping(Topping& newTop);
        void retrive_topping();
        void view_toppings();
        void list_toppings();

        Topping getTopping(int id);
    private:
        vector<Topping>toppings;
        int numberOfToppings;
};

#endif // TOPPINGUI_H

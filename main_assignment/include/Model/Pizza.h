#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <vector>

#include "Topping.h"
#include "ToppingUI.h"

using namespace std;

class Pizza
{
    public:
        Pizza();
        void read(fstream& file); // member function that reads in the pizza from file
        void write(fstream& file); // member function that writes the pizza in file
        void add_topping(Topping& topping);
        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);
    private:
        char name[32];
        int price;
        vector<Topping>toppings;
        ToppingUI top;

};

#endif // PIZZA_H

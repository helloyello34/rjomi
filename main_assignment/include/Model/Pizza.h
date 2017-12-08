#ifndef PIZZA_H
#define PIZZA_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>

#include "Topping.h"

#include "InvalidNameException.h"
#include "InvalidIdException.h"

using namespace std;

class Pizza
{
    public:
        Pizza();

        string get_name();
        double get_price();

        void write(ofstream& file);
        void read(ifstream& file);

        void clear_toppings();
        void add_topping(Topping& topping);

        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);
    private:
        char name[32];
        double price;
        vector<Topping>toppings;

};

#endif // PIZZA_H

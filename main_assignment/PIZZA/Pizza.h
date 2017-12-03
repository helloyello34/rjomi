#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <vector>
#include <fstream>



#include "../TOPPING/Topping.h"
#include "../TOPPING/ToppingUI.h"

using namespace std;

class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();
        void add_topping(Topping topping);
        void create_pizza();
        void make_pizza();
        void store_pizza();
        double get_price();
        void read(fstream& file);
        void write(fstream& file);

        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);

    private:
        vector<Topping>toppings;
        char name[32];
        double price;
};

#endif // PIZZA_H

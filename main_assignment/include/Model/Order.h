#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>

#include "Pizza.h"
#include "Sides.h"
#include "Drink.h"


/// Including Exceptions
#include "InvalidIdException.h"
#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "UnableToOpenFileException.h"

using namespace std;

class Order
{
    public:
        Order();
        void add_pizza(Pizza pizza);
        void add_drink(Drink drink);
        void add_sides(Sides side);
        friend istream& operator >> (istream& in, Order& order);
        friend ostream& operator << (ostream& out, const Order& order);
        virtual ~Order();
    private:
        double price;
        vector<Pizza>pizzas;
        vector<Drink>drinks;
        vector<Sides>sides;

};

#endif // ORDER_H

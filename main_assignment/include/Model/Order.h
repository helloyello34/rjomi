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
#include "Location.h"


/// Including Exceptions
#include "InvalidIdException.h"
#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "UnableToOpenFileException.h"
#include "InvalidPhoneNumberException.h"

using namespace std;

class Order
{
    public:
        Order();

        void add_phone_number(char* number);
        void add_pizza(Pizza& pizza);
        void add_drink(Drink& drink);
        void add_sides(Sides& side);
        void set_location(Location& location);

        string get_location();
        string get_phone();

        void read(ifstream& file);
        void write(ofstream& file);

        friend istream& operator >> (istream& in, Order& order);
        friend ostream& operator << (ostream& out, const Order& order);
    private:
        Location location;
        char phone[8];
        double price;
        vector<Pizza>pizzas;
        vector<Drink>drinks;
        vector<Sides>sides;

};

#endif // ORDER_H

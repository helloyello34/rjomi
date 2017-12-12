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
#include "InvalidCommentException.h"

using namespace std;

enum status {RECEVED = 1, PREP, OVEN, READY};

class Order
{
    public:
        Order();

        void add_phone_number(char* number);
        void add_pizza(Pizza& pizza);
        void add_drink(Drink& drink);
        void add_sides(Sides& side);

        void set_comment(char* comment);
        void set_location(Location& location);
        void set_paid(bool paid);
        void set_status(status orderstatus);

        string get_location();
        string get_phone();
        status get_status();
        bool get_paid();

        bool is_order_receved();

        void read(ifstream& file);
        void write(ofstream& file);

        friend istream& operator >> (istream& in, Order& order);
        friend ostream& operator << (ostream& out, const Order& order);
        friend bool operator == (Order& order1, Order& order2);
    private:
        Location location;
        char phone[8];
        char comment[255];
        double price;
        status orderStatus;
        bool paid;
        vector<Pizza>pizzas;
        vector<Drink>drinks;
        vector<Sides>sides;

};

#endif // ORDER_H

#ifndef ORDER_H
#define ORDER_H

/// Including Inbuilt classes to use in the other classes
/// such as OrderUI, OrderService, OrderRepository
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>

/// Including Model classes so you can add them to the order!
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

/// Enum for status on the order!
enum status {RECEVED = 1, PREP, OVEN, READY};

class Order
{
    public:
        Order();

        ///////////////////////////////////////////////////////
        /// changes the phone number
        void add_phone_number(char* number);
        /// adds pizza to vector in order
        void add_pizza(Pizza& pizza);
        /// adds drink to vector in order
        void add_drink(Drink& drink);
        /// adds side dish to vector in order
        void add_sides(Sides& side);
        ///////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////
        /// changes the comment on order
        void set_comment(char* comment);
        /// changes the location on order
        void set_location(Location& location);
        /// changes paid to true
        void set_paid(bool paid);
        /// changes status on order
        void set_status(status orderstatus);
        ///////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////
        /// returns the location on the order
        string get_location();
        /// returns the phone number on the order
        string get_phone();
        /// returns the status on the order
        status get_status();
        /// returns true if the pizza is paid, false otherwice
        bool get_paid();
        /// returns the comment
        string get_comment();
        ///////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////
        /// checks if order is both paid and is ready!
        bool is_order_receved();
        ///////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////
        /// takes in ifstream and reads from file
        void read(ifstream& file);
        /// takes in ofstream and writes to file
        void write(ofstream& file);
        ///////////////////////////////////////////////////////

        //////////////////////////////////////////////////////
        /// I dont even know the reason for this friend function
        friend istream& operator >> (istream& in, Order& order);

        /// prints out the order
        friend ostream& operator << (ostream& out, const Order& order);

        /// checks if the location and phone number is the same!
        friend bool operator == (Order& order1, Order& order2);
        ///////////////////////////////////////////////////////
    private:
        /// Location for the order
        Location location;
        /// phone number for the order
        char phone[8];
        /// Comment for the order
        char comment[255];
        /// Price for the order
        double price;
        /// Status of the order
        status orderStatus;
        /// Is the order paid or not
        bool paid;
        /// list of pizzas in the order
        vector<Pizza>pizzas;
        /// list of drinks in the order
        vector<Drink>drinks;
        /// list of the side dishes in the order
        vector<Sides>sides;

};

#endif // ORDER_H

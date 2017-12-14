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

    ////////////////////////////////////////////////////////////////////
    /// Returns the name of the pizza
    string get_name() const;

    /// Returns the price of the pizza
    double get_price() const;
    ////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////
    /// Takes ofstream and writes to file
    void write(ofstream& file);

    /// Takes ifstream and reads from file
    void read(ifstream& file);
    ////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////
    /// clear all current toppings
    void clear_toppings();

    /// add new topping to pizza
    void add_topping(Topping& topping);
    ////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////
    /// Friend function to read out pizza
    friend ostream& operator << (ostream& out, const Pizza& pizza);

    /// Friend function to write to pizza
    friend istream& operator >> (istream& in, Pizza& pizza);
    ////////////////////////////////////////////////////////////////////
private:
    char name[32];
    double price;
    vector<Topping>toppings;

};

#endif // PIZZA_H

#ifndef TOPPING_H
#define TOPPING_H

#define TOPPING_H


#include <fstream>
#include <iostream>
#include <string.h>


#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "InvalidIdException.h"

using namespace std;

class Topping
{
public:
    ////////////////////////////////////////////////////////////////////
    /// Topping Constructor
    Topping();
    /// Topping Constructor with name and price
    Topping(char* name, double price);
    ////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////
    /// takes ifstream and reads from the file
    void read(ifstream& file);

    /// takes ofstream and writes to the file
    void write(ofstream& file);
    ////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////
    /// Validates that the topping is valid
    bool valid_topping() const;
    ////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////
    /// Returns the name of the topping
    string get_name();

    /// Returns the price of the topping
    double get_price();
    ////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////
    /// Friend function to read topping
    friend ostream& operator << (ostream& out, const Topping& topping);

    /// Friend function to write into topping
    friend istream& operator >> (istream& in, Topping& topping);
    ////////////////////////////////////////////////////////////////////

private:
    char name[32];
    double price;
};

#endif // TOPPING_H

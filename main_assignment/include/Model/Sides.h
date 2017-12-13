#ifndef SIDES_H
#define SIDES_H

#include <fstream>
#include <iostream>
#include <string.h>

#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "InvalidIdException.h"

using namespace std;

class Sides
{
    public:
        /// Side dish Constructor
        Sides();

        ////////////////////////////////////////////////////////////////////
        /// Takes ofstream and writes to file
        void write(ofstream& file);
        /// Takes ifstream and reads from file
        void read(ifstream& file);
        ////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////
        /// Returns the name of the side dish
        string get_name() const;

        /// Returns the price of the side dish
        double get_price() const;
        ////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////
        /// Friend function to read out side dish
        friend ostream& operator << (ostream& out, const Sides& side);

        /// Friend function to write to side dish
        friend istream& operator >> (istream& in, Sides& side);
        ////////////////////////////////////////////////////////////////////
    private:
        char name[32];
        double price;
};

#endif // SIDES_H

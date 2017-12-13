#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <fstream>
#include <string.h>

#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "InvalidIdException.h"
#include "UnableToOpenFileException.h"

using namespace std;

class Drink
{
    public:
        Drink();

        ////////////////////////////////////////////////////////////////////
        /// Returns name of drink
        string get_name() const;

        /// Returns price of drink
        double get_price() const;
        ////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////
        /// Takes ifstream and reads from file
        void read(ifstream& file);

        /// Takes ofstream and writes to file
        void write(ofstream& file);
        ////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////
        /// Friend function to write to drink
        friend istream& operator >> (istream& in, Drink& drink);

        /// Friend function to read from drink
        friend ostream& operator << (ostream& out, const Drink& drink);
        ////////////////////////////////////////////////////////////////////
    private:
        char name[32];
        double price;
};

#endif // DRINK_H

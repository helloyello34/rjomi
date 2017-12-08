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
        Sides();

        void write(ofstream& file);
        void read(ifstream& file);

        string get_name() const;
        double get_price() const;

        friend ostream& operator << (ostream& out, const Sides& side);
        friend istream& operator >> (istream& in, Sides& side);
    private:
        char name[32];
        double price;
};

#endif // SIDES_H

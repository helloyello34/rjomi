#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <fstream>
#include <string.h>

#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "InvalidIdException.h"

using namespace std;


class Drink
{
    public:
        Drink();

        string get_name() const;
        double get_price() const;

        void read(ifstream& file);
        void write(ofstream& file);

        friend istream& operator >> (istream& in, Drink& drink);
        friend ostream& operator << (ostream& out, const Drink& drink);
    private:
        char name[32];
        double price;
};

#endif // DRINK_H

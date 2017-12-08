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
        Topping();
        Topping(char* name, double price);
        void read(ifstream& file);
        void write(ofstream& file);
        bool valid_topping() const;
        string get_name();
        double get_price();
        friend ostream& operator << (ostream& out, const Topping& topping);
        friend istream& operator >> (istream& in, Topping& topping);

    private:
        char name[32];
        double price;
};

#endif // TOPPING_H

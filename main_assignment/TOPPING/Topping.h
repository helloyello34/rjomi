#ifndef TOPPING_H
#define TOPPING_H

#define TOPPING_H


#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

class Topping
{
    public:
        Topping();
        virtual ~Topping();
        void read(fstream& file);
        void write(fstream& file);
        bool valid_topping();
        friend ostream& operator << (ostream& out, const Topping& topping);
        friend istream& operator >> (istream& in, Topping& topping);

    private:
        char name[32];
        double price;
};

#endif // TOPPING_H

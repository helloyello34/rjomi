#ifndef TOPPING_H
#define TOPPING_H

#include <iostream>

using namespace std;

class Topping
{
    public:
        Topping();
        virtual ~Topping();

        friend ostream& operator << (ostream& out, const Topping& topping);
        friend istream& operator >> (istream& in, Topping& topping);

    private:
        char name[32];
        double price;
};

#endif // TOPPING_H

#include "Topping.h"

Topping::Topping()
{
    this->name[0] = '\0';
    this->price = 0;
}

Topping::~Topping()
{
    //dtor
}

ostream& operator << (ostream& out, const Topping& topping)
{
    out << topping.name << " kr:" << topping.price;

    return out;
}

istream& operator >> (istream& in, Topping& topping)
{
    cout << "Topping name : ";
    in >> topping.name;
    cout << "Topping price : ";
    in >> topping.price;

    return in;
}

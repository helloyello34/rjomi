#include "Topping.h"

Topping::Topping()
{
    //ctor
}

Topping::~Topping()
{
    //dtor
}


ostream& operator << (ostream& out, const Topping& topping)
{
    out << topping.name << " " << topping.price;
}

istream& operator >> (istream& in, Topping& topping)
{
    cout << "Topping name : ";
    in >> topping.name;
    cout << "Topping price : ";
    in >> topping.price;

}

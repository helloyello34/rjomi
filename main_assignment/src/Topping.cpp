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
<<<<<<< HEAD
    out << topping.name << " kr:" << topping.price;

=======
    out << topping.name << " " << topping.price;

>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
    return out;
}

istream& operator >> (istream& in, Topping& topping)
{
    cout << "Topping name : ";
    in >> topping.name;
    cout << "Topping price : ";
<<<<<<< HEAD
    in >> topping.price;

=======
    in >> topping.price;

>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
    return in;
}

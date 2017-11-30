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

void Topping::read(fstream& file)
{
    file >> this->name >> this->price;
}

void Topping::write(fstream& file)
{
    file << endl << this->name << " ";
    file << this->price;
}

ostream& operator << (ostream& out, const Topping& topping)
{
    out << topping.name << " " << topping.price;
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


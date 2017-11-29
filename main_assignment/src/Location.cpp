#include "Location.h"

Location::Location()
{
    this->name = "";
}

Location::~Location()
{

}

istream& operator >> (istream& in, Location& location)
{
    cout << "Enter a new place: ";
    in >> location.name;

    return in;
}

ostream& operator << (ostream& out, const Location& location)
{
    out << location.name << endl;

    return out;
}

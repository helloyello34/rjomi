#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

using namespace std;

class Location
{
    public:
        Location();
        virtual ~Location();
        friend istream& operator >> (istream& in, Location& location);
        friend ostream& operator << (ostream& out, const Location& location);
    private:
        string name;
};

#endif // LOCATION_H

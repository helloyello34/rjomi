#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

#include "InvalidNameException.h"
#include "InvalidIdException.h"


using namespace std;

class Location
{
    public:
        Location();

        void read(ifstream& file);
        void write(ofstream& file);

        string get_name();

        friend istream& operator >> (istream& in, Location& location);
        friend ostream& operator << (ostream& out, const Location& location);
    private:
        char name[32];
};

#endif // LOCATION_H

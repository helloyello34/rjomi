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

        ////////////////////////////////////////////////////////////////////
        /// Takes ifstream and reads from file
        void read(ifstream& file);

        /// Takes ofstream and writes to file
        void write(ofstream& file);
        ////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////
        /// Returns the name of the location
        string get_name();
        ////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////
        /// Friend function to write location
        friend istream& operator >> (istream& in, Location& location);

        /// Friend function to read out location
        friend ostream& operator << (ostream& out, const Location& location);
        ////////////////////////////////////////////////////////////////////
    private:
        char name[32];
};

#endif // LOCATION_H

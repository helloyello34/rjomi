#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <string>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

class Employe
{
    public:
        Employe();

        string get_name() const;
        unsigned int get_ssn() const;

        void write(fstream& file) const;
        void read(fstream& file);

        friend istream& operator >> (istream& in, Employe& employe);
        friend ostream& operator << (ostream& out, const Employe employe);
    private:
        char name[100];
        unsigned int ssn;
};

#endif // EMPLOYE_H

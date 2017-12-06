#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <string>
#include <string.h>
#include <fstream>
#include <iostream>

#include "InvalidSsnExceptions.h"

using namespace std;

class Employe
{
    public:
        Employe();
        Employe(char* name, char* ssn);

        string get_name() ;
        string get_ssn() ;

        void write(fstream& file) const;
        void read(fstream& file);

        friend istream& operator >> (istream& in, Employe& employe);
        friend ostream& operator << (ostream& out, const Employe& employe);
    private:
        char name[100];
        char ssn[20];
};

#endif // EMPLOYE_H

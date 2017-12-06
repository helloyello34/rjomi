#ifndef SALARY_H
#define SALARY_H

#include <iostream>
#include <fstream>
#include <string>

#include "Employe.h"

using namespace std;

class Salary
{
    public:
        Salary();
        void write(fstream& file) const;
        void read(fstream& file);
        unsigned int get_employe_ssn();
        friend istream& operator >> (istream& in, Salary& salary);
        friend ostream& operator << (ostream& out, const Salary& salary);
        friend int operator == (const Salary& salary1, const Salary& salary2);
    private:
        Employe employe;
        int salary;
        int month;
        int year;
};

#endif // SALARY_H

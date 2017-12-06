#ifndef SALARY_H
#define SALARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>

#include "Employe.h"
#include "InvalidMonthExceptions.h"
#include "InvalidYearExceptions.h"

class WrongNameException { };

using namespace std;

class Salary
{
    public:
        Salary();
        Salary(char* name, char* ssn);
        void write(fstream& file) const;
        void read(fstream& file);
        string get_employe_ssn();
        string get_employe_name();
        int get_month();
        int get_year();
        Salary(char* name, char* ssn, int salary, int month, int year);
        friend istream& operator >> (istream& in, Salary& salary);
        friend ostream& operator << (ostream& out, const Salary& salary);
        friend int operator == ( Salary& salary1,  Salary& salary2);
        friend Salary& operator + (const Salary& salary1, const Salary& salary2);
    private:
        Employe employe;
        int salary;
        int month;
        int year;
};

#endif // SALARY_H

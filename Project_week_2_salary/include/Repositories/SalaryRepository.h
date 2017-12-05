#ifndef SALARYREPOSITORY_H
#define SALARYREPOSITORY_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Salary.h"

using namespace std;

class SalaryRepository
{
    public:
        SalaryRepository();
        void add_salary(const Salary& salary);
        void read_salary(vector<Salary>&salary);
        void overwrite_salary(vector<Salary>&salary);
    private:
};

#endif // SALARYREPOSITORY_H

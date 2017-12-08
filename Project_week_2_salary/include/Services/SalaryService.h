#ifndef SALARYSERVICE_H
#define SALARYSERVICE_H

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "SalaryRepository.h"
#include "Salary.h"

class FirstTimeWritingException { };

using namespace std;

class SalaryService
{
    public:
        SalaryService();
        void add_salary( Salary& salary);
        void print_salary(string this_ssn);
        void print_year(string this_ssn, int this_year);
    private:
        void get_salary();
        SalaryRepository salary_repo;
        vector<Salary>salary;

};

#endif // SALARYSERVICE_H

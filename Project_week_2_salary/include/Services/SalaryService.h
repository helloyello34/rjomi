#ifndef SALARYSERVICE_H
#define SALARYSERVICE_H

#include <vector>
#include <iostream>

#include "SalaryRepository.h"
#include "Salary.h"

using namespace std;

class SalaryService
{
    public:
        SalaryService();
        void add_salary(const Salary& salary);
        void get_salary();
        void print_salary(unsigned int this_ssn);
    private:
        SalaryRepository salary_repo;
        vector<Salary>salary;

};

#endif // SALARYSERVICE_H

#ifndef MAINUI_H
#define MAINUI_H

#include "Salary.h"
#include "SalaryService.h"

class MainUI
{
    public:
        MainUI();
        void Main_Menu();
        void validate(char input);
        void add_salary();
        void get_salary_ssn();
        void get_salary_year();

    private:
        SalaryService salary_service;
};

#endif // MAINUI_H

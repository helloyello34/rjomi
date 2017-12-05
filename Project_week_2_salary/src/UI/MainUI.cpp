#include "MainUI.h"



MainUI::MainUI()
{
    //ctor
}


void MainUI::Main_Menu()
{
    char input = '\0';
    while(input != 'q'){
    cout << "Main Menu"                             << endl;
    cout << "=====================================" << endl;
    cout << "1. Add salary record"                  << endl;
    cout << "2. Get salary for given SSN"           << endl;
    cout << "3. Get higest salary for a given year" << endl;
    cout << "q. Quit"                               << endl;
    cout << "=====================================" << endl;
    cin >> input;
    validate(input);
    }
}

void MainUI::validate(char input)
{
    switch(input){
    case '1': add_salary(); break;
    case '2': get_salary_ssn(); break;
    case '3': get_salary_year(); break;
    case 'q': cout << "Good Bye" << endl; break;
    default: cout << "Invalid input" << endl; break;

    }
}

void MainUI::add_salary()
{
    Salary salary;
    cin >> salary;
    salary_service.add_salary(salary);
}

void MainUI::get_salary_ssn()
{
    unsigned int this_ssn;
    cout << "Enter an ssn (10): ";
    cin >> this_ssn;

    salary_service.get_salary();
    salary_service.print_salary(this_ssn);
}

void MainUI::get_salary_year()
{

}

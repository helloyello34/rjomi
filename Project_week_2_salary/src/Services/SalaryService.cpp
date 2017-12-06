#include "SalaryService.h"



SalaryService::SalaryService()
{
    //ctor
}

void SalaryService::add_salary(Salary& salary)
{
    try{
    get_salary();
    }
    catch(FirstTimeWritingException e){
        salary_repo.add_salary(salary);
        return;
    }
    try{
    unsigned int i = 0;
    for(; i < this->salary.size(); i++) {
        if(this->salary[i] == salary){
            this->salary[i] = salary;
            salary_repo.overwrite_salary(this->salary);
            break;
        }
    }
    if(!(this->salary[i] == salary)){
        salary_repo.add_salary(salary);
    }
    }
    catch(WrongNameException e){
        cout << "Error: Wrong name or ssn" << endl;
    }
}

void SalaryService::get_salary()
{
    salary_repo.read_salary(this->salary);
}

void SalaryService::print_salary(string this_ssn)
{
    get_salary();
    cout << "=========================================" << endl;
    for(unsigned int i = 0; i < this->salary.size(); i++) {
        string ssn = this->salary[i].get_employe_ssn();
        if(ssn == this_ssn){
            cout << this->salary[i] << endl;
        }
    }
    cout << "=========================================" << endl;
}

void SalaryService::print_year(string this_ssn, int this_year)
{
    get_salary();
    Salary salaryByYear;
    for(unsigned int i = 0; i < this->salary.size(); i++){

        if(this->salary[i].get_employe_ssn() == this_ssn){
            if(this->salary[i].get_year() == this_year){
                salaryByYear = salaryByYear + this->salary[i];
            }
        }
    }
    if(salaryByYear.get_year() > 0){
    cout << endl << endl;
    cout << "=========================================" << endl;
    cout << "Salary year " << salaryByYear.get_year() << endl;
    cout << salaryByYear << endl;
    cout << "=========================================" << endl << endl;
    }else{
        cout << endl << endl;
        cout << "There are no records of this person the year "
             << this_year << endl << endl;
    }
}

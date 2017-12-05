#include "SalaryService.h"

SalaryService::SalaryService()
{
    //ctor
}

void SalaryService::add_salary(const Salary& salary)
{
    get_salary();
    for(unsigned int i = 0; i < this->salary.size(); i++) {
        if(this->salary[i] == salary){
            this->salary[i] = salary;
            salary_repo.overwrite_salary(this->salary);
            break;
        } else {
            salary_repo.add_salary(salary);
        }
    }
    if(this->salary.size() == 0){
        salary_repo.add_salary(salary);
    }

}

void SalaryService::get_salary()
{
    salary_repo.read_salary(this->salary);
}

void SalaryService::print_salary(unsigned int this_ssn)
{
    for(unsigned int i = 0; i < this->salary.size(); i++) {
        if(this_ssn == this->salary[i].get_employe_ssn()){
            cout << this->salary[i] << endl;
        }
    }
}

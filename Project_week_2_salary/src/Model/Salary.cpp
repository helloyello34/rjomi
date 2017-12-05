#include "Salary.h"

Salary::Salary()
{
    this->salary = 0;
    this->month = 0;
    this->year = 0;
}

void Salary::write(fstream& file) const
{
    //writing txt

    this->employe.write(file);
    file << this->salary << endl;
    file << this->month << endl;
    file << this->year;

}

void Salary::read(fstream& file)
{

    //writing txt

    cout << "Reading Employe" << endl;
    this->employe.read(file);
    cout << "Done reading Employe" << endl;
    file >> this->salary;
    file >> this->month;
    file >> this->year;
    cout << "Done reading everything" << endl;

}

unsigned int Salary::get_employe_ssn()
{
    return this->employe.get_ssn();
}

istream& operator >> (istream& in, Salary& salary)
{
    if(salary.employe.get_ssn() == 0){
        in >> salary.employe;
    }

    cout << "Salary: ";
    in >> salary.salary;

    cout << "Month (1-12): ";
    in >> salary.month;

    cout << "Year (-2017): ";
    in >> salary.year;

    return in;
}


ostream& operator << (ostream& out, const Salary& salary)
{
    out << endl;
    out << "Name: " << salary.employe.get_name() << endl;

    out << "SSN: " << salary.employe.get_ssn() << endl;

    out << "Salary: " << salary.salary << endl;

    out << "Month: " << salary.month << endl;

    out << "Year: " << salary.year << endl;
    out << endl;

    return out;
}

int operator == (const Salary& salary1, const Salary& salary2)
{
    if(salary1.employe.get_ssn() != salary2.employe.get_ssn()){
        return 0;   // Ekki sama manneskjan
    } else {
        if(salary1.year == salary2.year){
            if(salary1.month == salary2.month){
                return 1;   //sama faersla og tharf ad yfirskrifa
            }
        }
        return 0;   // sama manneskjan en bara baeta vid
    }
}

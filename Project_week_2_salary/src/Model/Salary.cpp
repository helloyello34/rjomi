#include "Salary.h"

Salary::Salary()
{
    this->salary = 0;
    this->month = 0;
    this->year = 0;
}

Salary::Salary(char* name, char* ssn, int salary, int month, int year)
{
    this->salary = salary;
    this->month = month;
    this->year = year;
}

int Salary::get_month()
{
    return this->month;
}

int Salary::get_year()
{
    return this->year;
}

string Salary::get_employe_name()
{
    return this->employe.get_name();
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

//    cout << "Reading Employe" << endl;
    this->employe.read(file);
    file >> this->salary;
    file >> this->month;
    file >> this->year;
//    cout << "Done reading everything" << endl;

}

string Salary::get_employe_ssn()
{
    return employe.get_ssn();
}

istream& operator >> (istream& in, Salary& salary)
{
    cout << "   Add salary record" << endl;
    cout << " ==========================" << endl;
    in >> salary.employe;

    cout << "  Salary: ";
    in >> salary.salary;

    cout << "  Month (1-12): ";
    in >> salary.month;
    if(salary.month < 1 || salary.month > 12){
        throw InvalidMonthExceptions("  Error: Wrong month");
    }

    cout << "  Year (1900-2017): ";
    in >> salary.year;
    if(salary.year < 1900 || salary.year > 2017){
       throw InvalidYearExceptions("  Error: Wrong year");
    }

    return in;
}


ostream& operator << (ostream& out, const Salary& salary)
{
    out << endl;

    out << "   --------------------------" << endl;
    out << salary.employe << endl;

    out << "    Salary: " << salary.salary << endl;

    if(salary.month > 0){
    out << "    Month: " << salary.month << endl;
    }

    out << "    Year: " << salary.year << endl;
    out << "   -------------------------" << endl;

    return out;
}

int operator == (Salary& salary1, Salary& salary2)
{
    if(salary1.get_employe_ssn() == salary2.get_employe_ssn()){
        //cout << "Same person" << endl;
        if(salary1.get_employe_name() != salary2.get_employe_name()){
            throw WrongNameException();
        }
        if(salary1.year == salary2.year){
        if(salary1.month == salary2.month){
        return 1;
        }
        }
    }
    return 0;
    /*
    string name1, name2;
    name1 = salary1.get_employe_ssn();
    name2 = salary2.get_employe_ssn();
    if(strcmp(name1, name2)){
        cout << "Ekki sama manneskja" << endl;
        return 0;   // Ekki sama manneskjan
    } else {
        if(salary1.year == salary2.year){
            if(salary1.month == salary2.month){
                cout << "Overwrite" << endl;
                return 1;   //sama faersla og tharf ad yfirskrifa
            }
        }
        cout << "Elsid" << endl;
        return 0;   // sama manneskjan en bara baeta vid
    }
    */
}

Salary& operator + (const Salary& salary1, const Salary& salary2)
{
    Salary temp;
    temp.employe = salary2.employe;
    temp.year = salary2.year;
    temp.salary = salary1.salary + salary2.salary;
    return temp;
}

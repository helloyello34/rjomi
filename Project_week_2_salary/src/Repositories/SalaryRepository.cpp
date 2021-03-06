#include "SalaryRepository.h"

class FirstTimeWritingException { };

SalaryRepository::SalaryRepository()
{
    //ctor
}

void SalaryRepository::add_salary(const Salary& salary)
{
    //cout << "Writing to file " << endl;
    ofstream file;
    file.open("Salary.dat", ios::binary|ios::app);
    if(file.is_open()) {
        //salary.write(file);
        file.write((char*)(&salary), sizeof(Salary));
        file.close();
    } else {
        cout << "File could not open ! " << endl;
    }
}

void SalaryRepository::read_salary(vector<Salary>&salary)
{
    //cout << "Reading from file " << endl;
    ifstream file;
    file.open("Salary.dat", ios::binary);
    Salary temp;
    if(file.is_open()) {
        salary.clear();
        while(file.read((char*)(&temp), sizeof(Salary))) {
            salary.push_back(temp);
            //cout << "READ" << endl;
        }
        //salary.pop_back();
//      file.read((char*)(&temp), sizeof(Salary));
//      salary.push_back(temp);

        //salary.pop_back();
        file.close();
    } else {
        throw FirstTimeWritingException();
        cout << "File could not open !" << endl;
    }
}

void SalaryRepository::overwrite_salary(vector<Salary>&salary)
{
    ofstream file;
    file.open("Salary.dat", ios::binary|ios::out);

    if(file.is_open()) {
        for(unsigned int i = 0; i < salary.size(); i++) {
            file.write((char*)(&salary[i]), sizeof(Salary));
        }
    } else {
        cout << "File could not open ! " << endl;
    }
}

#include "SalaryRepository.h"

SalaryRepository::SalaryRepository()
{
    //ctor
}

void SalaryRepository::add_salary(const Salary& salary)
{
    fstream file;
    file.open("Salary.dat", ios::binary|ios::app|ios::out|ios::in);
    if(file.is_open()){
        //salary.write(file);
        file.write((char*)(&salary), sizeof(Salary));
        file.close();
    }else{
        cout << "File could not open ! " << endl;
    }
}

void SalaryRepository::read_salary(vector<Salary>&salary)
{
    fstream file;
    file.open("Salary.dat", ios::binary|ios::out|ios::in);
    Salary temp;
    if(file.is_open()){
        salary.clear();
        while(/*!(file.eof())*/file.read((char*)(&temp), sizeof(Salary))){
            //temp.read(file);
//            file.read((char*)(&temp), sizeof(Salary));
            salary.push_back(temp);
        }
        salary.pop_back();
        file.close();
    }else{
        cout << "File could not open !" << endl;
    }
}

void SalaryRepository::overwrite_salary(vector<Salary>&salary)
{
    fstream file;
    file.open("Salary.dat", ios::binary|ios::out|ios::in);

    if(file.is_open()){
        for(unsigned int i = 0; i < salary.size(); i++){
            file.write((char*)(&salary[i]), sizeof(Salary));
        }
    } else {
        cout << "File could not open ! " << endl;
    }
}

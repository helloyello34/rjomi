#include "Employe.h"

Employe::Employe()
{
    this->name[0] = '\0';
    this->ssn = 0;
}

string Employe::get_name() const
{
    return this->name;
}

unsigned int Employe::get_ssn() const
{
    return this->ssn;
}

void Employe::write(fstream& file) const
{
    file << this->name << endl;
    file << this->ssn << endl;
}

void Employe::read(fstream& file)
{
//    getline(file,this->name);
    file >> this->ssn;
}


istream& operator >> (istream& in, Employe& employe)
{
    cout << "Name: ";
    in.ignore();
    in.getline(employe.name, 100);
    cout << "SSN (10): ";
    in >> employe.ssn;

    return in;
}

#include "Employe.h"

Employe::Employe()
{
    this->name[0] = '\0';
    this->ssn[0] = '\0';
}

Employe::Employe(char* name, char* ssn)
{
    strcpy(this->name, name);
    strcpy(this->ssn, ssn);
}

string Employe::get_name()
{
    return (string)this->name;
}

string Employe::get_ssn()
{
    return (string)this->ssn;
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

    if(strlen(employe.ssn) != 10 ){
        throw InvalidSsnExceptions("Error: Ssn should be 10 integers");
    }
    for(int i = 0; i < 10; i++) {
        if(!(isdigit(employe.ssn[i]))){
            throw InvalidSsnExceptions("Error: Ssn should only hold integers");
        }
    }



    return in;
}

ostream& operator << (ostream& out, const Employe& employe)
{
    out << "Name: " << employe.name << endl;

    out << "Ssn: " << employe.ssn << endl;

    return out;
}

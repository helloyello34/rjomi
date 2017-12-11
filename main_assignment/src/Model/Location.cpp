#include "Location.h"

Location::Location()
{
    strcpy(this->name,"Nothing");
}

void Location::read(ifstream& file)
{
    file.read(this->name, sizeof(this->name));
}

void Location::write(ofstream& file)
{
    file.write(this->name, sizeof(this->name));
}

string Location::get_name()
{
    return (string)this->name;
}


istream& operator >> (istream& in, Location& location)
{
    cout << "  Name: ";
    in.getline(location.name, 32);

    if(strlen(location.name) == 0){
        throw InvalidNameException();
    }
    for(size_t i = 0; i < strlen(location.name); i++) {
        if(!isalnum(location.name[i])) {
            if(location.name[i] != ' ') {
                throw InvalidNameException();
            }
        }
    }

    return in;
}

ostream& operator << (ostream& out, const Location& location)
{
    out << "  " << location.name << endl;

    return out;
}

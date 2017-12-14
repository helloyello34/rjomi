#include "Location.h"

Location::Location()
{
    // Initializes Location
    strcpy(this->name,"Nothing");
}

void Location::read(ifstream& file)
{
    // Read Locations from file
    file.read(this->name, sizeof(this->name));
}

void Location::write(ofstream& file)
{
    // Write Locations to file
    file.write(this->name, sizeof(this->name));
}

string Location::get_name()
{
    // Returns the name of Location
    return (string)this->name;
}




istream& operator >> (istream& in, Location& location)
{
    // prints out the name of location
    cout << "  Name: ";
    in.getline(location.name, 32);

    // if nothing is input as a name. throw a fault
    if(strlen(location.name) == 0){
        throw InvalidNameException();
    }
    // If any character is not alphanumeric or a space. Throw a fault
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
    // Prints out Location
    out << "  " << location.name << endl;

    return out;
}

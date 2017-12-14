#include "Sides.h"

Sides::Sides()
{
    // Default initializer for sides
    strcpy(this->name, "nothing");
    this->price = 0;
}


void Sides::write(ofstream& file)
{
    // Writes sides to file
    file.write(this->name, sizeof(this->name));
    file.write((char*)(&this->price), sizeof(this->price));
}

void Sides::read(ifstream& file)
{
    // Reads sides from file
    file.read(this->name, sizeof(this->name));
    file.read((char*)(&this->price), sizeof(this->price));
}

string Sides::get_name() const
{
    // Returns name of sides
    return (string)this->name;
}

double Sides::get_price() const
{
    // Returns price
    return this->price;
}

ostream& operator << (ostream& out, const Sides& side)
{
    // Print out sides
    out << "     Name: " << side.name << endl;
    out << "     Price: " << side.price << endl;
    return out;
}

istream& operator >> (istream& in, Sides& side)
{
    // Input sides
    cout << "  Name: ";
    in.getline(side.name, 32);
    // If name is length 0. Throw a fault
    if(strlen(side.name) == 0)
    {
        throw InvalidNameException();
    }
    // If name is not alphanumeric or a space. Throw a fault
    for(unsigned int i = 0; i < strlen(side.name); i++)
    {
        if(!(isalnum(side.name[i])))
        {
            if(side.name[i] != ' ')
            {
                throw InvalidNameException();
            }
        }
    }
    cout << "  Price: ";
    in >> side.price;
    // if price is not a number. throw a fault
    if(in.fail())
    {
        in.clear();
        throw InvalidPriceException();
    }
    // Price cap for sides
    if(side.price > 5000 || side.price < 0)
    {
        throw InvalidPriceException();
    }

    return in;
}

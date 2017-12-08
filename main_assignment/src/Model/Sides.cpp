#include "Sides.h"

Sides::Sides()
{
    strcpy(this->name, "nothing");
    this->price = 0;
}


void Sides::write(ofstream& file)
{
    file.write(this->name, sizeof(this->name));
    file.write((char*)(&this->price), sizeof(this->price));
}

void Sides::read(ifstream& file)
{
    file.read(this->name, sizeof(this->name));
    file.read((char*)(&this->price), sizeof(this->price));
}

string Sides::get_name()
{
    return (string)this->name;
}

double Sides::get_price()
{
    return this->price;
}

ostream& operator << (ostream& out, const Sides& side)
{
    out << "Name: " << side.name << endl;
    out << "Price: " << side.price << endl;
    return out;
}

istream& operator >> (istream& in, Sides& side)
{
    cout << "===== Writing new side dish =====" << endl;
    cout << "Name: ";
    in.getline(side.name, 32);
    if(strlen(side.name) == 0){
        throw InvalidNameException();
    }
    for(unsigned int i = 0; i < strlen(side.name); i++){
        if(!(isalnum(side.name[i]))){
            if(side.name[i] != ' '){
                throw InvalidNameException();
            }
        }
    }
    cout << "Price: ";
    in >> side.price;
    if(in.fail()){
        in.clear();
        throw InvalidPriceException();
    }
    if(side.price > 5000 || side.price < 0){
        throw InvalidPriceException();
    }

    return in;
}

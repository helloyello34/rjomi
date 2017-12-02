#include "Topping.h"

Topping::Topping()
{
    strcpy(name,"nothing");
    this->price = 0;
}

Topping::~Topping()
{
    //dtor
}



void Topping::read(fstream& file)
{
    file.read(this->name, sizeof(this->name));
    file.read((char*)(&this->price), sizeof(this->price));
    //file >> this->name >> this->price;
}

void Topping::write(fstream& file)
{

    file.write(this->name, sizeof(this->name));
    file.write((char*)(&this->price), sizeof(this->price));
    /*
    if(valid_topping()){
        file << endl << this->name << " ";
        file << this->price;
    }*/

}


bool Topping::valid_topping()
{
    if(strcmp(this->name, "nothing")) {
        return true;
    } else {
        return false;
    }
}

ostream& operator << (ostream& out, const Topping& topping)
{
    out << topping.name << " " << topping.price;
    return out;
}

istream& operator >> (istream& in, Topping& topping)
{
    cout << "Topping name : ";
    in >> topping.name;
    cout << "Topping price : ";
    in >> topping.price;
    return in;
}


#include "Topping.h"

Topping::Topping()
{
    strcpy(name,"Nothing");
    this->price = 0;
}

Topping::Topping(char* name, double price)
{
    strcpy(this->name, name);
    this->price = price;
}



void Topping::read(ifstream& file)
{
    //Writing in binary

    file.read(this->name, sizeof(this->name));
    file.read((char*)(&this->price), sizeof(this->price));

    //Writing in txt file
    /*
    file >> this->name >> this->price ;
    */
}

void Topping::write(ofstream& file) const
{
    //Writing in binary

    file.write(this->name, sizeof(this->name));
    file.write((char*)(&this->price), sizeof(this->price));

    //Writing in txt file
    /*
    if(valid_topping()){
        file << this->name << " ";
        file << this->price << " ";
    }
    */

}


bool Topping::valid_topping() const
{
    if(strcmp(this->name, "nothing")) {
        return true;
    } else {
        return false;
    }
}

string Topping::get_name()
{
    return (string)this->name;
}

double Topping::get_price()
{
    return this->price;
}

ostream& operator << (ostream& out, const Topping& topping)
{
    out << topping.name << " | " << topping.price << " kr.";
    return out;
}

istream& operator >> (istream& in, Topping& topping)
{
    cout << "Name : ";
    in.getline(topping.name, 32);
    if(strlen(topping.name) == 0) {
        throw InvalidNameException();
    }
    for(size_t i = 0; i < strlen(topping.name); i++) {
        if(!(isalpha(topping.name[i]))){
            if(!(topping.name[i] == ' ')) {
                throw InvalidNameException();
            }
        }
    }

    cout << "Price: ";
    in >> topping.price;

    if(in.fail()) {
        in.clear();
        throw InvalidPriceException();
    }
    if(topping.price < 0 || topping.price > 5000) {
        throw InvalidPriceException();
    }

    return in;
}


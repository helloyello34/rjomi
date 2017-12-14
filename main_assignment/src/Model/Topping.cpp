#include "Topping.h"

Topping::Topping()
{
    // Default initializer for toppings
    strcpy(name,"Nothing");
    this->price = 0;
}

Topping::Topping(char* name, double price)
{
    // Initializer with a set name and price
    strcpy(this->name, name);
    this->price = price;
}



void Topping::read(ifstream& file)
{
    /// reading in binary
    file.read(this->name, sizeof(this->name));
    file.read((char*)(&this->price), sizeof(this->price));
}

void Topping::write(ofstream& file)
{
    /// Writing in binary

    file.write(this->name, sizeof(this->name));
    file.write((char*)(&this->price), sizeof(this->price));
}


bool Topping::valid_topping() const
{
    // Checks if name of topping is valid
    if(strcmp(this->name, "nothing")) {
        return true;
    } else {
        return false;
    }
}

string Topping::get_name()
{
    // Returns name
    return (string)this->name;
}

double Topping::get_price()
{
    // Returns price
    return this->price;
}

ostream& operator << (ostream& out, const Topping& topping)
{
    // prints out topping
    out << topping.name << " | " << topping.price << " kr.";
    return out;
}

istream& operator >> (istream& in, Topping& topping)
{
    // input topping
    cout << " ======================" << endl;
    cout << "  Name : ";
    in.getline(topping.name, 32);
    // If name is length 0. Throw a fault
    if(in.fail())
    {
        in.clear();
        throw InvalidNameException();
    }
    if(strlen(topping.name) == 0) {
        throw InvalidNameException();
    }
    // If name is not alphanumeric or a space. Throw a fault
    for(size_t i = 0; i < strlen(topping.name); i++) {
        if(!(isalpha(topping.name[i]))){
            if(!(topping.name[i] == ' ')) {
                throw InvalidNameException();
            }
        }
    }

    cout << "  Price: ";
    in >> topping.price;

    // If price is not a number. Throw a fault
    if(in.fail()) {
        in.clear();
        throw InvalidPriceException();
    }
    // Price cap for toppings
    if(topping.price < 0 || topping.price > 5000) {
        throw InvalidPriceException();
    }

    return in;
}


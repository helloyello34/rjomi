#include "Pizza.h"

Pizza::Pizza()
{
    strcpy(this->name, "Custom" );
    this->price = 1500;
}


string Pizza::get_name() const
{
    return (string)this->name;
}

double Pizza::get_price() const
{
    return this->price;
}

void Pizza::write(ofstream& file)
{
    file.write(this->name, sizeof(this->name));
    file.write((char*)(&this->price), sizeof(this->price));
    unsigned int topping_size = this->toppings.size();
    file.write((char*)(&topping_size), sizeof(topping_size));
    for(size_t i = 0; i < topping_size; i++) {
        this->toppings[i].write(file);
    }
}

void Pizza::read(ifstream& file)
{
    file.read(this->name, sizeof(this->name));
    file.read((char*)(&this->price), sizeof(this->price));
    unsigned int topping_size;
    file.read((char*)(&topping_size), sizeof(topping_size));
    for(size_t i = 0; i < topping_size; i++) {
        if(toppings[i].get_name() == "Nothing"){
            return;
        }
        this->toppings[i].read(file);
    }
}

void Pizza::add_topping(Topping& topping)
{
    this->price += topping.get_price();
    this->toppings.push_back(topping);
}

ostream& operator << (ostream& out, const Pizza& pizza)
{
    out << "   " << pizza.name << endl;
    out << "   " << pizza.price << " kr." << endl;
    out << "  Topping: " << endl;
    for(size_t i = 0; i < pizza.toppings.size(); i++ ) {
        out << "    " << pizza.toppings[i] << endl;
    }
    return out;
}

istream& operator >> (istream& in, Pizza& pizza)
{
    cout << "Name: ";
    in.getline(pizza.name, 32);

    if(strlen(pizza.name) == 0){
        throw InvalidNameException();
    }
    for(size_t i = 0; i < strlen(pizza.name); i++) {
        if(!isalnum(pizza.name[i])) {
            if(!(pizza.name[i] == ' ')) {
                throw InvalidNameException();
            }
        }
    }

    return in;
}

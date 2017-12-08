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
    size_t topping_size = this->toppings.size();
    file.write((char*)(&topping_size), sizeof(topping_size));
    for(size_t i = 0; i < topping_size; i++) {
        this->toppings[i].write(file);
    }
}

void Pizza::read(ifstream& file)
{
//    cout << "name" << endl;
    file.read(this->name, sizeof(this->name));
//    cout << "price" << endl;
    file.read((char*)(&this->price), sizeof(this->price));
//    cout << "size" << endl;
    size_t topping_size;
    file.read((char*)(&topping_size), sizeof(topping_size));
//    cout << "topping" << endl;
    this->toppings.clear();
    Topping temp;
    for(size_t i = 0; i < topping_size; i++) {
        if(topping_size > 40) {
            return;
        }
//        cout << "topping no, " << i << endl;
        temp.read(file);
        this->toppings.push_back(temp);
//        if(toppings[i].get_name() == "Nothing"){
//            return;
//        }

    }
}

void Pizza::add_topping(Topping& topping)
{
    this->price += topping.get_price();
    this->toppings.push_back(topping);
}

void Pizza::clear_toppings()
{
    this->toppings.clear();
    this->price = 1500;
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

#include "Pizza.h"

Pizza::Pizza()
{
    // Default initializer
    strcpy(this->name, "Custom" );
    this->price = 1500;
}


string Pizza::get_name() const
{
    // Returns name of pizza
    return (string)this->name;
}

double Pizza::get_price() const
{
    // Returns price of pizza
    return this->price;
}

void Pizza::write(ofstream& file)
{
    // Write pizza to file
    file.write(this->name, sizeof(this->name));
    file.write((char*)(&this->price), sizeof(this->price));
    size_t topping_size = this->toppings.size();
    file.write((char*)(&topping_size), sizeof(topping_size));
    for(size_t i = 0; i < topping_size; i++)
    {
        this->toppings[i].write(file);
    }
}

void Pizza::read(ifstream& file)
{
    // Read pizza from file
    file.read(this->name, sizeof(this->name));
    file.read((char*)(&this->price), sizeof(this->price));
    size_t topping_size;
    file.read((char*)(&topping_size), sizeof(topping_size));
    this->toppings.clear();
    Topping temp;
    for(size_t i = 0; i < topping_size; i++)
    {
        if(topping_size > 40)
        {
            return;
        }
        temp.read(file);
        this->toppings.push_back(temp);
    }
}

void Pizza::add_topping(Topping& topping)
{
    // Add topping to pizza
    this->price += topping.get_price();
    this->toppings.push_back(topping);
}

void Pizza::clear_toppings()
{
    // Clears toppings
    this->toppings.clear();
    this->price = 1500;
}

ostream& operator << (ostream& out, const Pizza& pizza)
{
    // Prints pizza
    out << "  " << pizza.name << endl;
    out << "       " << pizza.price << " kr." << endl;
    out << "  ------------------" << endl;
    // Print toppings of the pizza
    out << "   Topping: " << endl;
    for(size_t i = 0; i < pizza.toppings.size(); i++ )
    {
        out << "    " << pizza.toppings[i] << endl;
    }
    return out;
}

istream& operator >> (istream& in, Pizza& pizza)
{
    // Inputs pizza
    cout << "  Name: ";
    in.getline(pizza.name, 32);

    // If pizza name is length 0. throw exception
    if(strlen(pizza.name) == 0)
    {
        throw InvalidNameException();
    }
    // If name is not alphanumeric or a space throw exception
    for(size_t i = 0; i < strlen(pizza.name); i++)
    {
        if(!isalnum(pizza.name[i]))
        {
            if(!(pizza.name[i] == ' '))
            {
                throw InvalidNameException();
            }
        }
    }

    return in;
}

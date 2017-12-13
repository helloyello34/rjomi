#include "Drink.h"

Drink::Drink()
{
    strcpy(this->name, "nothing");
    this->price = 0;
}


string Drink::get_name() const
{
    return (string)this->name;
}

double Drink::get_price() const
{
    return this->price;
}

void Drink::read(ifstream& file)
{
    // Read the name and price from the file
    file.read(this->name, sizeof(this->name));
    file.read((char*)(&this->price), sizeof(this->price));
}

void Drink::write(ofstream& file)
{
    // Write the name and price of the drink
    file.write(this->name, sizeof(this->name));
    file.write((char*)(&this->price), sizeof(this->price));
}

istream& operator >> (istream& in, Drink& drink)
{

    // Writing in the drink name
    cout << "  Drink Name: ";
    in.getline(drink.name, 32);
    for(unsigned int i = 0; i < strlen(drink.name); i++){
        if(!(isalnum(drink.name[i]))){
            if(drink.name[i] != ' ' && drink.name[i] != '.'){
                throw InvalidNameException();
            }
        }
    }
    // Writing in the drink price
    cout << "  Drink Price: ";
    in >> drink.price;
    if(in.fail()){
        in.clear();
        throw InvalidPriceException();
    }
    if(drink.price > 1000 || drink.price < 0){
        throw InvalidPriceException();
    }

    return in;
}

ostream& operator << (ostream& out, const Drink& drink)
{

    out << "    Name: " << drink.name << endl;
    out << "    Price: " << drink.price << endl;

    return out;
}

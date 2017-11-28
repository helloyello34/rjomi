#include "Pizza.h"

Pizza::Pizza()
{
    this->name = "";
    this->id = 0;
    this->price = 0;
}

Pizza::~Pizza()
{
    //dtor
}

string Pizza::get_name()
{
    return this->name;
}

void Pizza::print_ingr()
{
    for(int i = 0; i < this->alegg.size(); i++){
        cout << this->alegg[i] << endl;
    }
}

void Pizza::create_pizza()
{

}

ostream& operator << (ostream& out, const Pizza pizza)
{

    out << pizza.id << ": " << pizza.name << endl;

    return out;
}

#include "Pizza.h"

Pizza::Pizza()
{
    this->name[0] = '\0';
    this->price = 0;
}

Pizza::~Pizza()
{

}

void Pizza::add_topping(Topping topping)
{
    if(topping.valid_topping()){
        this->toppings.push_back(topping);
    }
}

void Pizza::create_pizza()
{

}

void Pizza::make_pizza()
{

}

double Pizza::get_price()
{
    return this->price;
}

void Pizza::read(fstream& file)
{
    cout << endl << endl << "Reading PIzza Chechk " << endl;

    file.read(this->name, sizeof(name));
    cout << this->name << endl;

    file.read((char*)(&this->price), sizeof(this->price));
    cout << this->price << endl;

    unsigned int size;
    file.read((char*)(&size), sizeof(size));
    cout << size << endl;

    vector<Topping>temp_toppings;
    for(unsigned int i = 0; i < size; i++){
        Topping temp;
        temp.read(file);
        temp_toppings.push_back(temp);
        cout << temp << endl;
    }

    this->toppings = temp_toppings;

    cout << "=======================" << endl;

    /*
    file >> this->name;
    //file >> this->price;
    int size = 3;
    //file >> size;
    Topping temp;
    for(int i = 0; i < size; i++){
        //temp.read(file);
        //this->toppings.push_back(temp);
        //cout << "lykkja";
    }
    */

}


void Pizza::write(fstream& file)
{
    cout << endl << endl << "Writing PIzza Chechk " << endl;
    file.write(this->name, sizeof(name));
    cout << this->name << endl;

    file.write((char*)(&this->price), sizeof(this->price));
    cout << this->price << endl;

    unsigned int size = this->toppings.size();
    file.write((char*)(&size), sizeof(size));
    cout << size << endl;


    for(unsigned    int i = 0; i < size; i++){
        this->toppings[i].write(file);
        cout << this->toppings[i] << endl;
    }

    cout << "=====================" << endl;


    /*
    file << this->name << " ";
    file << this->price << " ";
    file << this->toppings.size() << " ";
    for(unsigned int i = 0; i < this->toppings.size(); i++){
        this->toppings[i].write(file);
    }
    */
}




ostream& operator << (ostream& out, const Pizza& pizza)
{
    out << "Name: " << pizza.name << endl;
    out << "Topping: " << endl;
    for(unsigned int i = 0; i < pizza.toppings.size(); i++){
        out << " " << pizza.toppings[i] << endl;
    }
    return out;
}

istream& operator >> (istream& in, Pizza& pizza)
{
    cout << "Name: ";
    in >> pizza.name;
    ToppingUI toppingui;

    char choice = '\0';
    int toppings;

    while(choice != 'n'){
        toppingui.list_toppings();
        cout << "enter a number: ";
        in >> toppings;
        pizza.add_topping(toppingui.getTopping(toppings));
        cout << "Continue? (y,n): ";
        in >> choice;
    }

    return in;
}

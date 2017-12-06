#include "Pizza.h"

Pizza::Pizza()
{
    this->name[0] = '\0';
    this->price = 1000;
}

void Pizza::read(fstream& file)
{
    // txt file
    /*
    file >> this->name;
    file >> this->price;
    unsigned int size;
    file >> size;
    Topping temp;
    for(unsigned int i = 0; i < size; i++){
        temp.read(file);
        this->toppings.push_back(temp);
    }
    */
    // binary file

    file.read(this->name, sizeof(this->name));
    file.read((char*)(&this->price), sizeof(this->price));
    unsigned int size;
    file.read((char*)(&size), sizeof(size));
    Topping temp;
    for(unsigned int i = 0; i < size; i++){
        temp.read(file);
        this->toppings.push_back(temp);
    }


}

void Pizza::write(fstream& file)
{
    // txt file
    /*
    file << this->name << endl;
    file << this->price << endl;
    file << this->toppings.size() << endl;
    for(unsigned int i = 0; i < this->toppings.size(); i++){
        file << this->toppings[i] << endl;
    }
    */
    // binary file

    file.write(this->name, sizeof(this->name));
    file.write((char*)(&this->price), sizeof(this->price));

    unsigned int size = this->toppings.size();
    file.write((char*)(&size), sizeof(size));
    for(unsigned int i = 0; i < this->toppings.size(); i++){
        this->toppings[i].write(file);
    }

}

void  Pizza::add_topping(Topping& topping)
{
    this->toppings.push_back(topping);
}


ostream& operator << (ostream& out, const Pizza& pizza)
{
    out << "Pizza ostream read: " << endl;
    out << "Name: " << pizza.name << endl;
    out << "Price: " << pizza.price << endl;
    out << "Topping: " << endl;
    for(unsigned int i = 0; i < pizza.toppings.size(); i++){
        out << i+1 << ". " << pizza.toppings[i] << endl;
    }
    out << "End of reading ostream pizza" << endl;

    return out;
}

istream& operator >> (istream& in, Pizza& pizza)
{
    cout << "Name: ";
    in >> pizza.name;

    char choice = '\0';
    int toppingId;
    while(true){
        cout << "Add new topping? ";
        in >> choice;
        if(choice == 'n'){
            break;
        }
        Topping temp;
        pizza.top.list_toppings();
        in >> toppingId;
        temp = pizza.top.getTopping(toppingId);
        pizza.add_topping(temp);
    }

    return in;
}

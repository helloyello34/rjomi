#include "Pizza.h"

Pizza::Pizza()
{
    this->name[0] = '\0';
    this->price = 1500;
}

void Pizza::read(ifstream& file)
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
    this->toppings.clear();
    for(unsigned int i = 0; i < size; i++){
        temp.read(file);
        if(temp.get_name() == "Nothing"){
            break;
        }

        //file.read((char*)(&temp), sizeof(Topping));

        this->toppings.push_back(temp);
    }



}

void Pizza::write(ofstream& file) const
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
        //file.write((char*)(&this->toppings[i]), sizeof(Topping));
        this->toppings[i].write(file);
    }

}

void  Pizza::add_topping(Topping& topping)
{
    this->price += topping.get_price();
    this->toppings.push_back(topping);
}


ostream& operator << (ostream& out, const Pizza& pizza)
{
<<<<<<< HEAD
=======
    //out << "Pizza ostream read: " << endl;
>>>>>>> 823a7cca4a861a39252154c428fd33cce324f1a6
    out << "Name: " << pizza.name << endl;
    out << "Price: " << pizza.price << endl;
    out << "Topping: " << endl;
    for(unsigned int i = 0; i < pizza.toppings.size(); i++){
        out << i+1 << ". " << pizza.toppings[i] << endl;
    }

    return out;
}

istream& operator >> (istream& in, Pizza& pizza)
{
    cout << "Name: ";
    in >> pizza.name;

    char choice = '\0';
    int toppingId;
    ToppingUI ui;
    ui.list_toppings();
    cout << "Enter a series of numbers together (Example: 1 5 6 7 0)" << endl;
    cout << "Enter the index number of topping to add it to the pizza" << endl;
    cout << "Enter '0' To quit" << endl;

    cout << "Input: ";
    while(true){
        Topping temp;

        in >> toppingId;
        if(toppingId == 0){
            break;
        }
        temp = ui.getTopping(toppingId);
        pizza.add_topping(temp);
    }

    return in;
}

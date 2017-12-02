#include "PizzaRepo.h"

PizzaRepo::PizzaRepo()
{
    //ctor
}

PizzaRepo::~PizzaRepo()
{
    //dtor
}



void PizzaRepo::write_pizza(Pizza& pizza)
{
    fstream file;
    file.open("Pizza_Menu.dat", ios::out|ios::binary|ios::app);

    if(file.is_open()) {
        pizza.write(file);
        file.close();
    } else {
        cout << "File did not open" << endl;
    }
    //pizza.write(file);

    //file.write((char*)(&pizza), sizeof(Pizza));


}


vector<Pizza> PizzaRepo::read_pizza()
{
    fstream file;
    file.open("Pizza_Menu.dat", ios::in|ios::binary);
    vector<Pizza>vector_of_pizzas;
    Pizza temp_pizza;

    if(file.is_open()) {
        while(!(file.eof())) {
            temp_pizza.read(file);
            //cout << temp_pizza << endl;
            //file.read((char*)(&temp_pizza), sizeof(Pizza));
            vector_of_pizzas.push_back(temp_pizza);
        }
        vector_of_pizzas.pop_back();

        file.close();

    } else {
        cout << "File could not open!" << endl;
    }

    return vector_of_pizzas;
}

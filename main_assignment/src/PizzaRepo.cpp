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
    file.open("Pizza_Menu.dat", ios::out|ios::app|ios::binary|ios::app);
    //pizza.write(file);

    file.write((char*)(&pizza), sizeof(Pizza));

    file.close();
}


vector<Pizza> PizzaRepo::read_pizza()
{
    fstream file;
    file.open("Pizza_Menu.dat", ios::in|ios::out|ios::binary);
    vector<Pizza>vector_of_pizzas;
    Pizza temp_pizza;

    if(file.is_open()){

    while(!(file.eof())) {
        //temp_pizza.read(file);
        //cout << temp_pizza << endl;
        file.read((char*)(&temp_pizza), sizeof(Pizza));
        vector_of_pizzas.push_back(temp_pizza);
    }

    file.close();

    }else{
        cout << "File could not open!" << endl;
    }

    return vector_of_pizzas;
}

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
    file.open("Pizza_Menu.txt", ios::out|ios::app);
    pizza.write(file);

    file.close();
}

vector<Pizza> PizzaRepo::read_pizza()
{
    fstream file;
    file.open("Pizza_Menu.txt", ios::in|ios::out);
    vector<Pizza>vector_of_pizzas;
    Pizza temp_pizza;

    while(!(file.eof())) {
        temp_pizza.read(file);
        vector_of_pizzas.push_back(temp_pizza);
    }

    file.close();

    return vector_of_pizzas;
}

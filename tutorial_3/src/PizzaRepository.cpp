#include "PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

PizzaRepository::~PizzaRepository()
{
    //dtor
}


void PizzaRepository::store_Pizza(const Pizza& pizza)
{
    ofstream fout;
    fout.open("pizzas.txt");

    fout << pizza;

    fout.close();
}


Pizza PizzaRepository::retrieve_Pizza()
{
    Pizza pizza;

    ifstream fin;
    fin.open("pizzas.txt");

    fin >> pizza;

    fin.close();

    return pizza;

}

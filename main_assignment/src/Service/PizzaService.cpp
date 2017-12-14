#include "PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}

void PizzaService::add_pizza(Pizza& newPizza)
{
    // Call to the repository class to add the new pizza to the file
    pizza_repo.add_pizza(newPizza);
}

void PizzaService::retreve_pizza(vector<Pizza>&pizzas)
{
    // Call to the repository class to read data to the vector
    pizza_repo.retreve_pizza(pizzas);
}

void PizzaService::overwrite_pizza(vector<Pizza>&pizzas)
{
    // Call to the repository class to write over exsisting data
    pizza_repo.overwrite_pizza(pizzas);
}


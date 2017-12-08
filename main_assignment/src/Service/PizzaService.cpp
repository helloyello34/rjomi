#include "PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}

void PizzaService::add_pizza(Pizza& newPizza)
{
    pizza_repo.add_pizza(newPizza);
}

void PizzaService::retreve_pizza(vector<Pizza>&pizzas)
{
    pizza_repo.retreve_pizza(pizzas);
}

void PizzaService::overwrite_pizza(vector<Pizza>&pizzas)
{
    pizza_repo.overwrite_pizza(pizzas);
}


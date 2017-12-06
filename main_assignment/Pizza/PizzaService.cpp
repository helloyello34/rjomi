#include "PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}


void PizzaService::newPizza(const Pizza& pizza)
{
    PizzaRepo pizzarepository;
    pizzarepository.write_pizza(pizza);
    //pizza_repo.write(pizza);
    //pizzaRepository.write_pizza(pizza);
}



void PizzaService::readPizza(vector<Pizza>&pizzas)
{
    PizzaRepo pizza_repo;
    pizza_repo.read_pizza(pizzas);
}

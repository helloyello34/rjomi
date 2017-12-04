#include "PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}


void PizzaService::newPizza(const Pizza& pizza)
{
    pizzarepository.write_pizza(pizza);
    //pizzaRepository.write_pizza(pizza);
}



void PizzaService::readPizza()
{

}

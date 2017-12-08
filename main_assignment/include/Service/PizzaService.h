#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "PizzaRepository.h"
#include "Pizza.h"


class PizzaService
{
    public:
        PizzaService();
        void add_pizza(Pizza& newPizza);
        void retreve_pizza(vector<Pizza>&pizzas);
        void overwrite_pizza(vector<Pizza>&pizzas);

    private:
        PizzaRepository pizza_repo;

};

#endif // PIZZASERVICE_H

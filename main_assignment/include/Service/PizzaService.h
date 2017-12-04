#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include <iostream>
#include <vector>

#include "PizzaRepo.h"
#include "Pizza.h"

using namespace std;



class PizzaService
{
    public:
        PizzaService();
        void newPizza(const Pizza& pizza);
        void readPizza(vector<Pizza>&pizzas);
    private:
        PizzaRepo pizza_repo;
};

#endif // PIZZASERVICE_H

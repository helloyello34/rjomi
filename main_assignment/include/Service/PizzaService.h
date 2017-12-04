#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "PizzaRepo.h"
#include "PizzaUI.h"
#include "Pizza.h"

#include <iostream>

using namespace std;

class PizzaService
{
    public:
        PizzaService();
        void newPizza(const Pizza& pizza);
        void readPizza();
    private:
        //PizzaRepo pizza_repo();
};

#endif // PIZZASERVICE_H

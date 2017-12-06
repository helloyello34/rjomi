#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "Pizza.h"
#include "PizzaRepository.h"

#include <iostream>

using namespace std;


class PizzaService
{
    public:
        PizzaService();
        void new_pizza();
        void store_pizza(const Pizza& pizza);
        void retrive_pizza();
        void list_pizza();

    private:
        vector<Pizza>pizzas;
        PizzaRepository pizza_repo;
};

#endif // PIZZASERVICE_H

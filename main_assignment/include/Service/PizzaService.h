#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "PizzaRepository.h"
#include "Pizza.h"


class PizzaService
{
    public:
        /// Constructor for Pizza Service
        PizzaService();

        /// Send pizza to Repository to store the pizza
        void add_pizza(Pizza& newPizza);

        /// Sends vector to Repository and reads from file
        void retreve_pizza(vector<Pizza>&pizzas);

        /// Sends vector to Repository and writes over all former data
        void overwrite_pizza(vector<Pizza>&pizzas);

    private:
        PizzaRepository pizza_repo;

};

#endif // PIZZASERVICE_H

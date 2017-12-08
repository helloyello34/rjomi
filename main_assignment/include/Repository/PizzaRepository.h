#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H

#include "Pizza.h"

#include "UnableToOpenFileException.h"

class PizzaRepository
{
    public:
        PizzaRepository();
        void add_pizza(Pizza& newPizza);
        void retreve_pizza(vector<Pizza>&pizzas);
        void overwrite_pizza(vector<Pizza>&pizzas);
    private:
};

#endif // PIZZAREPOSITORY_H

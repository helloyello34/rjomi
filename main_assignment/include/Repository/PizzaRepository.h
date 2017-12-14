#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H

#include "Pizza.h"

#include "UnableToOpenFileException.h"

class PizzaRepository
{
public:
    /// Pizza Repository constructor
    PizzaRepository();

    /// Store newPizza to file
    void add_pizza(Pizza& newPizza);

    /// reads from file to pizzas
    void retreve_pizza(vector<Pizza>&pizzas);

    /// writes over former data from pizzas
    void overwrite_pizza(vector<Pizza>&pizzas);
private:
};

#endif // PIZZAREPOSITORY_H

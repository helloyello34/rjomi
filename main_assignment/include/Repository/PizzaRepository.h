#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H

#include <fstream>
#include <iostream>
#include <vector>

#include "Pizza.h"

using namespace std;

class PizzaRepository
{
    public:
        PizzaRepository();
        void write(const Pizza& pizza);
        void read(vector<Pizza>&pizzas);
    private:
};

#endif // PIZZAREPOSITORY_H

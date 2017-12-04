#ifndef PIZZAREPO_H
#define PIZZAREPO_H

#include "Pizza.h"
#include "PizzaService.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class PizzaRepo
{
    public:
        PizzaRepo();
        virtual ~PizzaRepo();
        void read_pizza(vector<Pizza>&vector_of_pizza);
        void write_pizza(const Pizza& pizza);
    private:
        //int number_of_pizzas;
};

#endif // PIZZAREPO_H

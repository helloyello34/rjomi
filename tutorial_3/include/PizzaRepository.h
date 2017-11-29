#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H

#include "Pizza.h"
#include <fstream>


using namespace std;

class PizzaRepository
{
    public:
        PizzaRepository();
        virtual ~PizzaRepository();

        void store_Pizza(Pizza pizza);
        Pizza retrieve_Pizza();

    protected:

    private:
};

#endif // PIZZAREPOSITORY_H

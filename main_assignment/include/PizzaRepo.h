#ifndef PIZZAREPO_H
#define PIZZAREPO_H

#include"Pizza.h"
#include"PizzaUI.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class PizzaRepo
{
    public:
        PizzaRepo();
        virtual ~PizzaRepo();

        vector<Pizza> read_pizza();
        void write_pizza(Pizza& pizza);
    private:
};

#endif // PIZZAREPO_H

#ifndef PIZZAUI_H
#define PIZZAUI_H

#include "Pizza.h"
#include "PizzaRepository.h"

#include <IOSTREAM>

using namespace std;

class PizzaUI
{
    public:
        PizzaUI();
        virtual ~PizzaUI();
        void startUI();

    protected:

    private:
};

#endif // PIZZAUI_H

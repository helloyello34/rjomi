#ifndef SALESMANUI_H
#define SALESMANUI_H

#include <stdlib.h>
#include <iostream>

#include "../PIZZA/PizzaUI.h"
#include "OrderUI.h"

using namespace std;

class SalesmanUI
{
    public:
        SalesmanUI();
        virtual ~SalesmanUI();

        void startUI();

    private:
};

#endif // SALESMANUI_H

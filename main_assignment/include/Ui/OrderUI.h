#ifndef ORDERUI_H
#define ORDERUI_H

#include <stdlib.h>
#include <iostream>

#include "Order.h"
#include "OrderService.h"

#include "PizzaUI.h"
#include "DrinkUI.h"
//#include "SidesUI.h"

using namespace std;

class OrderUI
{
    public:
        OrderUI();
        void startUI();
        void make_order();
        void add_pizza();
        void add_sides();
        void add_drink();
        void show_order();

    private:
        PizzaUI pizza_ui;
        DrinkUI drink_ui;
        SidesUI sides_ui;

        OrderService order_service;
};

#endif // ORDERUI_H

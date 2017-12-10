#ifndef ORDERUI_H
#define ORDERUI_H

#include <stdlib.h>
#include <iostream>

#include "Order.h"
#include "OrderService.h"

#include "PizzaUI.h"
#include "DrinkUI.h"
#include "SidesUI.h"

using namespace std;

class OrderUI
{
    public:
        OrderUI();
        void salesmanUI(Location& staff_location);
        void make_order(Location& staff_location);
        void add_pizza(Order& order);
        void add_sides(Order& order);
        void add_drink(Order& order);
        void show_order(Location& location);
        void look_for_order(Location& location);
        void erase_other_locations(Location& location);
        void store_order(Order& order);

    private:
        PizzaUI pizza_ui;
        DrinkUI drink_ui;
        SidesUI sides_ui;

        vector<Order>orders;

        OrderService order_service;
};

#endif // ORDERUI_H

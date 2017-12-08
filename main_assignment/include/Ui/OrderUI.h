#ifndef ORDERUI_H
#define ORDERUI_H

#include <stdlib.h>
#include <iostream>

#include "Order.h"
#include "OrderService.h"

using namespace std;

class OrderUI
{
    public:
        OrderUI();
        void startUI();
        void make_order();
        void show_order();

    private:
        OrderService order_service;
        int numberOfOrders;
};

#endif // ORDERUI_H

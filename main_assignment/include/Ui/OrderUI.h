#ifndef ORDERUI_H
#define ORDERUI_H

#include <stdlib.h>
#include <iostream>

#include "Order.h"

using namespace std;

class OrderUI
{
    public:
        OrderUI();
        virtual ~OrderUI();
        void startUI();
        void make_order();
        void show_order();
    private:
        Order *orders;
        int numberOfOrders;
};

#endif // ORDERUI_H

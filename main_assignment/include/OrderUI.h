#ifndef ORDERUI_H
#define ORDERUI_H

#include "Order.h"

class OrderUI
{
    public:
        OrderUI();
        virtual ~OrderUI();
        void startUI();
    private:
        Order *orders;
        int numberOfOrders;
};

#endif // ORDERUI_H

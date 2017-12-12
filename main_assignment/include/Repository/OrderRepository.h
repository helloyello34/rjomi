#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "Order.h"


class OrderRepository
{
    public:
        OrderRepository();
        void store_order(Order& order);
        void get_orders(vector<Order>&orders);
        void overwrite_orders(vector<Order>&orders);
        void store_receved_orders(Order& order);
        void get_old_orders(vector<Order>&orders);
    private:
};

#endif // ORDERREPOSITORY_H

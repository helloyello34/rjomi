#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "Order.h"


class OrderRepository
{
public:
    /// Order Repository constructor
    OrderRepository();

    /// Store order to current orders
    void store_order(Order& order);

    /// reads from current orders to orders
    void get_orders(vector<Order>&orders);

    /// writes over former data on current orders
    void overwrite_orders(vector<Order>&orders);

    /// Store order to Old orders
    void store_receved_orders(Order& order);

    /// reads from Old orders to orders
    void get_old_orders(vector<Order>&orders);
private:
};

#endif // ORDERREPOSITORY_H

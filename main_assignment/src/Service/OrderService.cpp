#include "OrderService.h"

OrderService::OrderService()
{
    //ctor
}

void OrderService::store_order(Order& order)
{
    // Call to the repository class to store the new order in current order
    order_repo.store_order(order);
}

void OrderService::fill_vector(vector<Order>&orders)
{
    // Call to the repository class to read data to vector from current orders
    order_repo.get_orders(orders);
}

void OrderService::overwrite_orders(vector<Order>&orders)
{
    // Call to the repository class to write over exsisting data in current orders
    order_repo.overwrite_orders(orders);
}


void OrderService::store_old_order(Order& order)
{
    // Call to the repository class to store the order in old orders
    order_repo.store_receved_orders(order);
}

void OrderService::fill_old_vector(vector<Order>&orders)
{
    // Call to the repository class to read old orders to the vector
    order_repo.get_old_orders(orders);
}

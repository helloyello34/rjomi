#include "OrderService.h"

OrderService::OrderService()
{
    //ctor
}

void OrderService::store_order(Order& order)
{
    order_repo.store_order(order);
}

void OrderService::fill_vector(vector<Order>&orders)
{
    order_repo.get_orders(orders);
}

void OrderService::overwrite_orders(vector<Order>&orders)
{
    order_repo.overwrite_orders(orders);
}


void OrderService::store_old_order(Order& order)
{
    order_repo.store_receved_orders(order);
}

void OrderService::fill_old_vector(vector<Order>&orders)
{
    order_repo.get_old_orders(orders);
}

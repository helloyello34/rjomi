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

#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "Order.h"
#include "OrderRepository.h"

class OrderService
{
    public:
        OrderService();
        void store_order(Order& order);
        void fill_vector(vector<Order>&orders);
    private:
        OrderRepository order_repo;
};

#endif // ORDERSERVICE_H

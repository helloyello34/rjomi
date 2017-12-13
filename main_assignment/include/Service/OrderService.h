#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "Order.h"
#include "OrderRepository.h"

class OrderService
{
    public:
        /// Constructor for Order Service
        OrderService();

        /// Sends order to Repository to be stored
        void store_order(Order& order);

        /// Sends vector to Repository to be read all current orders
        void fill_vector(vector<Order>&orders);

        /// Sends vector to Repository to over write all former current order data
        void overwrite_orders(vector<Order>&orders);

        /// Sends order to Repository to store in another file
        void store_old_order(Order& order);

        /// Sends vector to Repository to be read all old orders
        void fill_old_vector(vector<Order>&orders);
    private:
        OrderRepository order_repo;
};

#endif // ORDERSERVICE_H

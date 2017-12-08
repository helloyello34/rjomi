#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "Order.h"
#include "OrderRepository.h"

class OrderService
{
    public:
        OrderService();
        void addOrder();
        void list_order();
        void edit_order();
        void delete_order();
        vector <Order> get_vector();
        Order get_order();

    private:
        OrderRepository order_repo;
};

#endif // ORDERSERVICE_H

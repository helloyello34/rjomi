#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "Order.h"

#include <iostream>
#include <vector>

using namespace std;

class OrderRepository
{
    public:
        OrderRepository();
        void store_order(Order& order);
        void retrieve_order(vector<Order>& Order);
        void overwrite_order(vector<Order>& Order);

    private:

};

#endif // ORDERREPOSITORY_H

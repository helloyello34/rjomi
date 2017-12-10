#include "OrderRepository.h"

OrderRepository::OrderRepository()
{
    //ctor
}

void OrderRepository::store_order(Order& order)
{
    ofstream file;
    file.open("binaries\\Orders\\currentOrders.dat", ios::binary|ios::app);

    if(file.is_open()) {
        order.write(file);
    } else {
        throw UnableToOpenFileException();
    }
}

void OrderRepository::get_orders(vector<Order>&orders)
{
    ifstream file;
    file.open("binaries\\Orders\\currentOrders.dat", ios::binary);

    if(file.is_open()) {
        Order tempOrder;
        orders.clear();
        while(!(file.eof())) {
            tempOrder.read(file);
            orders.push_back(tempOrder);
        }
        orders.pop_back();
    } else {
        throw UnableToOpenFileException();
    }
}

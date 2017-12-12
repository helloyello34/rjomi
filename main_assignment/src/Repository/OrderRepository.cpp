#include "OrderRepository.h"

OrderRepository::OrderRepository()
{
    //ctor
}

void OrderRepository::store_order(Order& order)
{
    ofstream file;
    file.open("binaries\\Orders\\currentOrders.dat", ios::binary|ios::app);

    if(file.is_open())
    {
        order.write(file);
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void OrderRepository::get_orders(vector<Order>&orders)
{
    ifstream file;
    file.open("binaries\\Orders\\currentOrders.dat", ios::binary);

    if(file.is_open())
    {
        Order tempOrder;
        orders.clear();
        while(!(file.eof()))
        {
            tempOrder.read(file);
            orders.push_back(tempOrder);
        }
        orders.pop_back();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void OrderRepository::overwrite_orders(vector<Order>&orders)
{
    ofstream file;
    file.open("binaries\\Orders\\currentOrders.dat", ios::binary);

    if(file.is_open())
    {

        for(size_t i = 0; i < orders.size(); i++)
        {
            orders[i].write(file);
        }

        file.close();

    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void OrderRepository::store_receved_orders(Order& order)
{
    ofstream file;
    file.open("binaries\\Orders\\oldOrders.dat", ios::binary|ios::app);

    if(file.is_open())
    {
        order.write(file);
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void OrderRepository::get_old_orders(vector<Order>&orders)
{
    ifstream file;
    file.open("binaries\\Orders\\oldOrders.dat", ios::binary);

    if(file.is_open())
    {
        Order temp;
        while(!(file.eof()))
        {
            temp.read(file);
            orders.push_back(temp);
        }
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

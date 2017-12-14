#include "OrderRepository.h"

OrderRepository::OrderRepository()
{
    //ctor
}

void OrderRepository::store_order(Order& order)
{
    // Makes ofstream to write to current order data file
    ofstream file;
    file.open("binaries\\Orders\\currentOrders.dat", ios::binary|ios::app);

    // Checks if the file is open
    if(file.is_open())
    {
        // Writes the file to the file
        order.write(file);

        // Close file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void OrderRepository::get_orders(vector<Order>&orders)
{
    // Makes ifstream to read from current order data file
    ifstream file;
    file.open("binaries\\Orders\\currentOrders.dat", ios::binary);

    // Checks if the file is open
    if(file.is_open())
    {
        // Makes temp order
        Order tempOrder;

        // Clears the vector
        orders.clear();

        while(!(file.eof()))
        {
            // Reads to the temp order
            tempOrder.read(file);

            // Puts it to the vector
            orders.push_back(tempOrder);
        }
        // Deletes the last instance of pizza
        orders.pop_back();

        // Close file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void OrderRepository::overwrite_orders(vector<Order>&orders)
{
    // Makes ofstream to write to current order data file
    ofstream file;
    file.open("binaries\\Orders\\currentOrders.dat", ios::binary);

    // Checks if the file is open
    if(file.is_open())
    {

        for(size_t i = 0; i < orders.size(); i++)
        {
            // Writes the order to the file
            orders[i].write(file);
        }

        // Close file
        file.close();

    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void OrderRepository::store_receved_orders(Order& order)
{
    // Makes ofstream to write to old order data file
    ofstream file;
    file.open("binaries\\Orders\\oldOrders.dat", ios::binary|ios::app);

    // Checks if the file is open
    if(file.is_open())
    {
        // Writes the order to the file
        order.write(file);

        // Close file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void OrderRepository::get_old_orders(vector<Order>&orders)
{
    // Makes ifstream to read from old order data file
    ifstream file;
    file.open("binaries\\Orders\\oldOrders.dat", ios::binary);

    // Checks if the file is open
    if(file.is_open())
    {
        // Creates a temp order
        Order temp;
        while(!(file.eof()))
        {
            // Reads from the file to the order
            temp.read(file);

            // Sets the order to the vector
            orders.push_back(temp);
        }
        // Deletes the last instance of order
        orders.pop_back();

        // Close file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

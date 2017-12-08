#include "OrderRepository.h"

OrderRepository::OrderRepository()
{
    //ctor
}

void OrderRepository::store_order(Order& order)
{
    //open file to write to
    ofstream file;
    file.open("binaries\\Menu\\order.dat", ios::binary|ios::app);

    //check if file is open
    if(file.is_open()){
        order.write(file);
        file.close();
    } else {
        cout << "'order.dat' file could not open! " << endl;
    }
}

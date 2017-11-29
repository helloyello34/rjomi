#include "Order.h"

Order::Order()
{

}

Order::~Order()
{
    delete[] this->orders;
}


#include "Order.h"

Order::Order()
{

}

Order::~Order()
{

}

void Order::add_pizza(Pizza pizza)
{
    this->pizzas.push_back(pizza);
    //this->price += pizza.get_price();
}

ostream& operator << (ostream& out, const Order& order)
{
    for(unsigned int i = 0; i < order.pizzas.size(); i++){

    }

    return out;
}

#include "Order.h"

using namespace std;

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
        out << "  Name: " << order.pizzas[i].get_name() << endl;
        out << "  Price: " << order.pizzas[i].get_price() << endl;
    }

    for(unsigned int i = 0; i < order.drinks.size(); i++){
        out << "  Name: " << order.drinks[i].get_name() << endl;
        out << "  Price: " << order.drinks[i].get_price() << endl;
    }

    for(unsigned int i = 0; i < order.sides.size(); i++){
        out << "  Name: " << order.sides[i].get_name() << endl;
        out << "  Price: " << order.sides[i].get_price() << endl;
    }
    return out;
}

istream& operator >> (istream& in, Order& order)
{
    cout << "===== Writing new order =====" << endl;
    for(unsigned int i = 0; i < order.pizzas.size(); i++){
        in >> order.pizzas[i];
    }
    for(unsigned int i = 0; i < order.drinks.size(); i++){
        in >> order.drinks[i];
    }
    for(unsigned int i = 0; i < order.sides.size(); i++){
        in >> order.sides[i];
    }
}

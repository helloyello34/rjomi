#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>

using namespace std;


#include "Pizza.h"
//#include "Drink.h"
//#include "Side.h"

using namespace std;

class Order
{
    public:
        Order();
        void add_pizza(Pizza pizza);
        //void add_pizza(Pizza pizza);
        //void add_drink(Drink drink);
        //void add_sides(Side side);
        friend istream& operator >> (istream& in, Order& order);
        friend ostream& operator << (ostream& out, const Order& order);
        virtual ~Order();
    private:
        double price;
        vector<Pizza>pizzas;
        //Drink* drink;
        //Side* side;

};

#endif // ORDER_H

#ifndef ORDER_H
#define ORDER_H

//<<<<<<< HEAD
#include <iostream>

using namespace std;



#include <iostream>

//#include "Pizza.h"
//#include "Drink.h"
//#include "Side.h"

using namespace std;

class Order
{
    public:
        Order();

       /// void add_pizza(Pizza pizza);

        //void add_pizza(Pizza pizza);

        //void add_drink(Drink drink);
        //void add_sides(Side side);
        friend istream& operator >> (istream& in, Order& order);
        friend ostream& operator << (ostream& out, const Order& order);
        virtual ~Order();
    private:
        double price;

        ///Pizza* pizza;

        //Pizza* pizza;

        //Drink* drink;
        //Side* side;
        int numberOfPizza;
        //int numberOfDrinks;
        //int numberOfSides;
        int currentNumberOfPizza;
        //int currentNumberOfDrinks;
        //int currentNumberOfSides;
};

#endif // ORDER_H

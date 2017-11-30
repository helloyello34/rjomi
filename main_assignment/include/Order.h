#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>

using namespace std;


<<<<<<< HEAD
#include "Pizza.h"
=======
#include <iostream>

//#include "Pizza.h"
>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
//#include "Drink.h"
//#include "Side.h"

using namespace std;

class Order
{
    public:
        Order();
<<<<<<< HEAD
        void add_pizza(Pizza pizza);
=======

       /// void add_pizza(Pizza pizza);
>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
        //void add_pizza(Pizza pizza);
        //void add_drink(Drink drink);
        //void add_sides(Side side);
        friend istream& operator >> (istream& in, Order& order);
        friend ostream& operator << (ostream& out, const Order& order);
        virtual ~Order();
    private:
        double price;
<<<<<<< HEAD
        vector<Pizza>pizzas;
=======

        ///Pizza* pizza;

        //Pizza* pizza;
>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
        //Drink* drink;
        //Side* side;

};

#endif // ORDER_H

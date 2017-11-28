#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();
        string get_name();
        void print_ingr();
        void create_pizza();
        friend ostream& operator << (ostream& out, const Pizza pizza);
    private:
        int id;
        int price;
        vector<string>alegg;
        string name;
};

#endif // PIZZA_H

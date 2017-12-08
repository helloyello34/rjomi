#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H


#include <iostream>
#include <fstream>
#include <vector>

#include "Topping.h"

#include "UnableToOpenFileException.h"


using namespace std;


class ToppingRepo
{
    public:
        ToppingRepo();
        virtual ~ToppingRepo();
        void store_toppings(Topping& newTop);
        void retreve_toppings(vector<Topping>&toppings);
        void overwrite_toppings(vector<Topping>&toppings);
    private:
};

#endif // TOPPINGREPO_H

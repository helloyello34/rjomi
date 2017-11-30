#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H


#include <iostream>
#include <fstream>

#include "Topping.h"
#include "ToppingUI.h"


using namespace std;


class ToppingRepo
{
    public:
        ToppingRepo();
        virtual ~ToppingRepo();
        void store_toppings();
        Topping get_toppings();
    private:
};

#endif // TOPPINGREPO_H

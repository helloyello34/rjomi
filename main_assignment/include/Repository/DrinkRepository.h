#ifndef DRINKREPOSITORY_H
#define DRINKREPOSITORY_H

#include "Drink.h"

#include <iostream>
#include <vector>

using namespace std;

class DrinkRepository
{
    public:
        DrinkRepository();
        void store_drink(Drink& drink);
        void retreve_drink(vector<Drink>&drinks);
        void overwrite_drink(vector<Drink>&drinks);
    private:
};

#endif // DRINKREPOSITORY_H

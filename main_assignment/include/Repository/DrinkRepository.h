#ifndef DRINKREPOSITORY_H
#define DRINKREPOSITORY_H

#include "Drink.h"

#include <iostream>
#include <vector>

using namespace std;

class DrinkRepository
{
    public:

        /// Drink Repository constructor
        DrinkRepository();

        /// Store drink to drink file
        void store_drink(Drink& drink);

        /// reads to drinks from drink file
        void retreive_drink(vector<Drink>&drinks);

        /// Write over drink file
        void overwrite_drink(vector<Drink>&drinks);
    private:
};

#endif // DRINKREPOSITORY_H

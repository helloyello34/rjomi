#ifndef DRINKSERVICE_H
#define DRINKSERVICE_H

#include "Drink.h"
#include "DrinkRepository.h"


class DrinkService
{
    public:
        DrinkService();
        void add_drink(Drink& newDrink);
        void overwrtie_drinks(vector<Drink>&drinks);
        vector<Drink> get_drinks_vector();
        Drink get_drink(vector<Drink>&drinks);
    private:
        DrinkRepository drink_repo;
};

#endif // DRINKSERVICE_H

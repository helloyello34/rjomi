#ifndef DRINKUI_H
#define DRINKUI_H

#include "Drink.h"
#include "DrinkService.h"

class DrinkUI
{
    public:
        DrinkUI();

        void add_drink();


    private:
        vector<Drink>drinks;

        DrinkService drink_service;
};

#endif // DRINKUI_H

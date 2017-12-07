#ifndef DRINKSERVICE_H
#define DRINKSERVICE_H

#include "Drink.h"
#include "DrinkRepository.h"


class DrinkService
{
    public:
        DrinkService();
        void addDrink();
        void list_drinks();
        void edit_drinks();
        void delete_drinks();
        Drink get_drink();
    private:
        vector<Drink>drinks;
        DrinkRepository drink_repo;
};

#endif // DRINKSERVICE_H

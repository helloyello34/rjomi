#ifndef DRINKSERVICE_H
#define DRINKSERVICE_H

#include "Drink.h"
#include "DrinkRepository.h"


class DrinkService
{
public:

    /// Constructor for drink Service
    DrinkService();

    /// Send a drink to the Repository
    void add_drink(Drink& newDrink);

    /// Sends vector to Repository and overwrites the data in file
    void overwrtie_drinks(vector<Drink>&drinks);

    /// Reads data from Repository and fills the vector
    vector<Drink> get_drinks_vector();

private:
    DrinkRepository drink_repo;
};

#endif // DRINKSERVICE_H

#include "DrinkService.h"

DrinkService::DrinkService()
{
    //ctor
}

void DrinkService::add_drink(Drink& newDrink)
{
    // Call to the repository class to store the new drink
    drink_repo.store_drink(newDrink);
}

vector<Drink> DrinkService::get_drinks_vector()
{
    // Call to the repository class to read data from file to vector
    vector<Drink>temp;
    drink_repo.retreive_drink(temp);
    return temp;
}

void DrinkService::overwrtie_drinks(vector<Drink>&drinks)
{
    // Call to the repository to overwrite the exsisting data
    drink_repo.overwrite_drink(drinks);
}

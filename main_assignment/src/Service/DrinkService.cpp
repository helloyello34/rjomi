#include "DrinkService.h"

DrinkService::DrinkService()
{
    //ctor
}

void DrinkService::add_drink(Drink& newDrink)
{
    drink_repo.store_drink(newDrink);
}

vector<Drink> DrinkService::get_drinks_vector()
{
    vector<Drink>temp;
    drink_repo.retreve_drink(temp);
    return temp;
}

void DrinkService::overwrtie_drinks(vector<Drink>&drinks)
{
    drink_repo.overwrite_drink(drinks);
}

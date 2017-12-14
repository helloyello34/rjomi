#include "ToppingService.h"

ToppingService::ToppingService()
{
    //ctor
}

void ToppingService::add_topping(Topping& newTop)
{
    // Call to repository class to store the new topping
    topping_repo.store_toppings(newTop);
}

vector<Topping> ToppingService::get_topping_vector()
{
    // Call to repository class to read the data to the vector
    vector<Topping>temp;
    topping_repo.retreve_toppings(temp);
    return temp;

}

void ToppingService::overwrite_topping(vector<Topping>&topping)
{
    // Call to repository class to write over data in file
    topping_repo.overwrite_toppings(topping);
}

#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H

#include "Topping.h"
#include "ToppingRepo.h"

class ToppingService
{
public:
    /// Constructor for Topping Service
    ToppingService();

    /// Send topping to the Repository
    void add_topping(Topping& newTop);

    /// get toppings from the Repository
    vector<Topping> get_topping_vector();

    /// Overwrites the file in repository
    void overwrite_topping(vector<Topping>&topping);
private:
    ToppingRepo topping_repo;

};

#endif // TOPPINGSERVICE_H

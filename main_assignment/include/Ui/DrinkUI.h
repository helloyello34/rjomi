#ifndef DRINKUI_H
#define DRINKUI_H

#include "Drink.h"
#include "DrinkService.h"

#include <stdlib.h>


class DrinkUI
{
public:
    /// Constructor for DrinkUI
    DrinkUI();

    /////////////////////////////////////////////////////
    /// Add drink to the menu
    void add_drink();

    /// Delete drink from the menu
    void delete_drink();

    /// Edit/Change drink from the menu
    void edit_drink();

    /// View drink from menu
    void view_drinks();
    /////////////////////////////////////////////////////

    /////////////////////////////////////////////////////
    /// Returns a specific drink
    Drink get_drink(size_t id);

    /// Returns the number of drinks in menu
    size_t get_vector_size();
    /////////////////////////////////////////////////////

private:
    vector<Drink>drinks;
    DrinkService drink_service;
};

#endif // DRINKUI_H

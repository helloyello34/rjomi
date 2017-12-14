#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H


#include <iostream>
#include <fstream>
#include <vector>

#include "Topping.h"

#include "UnableToOpenFileException.h"


using namespace std;


class ToppingRepo
{
public:

    /// Topping Repository constructor
    ToppingRepo();

    /// Store newTop to file
    void store_toppings(Topping& newTop);

    /// reads from file to toppings
    void retreve_toppings(vector<Topping>&toppings);

    /// writes over former data from toppings
    void overwrite_toppings(vector<Topping>&toppings);
private:
};

#endif // TOPPINGREPO_H

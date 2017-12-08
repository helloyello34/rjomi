#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H

#include "Topping.h"
#include "ToppingRepo.h"

class ToppingService
{
    public:
        ToppingService();
        void add_topping(Topping& newTop);
        vector<Topping> get_topping_vector();
        void overwrite_topping(vector<Topping>&topping);
    private:
        ToppingRepo topping_repo;

};

#endif // TOPPINGSERVICE_H

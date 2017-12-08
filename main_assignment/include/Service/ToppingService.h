#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H

#include "Topping.h"
#include "ToppingRepo.h"

class ToppingService
{
    public:
        ToppingService();
        void add_topping();
        void list_topping();
        void edit_topping();
        void delete_topping();
        Topping get_topping();
    private:
        vector<Topping>toppings;
        ToppingRepo topping_repo;

};

#endif // TOPPINGSERVICE_H

#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "PizzaRepository.h"
#include "Pizza.h"
#include "ToppingService.h"


class PizzaService
{
    public:
        PizzaService();
        void add_pizza_to_menu();
        void list_pizza_menu();

    private:
        PizzaRepository pizza_repo;
        ToppingService topping_service;

};

#endif // PIZZASERVICE_H

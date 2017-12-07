#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "PizzaRepository.h"
#include "Pizza.h"
#include "ToppingService.h"


class PizzaService
{
    public:
        PizzaService();

    private:
        PizzaRepository pizza_repo;
        ToppingService topping_service;

};

#endif // PIZZASERVICE_H

#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <stdlib.h>
#include <iostream>
#include <string>

#include "ToppingUI.h"

// Invlude for service classes
#include "DrinkUI.h"
#include "SidesUI.h"
#include "PizzaUI.h"
#include "LocationService.h"
#include "ToppingUI.h"



using namespace std;

class ManagerUI
{
    public:
        ManagerUI();

        void startUI();
        void editMenuUI();
        void LocationUI();
        void pizza();
        void toppings();
        void drinks();
        void sides();

    private:
        LocationService location_service;

        DrinkUI drink_ui;
        SidesUI sides_ui;
        PizzaUI pizza_ui;
        ToppingUI topping_ui;
//        ToppingService topping_service;
};

#endif // MANAGERUI_H

#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <stdlib.h>
#include <iostream>
#include <string>

#include "ToppingUI.h"

// Invlude for service classes
#include "DrinkService.h"
#include "SidesService.h"
#include "PizzaService.h"
#include "LocationService.h"



using namespace std;

class ManagerUI
{
    public:
        ManagerUI();
        virtual ~ManagerUI();

        void startUI();
        void editMenuUI();
        void LocationUI();
        void pizza();
        void toppings();
        void drinks();
        void sides();

    private:
        LocationService location_service;

        DrinkService drink_service;
        SidesService sides_service;
        PizzaService pizza_service;
//        ToppingService topping_service;
};

#endif // MANAGERUI_H

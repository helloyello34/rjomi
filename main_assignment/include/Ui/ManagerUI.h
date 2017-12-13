#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <stdlib.h>


/// Including Ui classes
#include "LocationUI.h"
#include "DrinkUI.h"
#include "SidesUI.h"
#include "PizzaUI.h"
#include "ToppingUI.h"
#include "OrderUI.h"





class ManagerUI
{
    public:
        ManagerUI();

        /// Start up UI
        void startUI();

        /// Edit menu UI
        void editMenuUI();

        /// menu to edit locations
        void Location();

        /// menu to edit pizzas
        void pizza();

        /// menu to edit toppings
        void toppings();

        /// menu to edit drinks
        void drinks();

        /// menu to edit sides
        void sides();

    private:
        LocationUI location_ui;
        DrinkUI drink_ui;
        SidesUI sides_ui;
        PizzaUI pizza_ui;
        ToppingUI topping_ui;
        OrderUI order_ui;
};

#endif // MANAGERUI_H

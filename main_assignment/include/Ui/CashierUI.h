#ifndef CASHIERUI_H
#define CASHIERUI_H

#include <stdlib.h>
#include <iostream>

/// Include ui classes
#include "LocationUI.h"
#include "OrderUI.h"

using namespace std;

class CashierUI
{
    public:
        CashierUI();

        /// screen that loads when cashier is run
        void startUI();

        /// sets this cashier to a location
        void choose_location();

        /// Make order paid or served
        void status_order();

    private:
        Location my_location;
        LocationUI location_ui;
        OrderUI order_ui;
};

#endif // CASHIERUI_H

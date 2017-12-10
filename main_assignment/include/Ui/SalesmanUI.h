#ifndef SALESMANUI_H
#define SALESMANUI_H

#include <stdlib.h>
#include <iostream>


#include "OrderUI.h"
#include "LocationUI.h"

using namespace std;

class SalesmanUI
{
    public:
        SalesmanUI();
        virtual ~SalesmanUI();

        void startUI();
        void choose_location();

    private:
        Location my_location;
        LocationUI location_ui;
        OrderUI order_ui;
};

#endif // SALESMANUI_H

#ifndef BAKERUI_H
#define BAKERUI_H

#include <stdlib.h>
#include <iostream>

#include "LocationUI.h"
#include "OrderUI.h"

using namespace std;

class BakerUI
{
public:
    /// Constructor for Baker UI
    BakerUI();

    /// Choose location for the baker
    void choose_location();

    /// UI for the baker
    void startUI();

private:
    LocationUI location_ui;
    OrderUI order_ui;

    Location my_location;
};

#endif // BAKERUI_H

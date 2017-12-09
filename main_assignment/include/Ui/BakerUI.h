#ifndef BAKERUI_H
#define BAKERUI_H

#include <stdlib.h>
#include <iostream>

#include "LocationUI.h"

using namespace std;

class BakerUI
{
    public:
        BakerUI();
        virtual ~BakerUI();

        void startUI();

    private:
        LocationUI location_ui;
};

#endif // BAKERUI_H

#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <stdlib.h>
#include <iostream>
#include <string>

#include "ToppingUI.h"


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
};

#endif // MANAGERUI_H

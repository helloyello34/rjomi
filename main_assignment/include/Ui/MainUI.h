#ifndef MAINUI_H
#define MAINUI_H

#include <stdlib.h>
#include <iostream>

#include "ManagerUI.h"
#include "SalesmanUI.h"
#include "BakerUI.h"
#include "CashierUI.h"

using namespace std;

class MainUI
{
    public:
        MainUI();
        virtual ~MainUI();

        void welcom_screen();
        void startUI();
    private:
};

#endif // MAINUI_H

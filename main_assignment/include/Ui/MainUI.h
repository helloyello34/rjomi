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
    /// constructor for mainUI
    MainUI();

    /// Welcom screen for the program
    void welcome_screen();

    /// Login screen
    void startUI();
private:
};

#endif // MAINUI_H

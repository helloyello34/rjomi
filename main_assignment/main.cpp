#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <direct.h>

//#include "MainUI.h"
#include "UI/MainUI.h"

using namespace std;

void init_folder();

int main()
{
    init_folder();
    //system("pause");
    MainUI mainui;
    mainui.startUI();

    return 0;
}


/*
\binaries
\-Menu
\--pizza
\---pizza.dat
\---toppings
\----toppings.dat
\--drinks.dat
\--sides.dat
\-Orders
\--current.dat
\--old.dat
\-Location
\--locations.dat
*/

void init_folder()
{
    mkdir("binaries");
    mkdir("binaries\\Menu");
    mkdir("binaries\\Menu\\toppings");
    mkdir("binaries\\Orders");
    mkdir("binaries\\Location");
}

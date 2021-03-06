#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <direct.h>
#include <string.h>

#include "UI/MainUI.h"


using namespace std;

void init_folder();

int main()
{
    //initializes folders and the UI
    //Entire program is nested within the startUI function
    init_folder();
    MainUI mainui;
    mainui.startUI();

    return 0;
}

//File structure of binaries
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
    //Creates correct folders for binary files
    mkdir("binaries");
    mkdir("binaries\\Menu");
    mkdir("binaries\\Menu\\toppings");
    mkdir("binaries\\Orders");
    mkdir("binaries\\Location");
}

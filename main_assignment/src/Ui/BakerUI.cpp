#include "BakerUI.h"

BakerUI::BakerUI()
{
    startUI();
}

BakerUI::~BakerUI()
{
    //dtor
}

void BakerUI::startUI()
{
    char choice = '\0';
    while(choice != '2') {
    system("CLS");
    cout << "Baker: " << endl;
    cout << " ================================" << endl;
    cout << "  1. Select location   " << endl;
    cout << "  2. Back            " << endl;
    cout << " ================================" << endl;
    cout << " (1-2): ";
    cin >> choice;
    }
    if(choice == 1)
    {
        ///Select Location
    }
    else if (choice == 2)
    {
        ///
    }
}

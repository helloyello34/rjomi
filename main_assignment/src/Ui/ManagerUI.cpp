#include "ManagerUI.h"


ManagerUI::ManagerUI()
{
    startUI();
}

ManagerUI::~ManagerUI()
{
    //dtor
}

void ManagerUI::startUI()
{
    char choice = '\0';
    while(choice != '5') {
        system("CLS");
        cout << "   Manager " << endl;
        cout << " ====================" << endl;
        cout << "  1. Current orders" << endl;
        cout << "  2. Old orders" << endl;
        cout << "  3. Edit menu" << endl;
        cout << "  4. Location" << endl;
        cout << "  5. Back" << endl;
        cout << " ====================" << endl;
        cout << " (1-5): ";

        cin >> choice;

        if(choice == '1'){
            ///Current orders
        } else if(choice == '2') {
            ///Old orders
        } else if(choice == '3') {
            editMenuUI();
        } else if(choice == '4') {
            LocationUI();
        } else if (choice == '7') {
            ToppingUI toppingui;
            toppingui.startUI();
        }
    }
}

void ManagerUI::editMenuUI()
{
    char input;

    while(input != '4')
    {
        system("CLS");
        cout << "   Edit menu" << endl;
        cout << " ====================" << endl;
        cout << "  1. Pizza" << endl;
        cout << "  2. Drinks" << endl;
        cout << "  3. Sides" << endl;
        cout << "  4. Back" << endl;
        cout << " ====================" << endl;
        cout << "  (1-4): ";
        cin >> input;


    if(input == '1'){
        pizza();
    } else if(input == '2') {
        drinks();
    } else if(input == '3') {
        sides();
    } else if (input == '7') {
        ToppingUI toppingui;
        toppingui.startUI();
    }
    }



}

void ManagerUI::pizza()
{
    char input;

    while(input != '6')
    {
        system("CLS");
        cout << "   Pizza " << endl;
        cout << " ====================" << endl;
        cout << "  1. Add Pizza      " << endl;
        cout << "  2. Edit Pizza     " << endl;
        cout << "  3. Delete Pizza   " << endl;
        cout << "  4. View Pizza     " << endl;
        cout << "  5. Toppings       " << endl;
        cout << "  6. Back           " << endl;
        cout << " ====================" << endl;
        cout << " (1-5): ";
        cin >> input;

        if(input == '1'){
            ///Add Pizza
        } else if(input == '2') {
            ///Edit Pizza
        } else if(input == '3') {
            ///Delete Pizza
        } else if(input == '4') {
            ///View Pizza
        } else if(input == '5') {
            ToppingUI toppingui;
            toppingui.startUI();
        }
    }
}

void ManagerUI::drinks()
{
    char input;

    while(input != '5')
    {
        system("CLS");
        cout << "   Drinks " << endl;
        cout << " ====================" << endl;
        cout << "  1. Add Drinks      " << endl;
        cout << "  2. Edit Drinks     " << endl;
        cout << "  3. Delete Drinks   " << endl;
        cout << "  4. View Drinks     " << endl;
        cout << "  5. Back           " << endl;
        cout << " ====================" << endl;
        cout << " (1-5): ";
        cin >> input;

        if(input == '1'){
            ///Add Drinks
        } else if(input == '2') {
            ///Edit Drinks
        } else if(input == '3') {
            ///Delete Drinks
        } else if(input == '4'){
            ///View Drinks
        }
    }
}

void ManagerUI::sides()
{
    char input;

    while(input != '5')
    {
        system("CLS");
        cout << "   Sides " << endl;
        cout << " ====================" << endl;
        cout << "  1. Add Sides      " << endl;
        cout << "  2. Edit Sides     " << endl;
        cout << "  3. Delete Sides   " << endl;
        cout << "  4. View Sides     " << endl;
        cout << "  5. Back           " << endl;
        cout << " ====================" << endl;
        cout << " (1-5): ";
        cin >> input;

        if(input == '1'){
            ///Add Sides
        } else if(input == '2') {
            ///Edit Sides
        } else if(input == '3') {
            ///Delete Sides
        } else if(input == '4'){
            ///View Sides
        }
    }
}

void ManagerUI::LocationUI()
{
    char input;

    while(input != '5')
    {
        system("CLS");
        cout << "   Locations " << endl;
        cout << " ====================" << endl;
        cout << "  1. Add Location   " << endl;
        cout << "  2. Edit Location  " << endl;
        cout << "  3. Delete Location" << endl;
        cout << "  4. View Location  " << endl;
        cout << "  5. Back           " << endl;
        cout << " ====================" << endl;
        cout << " (1-5): ";
        cin >> input;

        if(input == '1'){
            ///Add Location
        } else if(input == '2') {
            ///Edit Location
        } else if(input == '3') {
            ///Delete Location
        } else if(input == '4'){
            ///View Location
        }
    }
}

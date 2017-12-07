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
            system("CLS");
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
        system("CLS");
        drinks();
    } else if(input == '3') {
        system("CLS");
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
        cin.ignore();

        if(input == '1'){
            system("CLS");
            this->drink_service.addDrink();
        } else if(input == '2') {
            system("CLS");
            this->drink_service.edit_drinks();
        } else if(input == '3') {
            system("CLS");
            this->drink_service.delet_drinks();
        } else if(input == '4'){
            system("CLS");
            this->drink_service.list_drinks();
            system("pause");
            system("CLS");
        } else {
            break;
        }
    }
}

void ManagerUI::sides()
{
    char input;

    while(input != '5')
    {

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
            /// Add Side

            system("CLS");
            this->sides_service.addSides();
            system("pause");
            system("CLS");
        } else if(input == '2') {
            /// Edit Side

            system("CLS");
            this->sides_service.edit_sides();
            system("pause");
            system("CLS");
        } else if(input == '3') {
            /// Delete Side

            system("CLS");
            this->sides_service.delete_sides();
            system("pause");
            system("CLS");
        } else if(input == '4'){
            /// List up all sides

            system("CLS");
            this->sides_service.list_sides();
            system("pause");
            system("CLS");
        } else {
            break;
        }
    }
}

void ManagerUI::LocationUI()
{
    char input;

    while(input != '5')
    {

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
            system("CLS");
            location_service.add_location();
            system("pause");
            system("CLS");
        } else if(input == '2') {
            ///Edit Location
        } else if(input == '3') {
            ///Delete Location
        } else if(input == '4'){
            ///View Location
            system("CLS");
            location_service.list_location();
            system("pause");
            system("CLS");
        }
    }
}

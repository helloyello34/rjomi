#include "ManagerUI.h"


ManagerUI::ManagerUI()
{
    startUI();
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
            Location();
        } else if (choice == '7') {

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
        cout << " (1-6): ";
        cin >> input;

        if(input == '1'){
            ///Add Pizza

            system("CLS");
            pizza_ui.add_pizza();
            system("pause");
            system("CLS");

        } else if(input == '2') {
            ///Edit Pizza

            system("CLS");
            pizza_ui.edit_pizza();
            system("pause");
            system("CLS");

        } else if(input == '3') {
            ///Delete Pizza

            system("CLS");
            pizza_ui.delete_pizza();
            system("pause");
            system("CLS");

        } else if(input == '4') {
            ///View Pizza

            system("CLS");
            cout << "   View Pizza" << endl;
            pizza_ui.view_pizza();
            cout << endl << "  ";
            system("pause");
            system("CLS");

        } else if(input == '5') {
            system("CLS");
            toppings();
        }
    }
}

void ManagerUI::toppings()
{
    char input;

    while(input != '5')
    {

        cout << "   Topping " << endl;
        cout << " ====================" << endl;
        cout << "  1. Add Topping    " << endl;
        cout << "  2. Edit Toppings  " << endl;
        cout << "  3. Delete Topping " << endl;
        cout << "  4. View Toppings  " << endl;
        cout << "  5. Back           " << endl;
        cout << " ====================" << endl;
        cout << " (1-5): ";
        cin >> input;

        if(input == '1'){
            ///Add Topping

            system("CLS");
            topping_ui.add_topping();
            system("pause");
            system("CLS");

        } else if(input == '2') {
            ///Edit Topping

            system("CLS");
            topping_ui.edit_topping();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        } else if(input == '3') {
            ///Delete Topping

            system("CLS");
            topping_ui.delete_topping();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        } else if(input == '4') {
            ///View Topping

            system("CLS");
            topping_ui.view_topping();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        } else {
            return;
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
        cout << "  5. Back            " << endl;
        cout << " ====================" << endl;
        cout << " (1-5): ";
        cin >> input;
        cin.ignore();

        if(input == '1'){
            /// Add drink
            system("CLS");
            drink_ui.add_drink();
//            this->drink_service.addDrink();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        } else if(input == '2') {
            /// Edit drink
            system("CLS");
            this->drink_ui.edit_drink();
            system("pause");
            system("CLS");
        } else if(input == '3') {
            /// Delete drink
            system("CLS");
            this->drink_ui.delete_drink();
            system("pause");
            system("CLS");
        } else if(input == '4'){
            /// View drinks
            system("CLS");
            drink_ui.view_drinks();
            cout << endl << "  ";
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
            this->sides_ui.add_sides();
            system("pause");
            system("CLS");
        } else if(input == '2') {
            /// Edit Side

            system("CLS");
            this->sides_ui.edit_sides();
            system("pause");
            system("CLS");
        } else if(input == '3') {
            /// Delete Side

            system("CLS");
            this->sides_ui.delete_sides();
            system("pause");
            system("CLS");
        } else if(input == '4'){
            /// View sides

            system("CLS");
            this->sides_ui.view_sides();
            cout << "  ";
            system("pause");
            system("CLS");
        } else {
            break;
        }
    }
}

void ManagerUI::Location()
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
            location_ui.add_location();
            system("pause");
            system("CLS");
        } else if(input == '2') {
            ///Edit Location
            system("CLS");
            location_ui.edit_location();
            system("pause");
            system("CLS");
        } else if(input == '3') {
            ///Delete Location
            system("CLS");
            location_ui.delete_location();
            system("pause");
            system("CLS");
        } else if(input == '4'){
            ///View Location
            system("CLS");
            location_ui.list_location();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
    }
}



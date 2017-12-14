#include "ManagerUI.h"


ManagerUI::ManagerUI()
{
    startUI();
}

void ManagerUI::startUI()
{
    char choice = '\0';
    while(choice != '4')
    {
        cout << "   Manager " << endl;
        cout << " ====================" << endl;
        cout << "  1. Orders" << endl;
        cout << "  2. Edit menu" << endl;
        cout << "  3. Location" << endl;
        cout << "  4. Back" << endl;
        cout << " ====================" << endl;
        cout << " (1-4): ";

        cin >> choice;

        switch(choice)
        {
        case '1':
            /// Orders
            system("CLS");
            order_ui.managerUI();
            system("CLS");
            break;
        case '2':
            /// Edit menu
            editMenuUI();
            break;
        case '3':
            /// Locations
            system("CLS");
            Location();
            break;
        case '4':
            system("CLS");
            // Return out of the function
            return ;
        default:
            system("CLS");
            cout << "Invalid Input!!" << endl;
            system("pause");
            system("CLS");
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
        // Input the index
        cin >> input;

        switch(input)
        {
        case '1':
            /// add pizza to menu
            system("CLS");
            pizza();
            break;
        case '2':
            /// add drinks to menu
            system("CLS");
            drinks();
            break;
        case '3':
            /// add sides to menu
            system("CLS");
            sides();
            break;
        case '4':
            /// return back to the former function
            system("CLS");
            return;
            break;
        default :
            /// id is not declared
            system("CLS");
            cout << "Invalid input!" << endl;
            system("pause");
            system("CLS");
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

        if(input == '1')
        {
            ///Add Pizza

            system("CLS");
            pizza_ui.add_pizza();
            system("pause");
            system("CLS");

        }
        else if(input == '2')
        {
            ///Edit Pizza

            system("CLS");
            pizza_ui.edit_pizza();
            system("pause");
            system("CLS");

        }
        else if(input == '3')
        {
            ///Delete Pizza

            system("CLS");
            pizza_ui.delete_pizza();
            system("pause");
            system("CLS");

        }
        else if(input == '4')
        {
            ///View Pizza

            system("CLS");
            cout << "   View Pizza" << endl;
            pizza_ui.view_pizza();
            cout << endl << "  ";
            system("pause");
            system("CLS");

        }
        else if(input == '5')
        {
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

        if(input == '1')
        {
            ///Add Topping

            system("CLS");
            topping_ui.add_topping();
            system("pause");
            system("CLS");

        }
        else if(input == '2')
        {
            ///Edit Topping

            system("CLS");
            topping_ui.edit_topping();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else if(input == '3')
        {
            ///Delete Topping

            system("CLS");
            topping_ui.delete_topping();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else if(input == '4')
        {
            ///View Topping

            system("CLS");
            topping_ui.view_topping();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else
        {
            system("CLS");
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

        if(input == '1')
        {
            /// Add drink
            system("CLS");
            drink_ui.add_drink();
//            this->drink_service.addDrink();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else if(input == '2')
        {
            /// Edit drink
            system("CLS");
            this->drink_ui.edit_drink();
            system("pause");
            system("CLS");
        }
        else if(input == '3')
        {
            /// Delete drink
            system("CLS");
            this->drink_ui.delete_drink();
            system("pause");
            system("CLS");
        }
        else if(input == '4')
        {
            /// View drinks
            system("CLS");
            drink_ui.view_drinks();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else
        {
            system("CLS");
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

        if(input == '1')
        {
            /// Add Side

            system("CLS");
            this->sides_ui.add_sides();
            system("pause");
            system("CLS");
        }
        else if(input == '2')
        {
            /// Edit Side

            system("CLS");
            this->sides_ui.edit_sides();
            system("pause");
            system("CLS");
        }
        else if(input == '3')
        {
            /// Delete Side

            system("CLS");
            this->sides_ui.delete_sides();
            system("pause");
            system("CLS");
        }
        else if(input == '4')
        {
            /// View sides

            system("CLS");
            this->sides_ui.view_sides();
            cout << "  ";
            system("pause");
            system("CLS");
        }
        else
        {
            system("CLS");
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

        if(input == '1')
        {
            ///Add Location
            system("CLS");
            location_ui.add_location();
            system("pause");
            system("CLS");
        }
        else if(input == '2')
        {
            ///Edit Location
            system("CLS");
            location_ui.edit_location();
            system("pause");
            system("CLS");
        }
        else if(input == '3')
        {
            ///Delete Location
            system("CLS");
            location_ui.delete_location();
            system("pause");
            system("CLS");
        }
        else if(input == '4')
        {
            ///View Location
            system("CLS");
            location_ui.list_location();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else
        {
            system("CLS");
            return;
        }
    }
}

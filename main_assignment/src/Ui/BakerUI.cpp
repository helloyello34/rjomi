#include "BakerUI.h"

BakerUI::BakerUI()
{
    startUI();
}

void BakerUI::startUI()
{
    if(location_ui.vector_size() == 0)
    {
        cout << "  Contact Manager" << endl;
        cout << endl << "  ";
        system("pause");
        return ;
    }
    // Choose location
    choose_location();
    if(my_location.get_name() != "Nothing")
    {
        char choice = '\0';
        while(choice != '3')
        {
            system("CLS");
            cout << "Baker: " << endl;
            cout << " ================================" << endl;
            cout << "  1. Show orders                 " << endl;
            cout << "  2. change order status         " << endl;
            cout << "  3. Back                        " << endl;
            cout << " ================================" << endl;
            cout << " (1-3): ";
            cin >> choice;
            switch (choice)
            {
            case '1':
                system("CLS");
                order_ui.show_order(my_location);
                cout << endl << "  ";
                system("pause");
                system("CLS");
                break;
            case '2':
                system("CLS");
                order_ui.find_order_status(my_location);
                cout << endl << "  ";
                system("pause");
                system("CLS");
                break;
            case '3':
                system("CLS");
                return ;
            default:
                system("CLS");
                cout << "Invalid input!" << endl;
                cout << endl << "  ";
                system("pause");
                system("CLS");
                break;
            }
        }
    }
}

void BakerUI::choose_location()
{
    // List up avaliable locations
    location_ui.list_location();
    size_t id;
    cout << "  Please choose your location" << endl;
    try
    {
        // Input the index of the location you're at
        cin >> id;
        if(cin.fail())
        {
            cin.clear();
            throw InvalidIdException();
        }
        if(id == 0)
        {
            return ;
        }
        if(id < 1 || id > location_ui.vector_size())
        {
            throw InvalidIdException();
        }
        // Set my location to the chosen location
        this->my_location = location_ui.get_location(id);

    }
    catch(InvalidIdException)
    {
        cout << "  Error: Invalid id" << endl;
    }
}

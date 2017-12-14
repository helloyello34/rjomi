#include "SalesmanUI.h"



SalesmanUI::SalesmanUI()
{
    //startUI();
    try {
    // Choose the location for the salesman
    choose_location();
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Error: Unable to find any locations!" << endl;
    }
//    system("CLS");
//    order_ui.salesmanUI(this->my_location);
}

void SalesmanUI::choose_location()
{
    // List upp all avaliable locations
    location_ui.list_location();
    size_t id;
    cout << "  Please choose your location" << endl;
    cout << "  id: ";
    try {
        // Input the index of the location you are at
        cin >> id;
        // Error check
        if(cin.fail()) {
            cin.clear();
            throw InvalidIdException();
        }
        if(id == 0) {
            return ;
        }
        if(id < 1 || id > location_ui.vector_size()) {
            throw InvalidIdException();
        }
        // Set salseman at the chosen location
        my_location = location_ui.get_location(id);
        system("CLS");
        // Go to orderUI with the location
        order_ui.salesmanUI(this->my_location);

    } catch(InvalidIdException) {
        cout << "  Error: Invalid id" << endl;
    }
}


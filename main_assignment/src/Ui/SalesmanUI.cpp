#include "SalesmanUI.h"



SalesmanUI::SalesmanUI()
{
    //startUI();
    try {
    choose_location();
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Error: Unable to find any locations!" << endl << endl;
        cout << "  ";
    }
//    system("CLS");
//    order_ui.salesmanUI(this->my_location);
}

<<<<<<< HEAD
=======

>>>>>>> 2d08dfb6496790740e32296e3fc8c6bc74b26db2
void SalesmanUI::choose_location()
{
    location_ui.list_location();
    size_t id;
    if(!(my_location.get_name() == "Nothing")) {
        cout << "  Your current location is " << my_location.get_name() << endl;
        cout << "  Press '0' to exit" << endl;
    }
    cout << "  Please choose your location" << endl;
    cout << "  id: ";
    try {
        cin >> id;
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
        my_location = location_ui.get_location(id);
        system("CLS");
        order_ui.salesmanUI(this->my_location);

    } catch(InvalidIdException) {
        cout << "Error: Invalid id" << endl;
    }
}


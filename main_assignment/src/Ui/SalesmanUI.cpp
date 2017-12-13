#include "SalesmanUI.h"



SalesmanUI::SalesmanUI()
{
    //startUI();
    choose_location();
//    system("CLS");
//    order_ui.salesmanUI(this->my_location);
}

<<<<<<< HEAD


=======
>>>>>>> 2d80c80158f73c2b21ec8a497790f8487e5a409b
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


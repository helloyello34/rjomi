#include "CashierUI.h"

CashierUI::CashierUI()
{

    startUI();
}


void CashierUI::startUI()
{
    char choice = '\0';
    while(choice != '3') {
        system("CLS");
        cout << "Cashier: " << endl;
        cout << " --------------------" << endl;
        cout << " 1. choose location  " << endl;
        if(my_location.get_name() != "Nothing") {
        cout << " 2. Charge order     " << endl;
        cout << " 3. Back             " << endl;
        cout << " --------------------" << endl;
        cout << " (1-3): ";
        } else {
        cout << " 2. Back              " << endl;
        cout << " --------------------" << endl;
        cout << " (1-2): ";
        }

        cin >> choice;

        switch(choice) {
        case '1':
            system("CLS");
            choose_location();
            system("pause");
            system("CLS");
            break;
        case '2':
            if(my_location.get_name() != "Nothing"){
            system("CLS");
            status_order();
            system("pause");
            system("CLS");
            } else {
            system("CLS");
            return ;
            }
            break;

        case '3':
            if(my_location.get_name() != "Nothing"){
            return;
            } else {
            cout << "Invalid Input" << endl;
            }
            break;
        default:
            cout << "Invalid Input" << endl;
            break;

        }
    }
}

void CashierUI::choose_location()
{
    location_ui.list_location();
    size_t id;
    if(!(my_location.get_name() == "Nothing")) {
        cout << "Your current location is " << my_location.get_name() << endl;
        cout << "Press '0' to exit" << endl;
    }
    cout << "Please choose your location" << endl;
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

    } catch(InvalidIdException) {
        cout << "Error: Invalid id" << endl;
    }
}

void CashierUI::status_order()
{

}

#include "SalesmanUI.h"



SalesmanUI::SalesmanUI()
{
    //startUI();
    choose_location();
    system("CLS");
    order_ui.salesmanUI(this->my_location);
}

SalesmanUI::~SalesmanUI()
{
    //dtor
}

//void SalesmanUI::startUI()
//{
//
//    char choise = '\0';
//
//    choose_location();
//
//    while(true) {
//    if(this->my_location.get_name() != "Nothing") {
//        while(choise != '3') {
//            system("CLS");
//            cout << "   Salesman: " << endl;
//            cout << " =====================" << endl;
//            cout << "  1. Orders           " << endl;
//            cout << "  2. Comments         " << endl;
//            cout << "  3. Back             " << endl;
//            cout << " =====================" << endl;
//            cout << " (1-4): ";
//            cin >> choise;
//
//            if(choise == '1') {
//                system("CLS");
//                order_ui.salesmanUI(this->my_location);
//        } else if(choise == '2') {
//
//        } else if (choise == '3') {
//            return;
//        }
//
//    }
////    } else {
////    while(choise != '2') {
////        system("CLS");
////        cout << "   Salesman: " << endl;
////        cout << " =====================" << endl;
////        cout << "  1. choose location  " << endl;
////        cout << "  2. Back             " << endl;
////        cout << " =====================" << endl;
////        cout << " (1-4): ";
////        cin >> choise;
////
////        if(choise == '1') {
////            system("CLS");
////            choose_location();
////            break;
////        } else if(choise == '2') {
////            return ;
////        } else {
////            cout << "Invalid input" << endl;
////        }
////
////    }
//    }
//    }
//}

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

    } catch(InvalidIdException) {
        cout << "Error: Invalid id" << endl;
    }
}


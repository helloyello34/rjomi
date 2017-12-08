#include "ToppingUI.h"

ToppingUI::ToppingUI()
{
    this->numberOfToppings = 0;
}




void ToppingUI::add_topping()
{
    Topping newTop;
    try{
    cin.ignore();
    cin >> newTop;
    topping_service.add_topping(newTop);
    } catch (InvalidNameException) {
        cout << "Error: Invalid name" << endl;
    } catch (InvalidPriceException) {
        cout << "Error: Invalid price" << endl;
    } catch (UnableToOpenFileException) {
        cout << "Error: Unable to store the new topping! " << endl;
    }
}

void ToppingUI::delete_topping()
{
    cout << "  Delete toppings" << endl;
    view_topping();
    unsigned int id;
    cout << "  Which topping would you like to delete? " << endl;
    cout << "  Press '0' To exit" << endl;
    cout << "  Id: ";
    try{
    cin >> id;
    if(cin.fail()){
        throw InvalidIdException();
    }
    if(id == 0){
        return;
    }
    if(id > this->toppings.size()){
        throw InvalidIdException();
    }
    this->toppings.erase(this->toppings.begin()+(id-1));
    topping_service.overwrite_topping(this->toppings);


    }
    catch (InvalidIdException){
        cout << "  Error: Invalid id!" << endl;
    }
}

void ToppingUI::view_topping()
{
    fill_topping_vector();
    cout << "   Toppings" << endl;
    cout << "---------------------------" << endl;
    for(size_t i = 0; i < this->toppings.size(); i++) {
        cout << i+1 << ". " << this->toppings[i] << endl;
        cout << "---------------------------" << endl;
    }
}

void ToppingUI::edit_topping()
{
    cout << "  Edit toppings" << endl;
    view_topping();
    unsigned int id;
    cout << "  Which topping would you like to edit? " << endl;
    cout << "  '0' To exit" << endl;
    cout << "  Id: ";
    try{
    cin >> id;
    if(cin.fail()){
        throw InvalidIdException();
    }
    if(id == 0){
        return;
    }
    if(id > this->toppings.size()){
        throw InvalidIdException();
    }
    cin.ignore();
    cin >> this->toppings[id-1];
    topping_service.overwrite_topping(this->toppings);


    }
    catch (InvalidIdException){
        cout << "  Error: Invalid id!" << endl;
    }
    catch (InvalidNameException){
        cout << "  Error: Invalid name" << endl;
    }
    catch (InvalidPriceException){
        cout << "  Error: Invalid price" << endl;
    }
}

void ToppingUI::fill_topping_vector()
{
    this->toppings.clear();
    this->toppings = topping_service.get_topping_vector();
}

Topping ToppingUI::getTopping(size_t id)
{
    fill_topping_vector();
    return this->toppings[id-1];
}

size_t ToppingUI::get_topping_size()
{
    fill_topping_vector();
    return this->toppings.size();
}

//void ToppingUI::retrive_topping()
//{
//    ToppingRepo newVector;
//    this->toppings = newVector.get_toppings();
//}

//Topping ToppingUI::getTopping(int id)
//{
//    if((unsigned)id <= this->toppings.size()) {
//        return this->toppings[id-1];
//    } else {
//        cout << "Invalid choice" << endl;
//        Topping temp;
//        return temp;
//    }
//}
//
////void ToppingUI::list_toppings()
////{
////        system("CLS");
////        retrive_topping();
////        cout << "   Avalable toppings " << endl;
////        cout << " =========================" << endl;
////        for(unsigned int i = 0; i < this->toppings.size(); i++) {
////            cout << "  " << i+1 << ". "<< this->toppings[i] << endl;
////        }
////        cout << " ==========================" << endl << endl;
////}

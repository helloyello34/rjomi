#include "ToppingService.h"

ToppingService::ToppingService()
{
    //ctor
}

void ToppingService::add_topping(Topping& newTop)
{
    topping_repo.store_toppings(newTop);
}

vector<Topping> ToppingService::get_topping_vector()
{
    vector<Topping>temp;
    topping_repo.retreve_toppings(temp);
    return temp;

}

void ToppingService::overwrite_topping(vector<Topping>&topping)
{
    topping_repo.overwrite_toppings(topping);
}



//void ToppingService::list_topping()
//{
//    topping_repo.retreve_toppings(this->toppings);
//    cout << "   Toppings" << endl;
//    cout << "---------------------------" << endl;
//    for(size_t i = 0; i < this->toppings.size(); i++) {
//        cout << i+1 << ". " << this->toppings[i] << endl;
//        cout << "---------------------------" << endl;
//    }
//}

//void ToppingService::edit_topping()
//{
//    cout << "  Edit toppings" << endl;
//    list_topping();
//    unsigned int id;
//    cout << "  Which topping would you like to edit? " << endl;
//    cout << "  '0' To exit" << endl;
//    cout << "  Id: ";
//    try{
//    cin >> id;
//    if(cin.fail()){
//        throw InvalidIdException();
//    }
//    if(id == 0){
//        return;
//    }
//    if(id > this->toppings.size()){
//        throw InvalidIdException();
//    }
//    cin.ignore();
//    cin >> this->toppings[id-1];
//    topping_repo.overwrite_toppings(this->toppings);
//
//
//    }
//    catch (InvalidIdException){
//        cout << "  Error: Invalid id!" << endl;
//    }
//    catch (InvalidNameException){
//        cout << "  Error: Invalid name" << endl;
//    }
//    catch (InvalidPriceException){
//        cout << "  Error: Invalid price" << endl;
//    }
//}
//
//void ToppingService::delete_topping()
//{
//    cout << "  Delete toppings" << endl;
//    list_topping();
//    unsigned int id;
//    cout << "  Which topping would you like to delete? " << endl;
//    cout << "  Press '0' To exit" << endl;
//    cout << "  Id: ";
//    try{
//    cin >> id;
//    if(cin.fail()){
//        throw InvalidIdException();
//    }
//    if(id == 0){
//        return;
//    }
//    if(id > this->toppings.size()){
//        throw InvalidIdException();
//    }
//    this->toppings.erase(this->toppings.begin()+(id-1));
//    topping_repo.overwrite_toppings(this->toppings);
//
//
//    }
//    catch (InvalidIdException){
//        cout << "  Error: Invalid id!" << endl;
//    }
//}
//
////Topping ToppingService::get_topping()
////{
////
////}

#include "DrinkService.h"

DrinkService::DrinkService()
{
    //ctor
}

void DrinkService::addDrink()
{
    Drink newDrink;
    try{
        cin >> newDrink;
        drink_repo.store_drink(newDrink);

    }
    catch(InvalidPriceException){
        cout << "Invalid Price" << endl;
    }
    catch(InvalidNameException){
        cout << "Invalid Name" << endl;
    }
}

void DrinkService::list_drinks()
{
    drink_repo.retreve_drink(this->drinks);
    cout << "   Drinks" << endl;
    cout << " -------------------" << endl;

    for(unsigned int i = 0; i < this->drinks.size(); i++) {
        cout << "  Id: " << i+1 << endl;
        cout << this->drinks[i];
        cout << " -------------------" << endl;
    }
}

void DrinkService::edit_drinks()
{
    cout << "  Edit drinks" << endl;
    list_drinks();
    unsigned int id;
    cout << "  Which drink would you like to edit? " << endl;
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
    if(id > this->drinks.size()){
        throw InvalidIdException();
    }
    cin.ignore();
    cin >> this->drinks[id-1];
    drink_repo.overwrite_drink(this->drinks);


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

void DrinkService::delete_drinks()
{
    cout << "  Delete drinks" << endl;
    list_drinks();
    unsigned int id;
    cout << "  Which drink would you like to delete? " << endl;
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
    if(id > this->drinks.size()){
        throw InvalidIdException();
    }
    this->drinks.erase(this->drinks.begin()+(id-1));
    drink_repo.overwrite_drink(this->drinks);


    }
    catch (InvalidIdException){
        cout << "  Error: Invalid id!" << endl;
    }
}

Drink DrinkService::get_drink()
{
    cout << "   Add drink" << endl;
    list_drinks();
    unsigned int id;
    try{
    cin >> id;
    if(cin.fail()){
        throw InvalidIdException();
    }
    if(id == 0){
        Drink temp;
        return temp;
    }
    if(id > this->drinks.size()){
        throw InvalidIdException();
    }
    return this->drinks[id-1];
    }
    catch (InvalidIdException){
        cout << "Invalid Id";
        Drink temp;
        return temp;
    }


}

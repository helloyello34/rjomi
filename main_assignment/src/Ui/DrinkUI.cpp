#include "DrinkUI.h"

DrinkUI::DrinkUI()
{
    //ctor
}

void DrinkUI::add_drink()
{
    Drink newDrink;
    try {
        cout << "   Add Drink" << endl;
        cout << " =====================" << endl;
        cin >> newDrink;
        drink_service.add_drink(newDrink);
    } catch (InvalidNameException) {
        cout << "Error: Invalid name!" << endl;
    } catch (InvalidPriceException) {
        cout << "Error: Invalid price!" << endl;
    } catch (UnableToOpenFileException) {
        cout << "Unable to successfully add drink" << endl;
    }
}

void DrinkUI::delete_drink()
{
    view_drinks();
    cout << "  Delete drinks" << endl;

    unsigned int id;
    cout << "  Which drink would you like to delete? " << endl;
    cout << "  Press '0' To exit" << endl;
    cout << "  Id: ";
    try{
    cin >> id;
    if(cin.fail()){
        cin.clear();
        throw InvalidIdException();
    }
    if(id == 0){
        return;
    }
    if(id > this->drinks.size()){
        throw InvalidIdException();
    }
    this->drinks.erase(this->drinks.begin()+(id-1));
    drink_service.overwrtie_drinks(this->drinks);
    system("CLS");
    cout << "  Drink succsessflully deleted" << endl << endl << "  ";
    }
    catch (InvalidIdException){
        cout << "  Error: Invalid id!" << endl;
    }

}

void DrinkUI::edit_drink()
{
    cout << "  Edit drinks" << endl;
    cout << " =======================" << endl;
    view_drinks();
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
    drink_service.overwrtie_drinks(this->drinks);


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

void DrinkUI::view_drinks()
{
    try {
        this->drinks.clear();
        this->drinks = drink_service.get_drinks_vector();
        cout << "    Drinks" << endl;
        cout << "  -------------------" << endl;
        for(unsigned int i = 0; i < this->drinks.size(); i++) {
            cout << "   Id: " << i+1 << endl;
            cout << this->drinks[i];
            cout << "  -------------------" << endl;
        }
    } catch(UnableToOpenFileException) {
        cout << "Error: could not open file! " << endl;
    }
}

Drink DrinkUI::get_drink(size_t id)
{
    this->drinks.clear();
    this->drinks = drink_service.get_drinks_vector();
    return this->drinks[id-1];
}

size_t DrinkUI::get_vector_size()
{
    this->drinks.clear();
    this->drinks = drink_service.get_drinks_vector();
    return this->drinks.size();
}

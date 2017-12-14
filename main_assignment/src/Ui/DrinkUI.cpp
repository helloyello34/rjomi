#include "DrinkUI.h"

DrinkUI::DrinkUI()
{
    //ctor
}

void DrinkUI::add_drink()
{
    // Construct a new drink
    Drink newDrink;
    try {
        cout << "   Add Drink" << endl;
        cout << " =====================" << endl;
        // Input into the new drink
        cin >> newDrink;
        // Send the new drink to be stored
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
    // View all avaliable drinks
    view_drinks();
    cout << "  Delete drinks" << endl;

    unsigned int id;
    cout << "  Which drink would you like to delete? " << endl;
    cout << "  Press '0' To exit" << endl;
    cout << "  Id: ";
    try{
    // Input the index of the drink to be deleted
    cin >> id;
    // Error check
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
    // Deletes the drink at the said index
    this->drinks.erase(this->drinks.begin()+(id-1));
    // Send the vector to the Service class to overwrite the data
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
    // View avaliable drinks
    view_drinks();
    unsigned int id;
    cout << "  Which drink would you like to edit? " << endl;
    cout << "  '0' To exit" << endl;
    cout << "  Id: ";
    try{
    // Input the index of the drink to be changed
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
    // Write into the drink at said index
    cin >> this->drinks[id-1];
    // Sends the vector to Service class to overwrite the data
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
    // Returns the drink at the index id
    this->drinks.clear();
    this->drinks = drink_service.get_drinks_vector();
    return this->drinks[id-1];
}

size_t DrinkUI::get_vector_size()
{
    // Return the number of drinks in the vector
    this->drinks.clear();
    this->drinks = drink_service.get_drinks_vector();
    return this->drinks.size();
}

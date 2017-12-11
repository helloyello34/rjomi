#include "SidesUI.h"

SidesUI::SidesUI()
{
    //ctor
}

void SidesUI::add_sides()
{
    Sides newSide;
    try{
    cin.ignore();
    cout << "   Add Sides" << endl;
    cout << " ===================" << endl;
    cin >> newSide;
    this->sides_service.add_sides(newSide);
    cout << " ===================" << endl << endl << "  ";
    }
    catch(InvalidNameException){
        cout << "Error: Invalid name" << endl;
    }
    catch(InvalidPriceException){
        cout << "Error: Invalid price" << endl;
    }
    catch (UnableToOpenFileException) {
        cout << "Error: Could not open file!" << endl;
    }
}

void SidesUI::edit_sides()
{

    cout << "   Edit sides" << endl;
    cout << " ===================" << endl;
    view_sides();
    unsigned int id;
    cout << "  Which drink would you like to edit? " << endl;
    cout << "  '0' To exit" << endl;
    cout << "  Id: ";

    try{
    cin >> id;
    system("CLS");
    if(cin.fail()){
        throw InvalidIdException();
    }
    if(id == 0){
        return;
    }
    if(id > this->sides.size()){
        throw InvalidIdException();
    }
    cin.ignore();
    cout << "   Edit Sides" << endl;
    cout << " ==================" << endl;
    cin >> this->sides[id-1];
    cout << " ==================" << endl << endl << "  ";
    sides_service.overwrite_sides(sides);
    }
    catch(InvalidIdException){
        cout << "Error: Invalid id" << endl;
    }
    catch (InvalidNameException){
        cout << "  Error: Invalid name" << endl;
    }
    catch (InvalidPriceException){
        cout << "  Error: Invalid price" << endl;
    }

}

void SidesUI::delete_sides()
{
    cout << "   Delete sides" << endl;
    cout << " =====================" << endl;
    view_sides();
    unsigned int id;
    cout << "  Which drink would you like to delete? " << endl;
    cout << "  '0' To exit" << endl;
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
    if(id > this->sides.size()){
        throw InvalidIdException();
    }
    cin.ignore();
    this->sides.erase(this->sides.begin()+(id-1));
    sides_service.overwrite_sides(sides);
    system("CLS");
    cout << "  Side successfully deleted" << endl;
    cout << endl << "  ";
    }
    catch(InvalidIdException){
        cout << "Error: Invalid id" << endl;
    }
    catch (InvalidNameException){
        cout << "  Error: Invalid name" << endl;
    }
    catch (InvalidPriceException){
        cout << "  Error: Invalid price" << endl;
    }
}

void SidesUI::view_sides()
{
    this->sides.clear();
    this->sides = sides_service.get_sides_vector();

    cout << "    Sides" << endl;
    cout << "  -------------------" << endl;
    for (size_t i = 0; i < this->sides.size(); i++) {
        cout << "   Id: " << i+1 << endl;
        cout << this->sides[i];
        cout << "  -------------------" << endl;
    }

}

Sides SidesUI::get_side(size_t id)
{
    this->sides = sides_service.get_sides_vector();
    return this->sides[id-1];
}

size_t SidesUI::get_vector_size()
{
    this->sides = sides_service.get_sides_vector();
    return this->sides.size();
}

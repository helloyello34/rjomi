#include "SidesService.h"

SidesService::SidesService()
{
    //ctor
}


void SidesService::addSides()
{
    Sides newSide;
    try{
    cin.ignore();
    cin >> newSide;
    this->sides_repo.store_side(newSide);
    }
    catch(InvalidNameException){
        cout << "Error: Invalid name" << endl;
    }
    catch(InvalidPriceException){
        cout << "Error: Invalid price" << endl;
    }
}

void SidesService::list_sides()
{
    sides_repo.read_side(this->sides);

    cout << "   Sides" << endl;
    cout << " -------------------" << endl;
    for (unsigned int i = 0; i < this->sides.size(); i++) {
        cout << "Id: " << i+1 << endl;
        cout << this->sides[i];
        cout << " -------------------" << endl;
    }
    cout << endl;
}

void SidesService::edit_sides()
{
    cout << "   Edit sides" << endl;
    list_sides();
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
    if(id > this->sides.size()){
        throw InvalidIdException();
    }
    cin.ignore();
    cin >> this->sides[id-1];
    sides_repo.overwrite_sides(sides);
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

void SidesService::delete_sides()
{
    cout << "   Delete sides" << endl;
    list_sides();
    unsigned int id;
    cout << "  Which drink would you like to delete? " << endl;
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
    if(id > this->sides.size()){
        throw InvalidIdException();
    }
    cin.ignore();
    this->sides.erase(this->sides.begin()+(id-1));
    sides_repo.overwrite_sides(sides);
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

Sides SidesService::get_sides()
{
    Sides temp;

    return temp;
}


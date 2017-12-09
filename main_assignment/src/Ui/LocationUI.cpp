#include "LocationUI.h"

LocationUI::LocationUI()
{
    //ctor
}

void LocationUI::add_location()
{
    Location newLocation;
    try{
        cin.ignore();
        cin >> newLocation;
        location_service.store_location(newLocation);
        cout << " Location stored successfully" << endl;
    }
    catch(InvalidNameException) {
        cout << " Error: Invalid Name !" << endl;
    }
    catch(UnableToOpenFileException) {
        cout << " Error: Could not store data!" << endl;
    }
}

void LocationUI::list_location()
{
    fill_vector();
    cout << "   Locations" << endl;
    cout << "-----------------------------" << endl;
    for(size_t i = 0; i < this->locations.size(); i++) {
        cout << " " << i+1 << ". " << this->locations[i] << endl;
        cout << "-----------------------------" << endl;
    }
}

void LocationUI::edit_location()
{
    list_location();
    unsigned int id;
    cout << "  Edit location" << endl;
    cout << " ------------------------------------------" << endl;
    cout << "  Whitch location would you like to edit? " << endl;
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
        if(id > this->locations.size() || id < 0){
            throw InvalidIdException();
        }
        cin.ignore();
        cin >> locations[id-1];

        location_service.overwrite_locations(this->locations);
        cout << "Location Edited successfully" << endl;
    }
    catch(InvalidIdException) {
        cout << "Error: Invalid id! " << endl;
    }
    catch(InvalidNameException) {
        cout << "Error: Invalid name" << endl;
    }
    catch(UnableToOpenFileException) {
        cout << "Error: Unable to edit location!" << endl;
    }
}


void LocationUI::delete_location()
{
    list_location();
    unsigned int id;
    cout << "  Delete location" << endl;
    cout << "------------------------------------------" << endl;
    cout << "  Whitch location would you like to delete? " << endl;
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
        if(id > this->locations.size() || id < 0){
            throw InvalidIdException();
        }
        locations.erase(locations.begin() + (id-1));

        location_service.overwrite_locations(this->locations);
        cout << "Location Deleted successfully" << endl;
    }
    catch(InvalidIdException) {
        cout << "Error: Invalid id! " << endl;
    }
    catch(UnableToOpenFileException) {
        cout << "Error: Unable to edit location!" << endl;
    }
}

void LocationUI::fill_vector()
{
    this->locations.clear();
    this->location_service.retreve_locations(this->locations);
}

size_t LocationUI::vector_size()
{
    fill_vector();
    return this->locations.size();
}

Location LocationUI::get_location(size_t id)
{
    fill_vector();
    return this->locations[id-1];
}

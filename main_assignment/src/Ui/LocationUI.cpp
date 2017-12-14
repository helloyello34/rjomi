#include "LocationUI.h"

LocationUI::LocationUI()
{
    //ctor
}

void LocationUI::add_location()
{
    // Construct a new location
    Location newLocation;
    try{
        cin.ignore();
        cout << "   Add Location" << endl;
        cout << " ========================" << endl;
        // Write into the location
        cin >> newLocation;
        cout << " ========================" << endl;
        // Send the new location to be stored in file
        location_service.store_location(newLocation);
        cout << endl << "  ";
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
    // Fill the vector to be listed
    fill_vector();
    cout << "    Locations" << endl;
    cout << "  -----------------------------" << endl;
    for(size_t i = 0; i < this->locations.size(); i++) {
        // Print out the location in the list
        cout << "   " << i+1 << ". " << this->locations[i] << endl;
        cout << "  -----------------------------" << endl;
    }
}

void LocationUI::edit_location()
{
    cout << "   Edit location" << endl;
    cout << " ===================================" << endl;
    // List up the avaliable locations
    list_location();
    cout << " ===================================" << endl;
    unsigned int id;
    cout << "  Whitch location would you like to edit? " << endl;
    cout << "  Press '0' To exit" << endl;
    cout << "  Id: ";
    try{
        // Input the index of the location to be changed
        cin >> id;
        system("CLS");

        // Error check
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
        cout << "   Edit Location" << endl;
        cout << " =========================" << endl;
        // Input into the lcoation at said index
        cin >> locations[id-1];
        cout << " =========================" << endl;
        cout << endl << "  ";
        // Send the changed location vector to be stored
        location_service.overwrite_locations(this->locations);
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
    // List up the avaliable locations
    list_location();
    unsigned int id;
    cout << "   Delete location" << endl;
    cout << " ===============================================" << endl;
    cout << "  Whitch location would you like to delete? " << endl;
    cout << "  Press '0' To exit" << endl;
    cout << "  Id: ";
    try{
        // Input the index of location to be deleted
        cin >> id;
        system("CLS");

        // Error check
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
        // Delete the location at the index inputed
        locations.erase(locations.begin() + (id-1));

        // Send the changed list to the Service to be stored
        location_service.overwrite_locations(this->locations);
        cout << "  Location Deleted successfully" << endl << endl << "  ";
    }
    catch(InvalidIdException) {
        cout << "  Error: Invalid id! " << endl;
    }
    catch(UnableToOpenFileException) {
        cout << "  Error: Unable to edit location!" << endl;
    }
}

void LocationUI::fill_vector()
{
    // Fill up the locations
    this->locations.clear();
    this->location_service.retreve_locations(this->locations);
}

size_t LocationUI::vector_size()
{
    // Return the number of locations
    fill_vector();
    return this->locations.size();
}

Location LocationUI::get_location(size_t id)
{
    // Return said location
    fill_vector();
    return this->locations[id-1];
}

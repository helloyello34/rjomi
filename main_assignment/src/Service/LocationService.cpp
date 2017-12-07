#include "LocationService.h"

LocationService::LocationService()
{
    //ctor
}

void LocationService::add_location()
{
    Location newLocation;
    try{
        cin.ignore();
        cin >> newLocation;
        location_repo.store_location(newLocation);
        cout << " Locatoin stored successfully" << endl;
    }
    catch(InvalidNameException) {
        cout << " Error: Invalid Name !" << endl;
    }
    catch(UnableToOpenFileException) {
        cout << " Error: Could not store data!" << endl;
    }
}

void LocationService::list_location()
{
    location_repo.retreve_locations(this->locations);
    cout << "   Locations" << endl;
    cout << "-----------------------------" << endl;
    for(size_t i = 0; i < this->locations.size(); i++) {
        cout << " " << i+1 << ". " << this->locations[i] << endl;
        cout << "-----------------------------" << endl;
    }
}

void LocationService::edit_location()
{

}

void LocationService::delet_location()
{

}

//Location LocationService::get_location()
//{
//
//}

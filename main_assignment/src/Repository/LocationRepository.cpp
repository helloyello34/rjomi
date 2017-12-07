#include "LocationRepository.h"

LocationRepository::LocationRepository()
{
    //ctor
}

void LocationRepository::store_location(Location& location)
{
    ofstream file;
    file.open("binaries\\Location\\locations.dat", ios::binary | ios::app);

    if(file.is_open()) {
        location.write(file);
        file.close();
    } else {
        throw UnableToOpenFileException();
    }
}

void LocationRepository::retreve_locations(vector<Location>&locations)
{
    ifstream file;
    file.open("binaries\\Location\\locations.dat", ios::binary);

    if(file.is_open()) {
        Location temp;
        locations.clear();
        while(!(file.eof())) {
            temp.read(file);
            locations.push_back(temp);
        }
        locations.pop_back();
        file.close();
    } else {
        throw UnableToOpenFileException();
    }

}

void LocationRepository::overwrite_locations(vector<Location>&locations)
{
    ofstream file;
    file.open("binaries\\Location\\locations.dat", ios::binary);

    if(file.is_open()) {

        for(size_t i = 0; i < locations.size(); i++) {
            locations[i].write(file);
        }

        file.close();
    } else {
        throw UnableToOpenFileException();
    }
}

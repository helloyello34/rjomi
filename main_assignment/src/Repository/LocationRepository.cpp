#include "LocationRepository.h"

LocationRepository::LocationRepository()
{
    //ctor
}

void LocationRepository::store_location(Location& location)
{
    // Make ofstream to write to location data file
    ofstream file;
    file.open("binaries\\Location\\locations.dat", ios::binary | ios::app);

    // Checks if the file is open
    if(file.is_open())
    {
        // Writes the locatio to the file
        location.write(file);

        // Close file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void LocationRepository::retreve_locations(vector<Location>&locations)
{
    // Make ifstream to read from location data file
    ifstream file;
    file.open("binaries\\Location\\locations.dat", ios::binary);

    // Checks if the file is open
    if(file.is_open())
    {
        // Creates a temp location
        Location temp;

        // Clears the vector
        locations.clear();

        while(!(file.eof()))
        {
            // Read temp location from file
            temp.read(file);

            // Sets the location to vector
            locations.push_back(temp);
        }
        // Deletes the last instance of location
        locations.pop_back();

        // Close file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }

}

void LocationRepository::overwrite_locations(vector<Location>&locations)
{
    // Make ofstream to write to location data file
    ofstream file;
    file.open("binaries\\Location\\locations.dat", ios::binary);

    // Checks if the file is open
    if(file.is_open())
    {

        for(size_t i = 0; i < locations.size(); i++)
        {
            // Writes the location to the file
            locations[i].write(file);
        }

        // Close file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

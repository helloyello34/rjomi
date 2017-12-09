#ifndef LOCATIONSERVICE_H
#define LOCATIONSERVICE_H


/// Including Model classes
#include "Location.h"

/// Including Repository classes
#include "LocationRepository.h"


class LocationService
{
    public:
        /// Cunstructor for LocationService
        LocationService();

        /// Function to store location to file
        void store_location(Location& location);

        /// Function to retreve the locations to a vector
        void retreve_locations(vector<Location>&locations);

        ///Function to overwrite, edit or delete from the file
        void overwrite_locations(vector<Location>&locations);

    private:
        LocationRepository location_repo;

};

#endif // LOCATIONSERVICE_H

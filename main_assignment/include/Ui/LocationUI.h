#ifndef LOCATIONUI_H
#define LOCATIONUI_H


/// Including Model classes
#include "Location.h"

/// Including Service classes
#include "LocationService.h"

#include <stdlib.h>

class LocationUI
{
    public:
        LocationUI();

        /// Add new location to file
        void add_location();

        /// View all avaliable locations
        void list_location();

        /// Edit any avaliable locations
        void edit_location();

        /// Delete any avaliable locations
        void delete_location();

        /// read all data from file to vector
        void fill_vector();

        /// Returns the number of locations in the file
        size_t vector_size();

        /// Return spesific location
        Location get_location(size_t id);
    private:
        LocationService location_service;
        vector<Location>locations;
};

#endif // LOCATIONUI_H

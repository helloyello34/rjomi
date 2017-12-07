#ifndef LOCATIONSERVICE_H
#define LOCATIONSERVICE_H

#include "LocationRepository.h"
#include "Location.h"

class LocationService
{
    public:
        LocationService();
        void add_location();
        void list_location();
        void edit_location();
        void delete_location();
        Location get_location();

    private:
        vector<Location>locations;
        LocationRepository location_repo;

};

#endif // LOCATIONSERVICE_H

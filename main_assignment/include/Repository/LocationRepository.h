#ifndef LOCATIONREPOSITORY_H
#define LOCATIONREPOSITORY_H

#include <vector>

#include "Location.h"

#include "UnableToOpenFileException.h"

class LocationRepository
{
    public:
        LocationRepository();
        void store_location(Location& location);
        void retreve_locations(vector<Location>&locations);
        void overwrite_locations(vector<Location>&locations);
    private:
};

#endif // LOCATIONREPOSITORY_H

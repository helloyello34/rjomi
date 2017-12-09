#ifndef LOCATIONREPOSITORY_H
#define LOCATIONREPOSITORY_H

/// Invluding inbuilt classes
#include <vector>

/// Including Model classes
#include "Location.h"

/// Invludeing Exception classes
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

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
        /// Location Repository cunstroctor
        LocationRepository();

        /// Store location to location file
        void store_location(Location& location);

        /// reads to locations from location file
        void retreve_locations(vector<Location>&locations);

        /// Writes over data from location file
        void overwrite_locations(vector<Location>&locations);
    private:
};

#endif // LOCATIONREPOSITORY_H

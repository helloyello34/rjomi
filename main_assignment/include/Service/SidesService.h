#ifndef SIDESSERVICE_H
#define SIDESSERVICE_H


#include <vector>

#include "Sides.h"
#include "SidesRepository.h"

#include "InvalidIdException.h"

using namespace std;

class SidesService
{
    public:
        SidesService();

        void add_sides(Sides& newSide);
        void delete_sides(vector<Sides>&sides);
        void overwrite_sides(vector<Sides>&sides);
        vector<Sides> get_sides_vector();

        Sides get_sides();

    private:
        SidesRepository sides_repo;
};

#endif // SIDESSERVICE_H

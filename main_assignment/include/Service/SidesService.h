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
        void addSides();
        void list_sides();
        void edit_sides();
        void delete_sides();
        Sides get_sides();

    private:
        vector<Sides>sides;
        SidesRepository sides_repo;
};

#endif // SIDESSERVICE_H

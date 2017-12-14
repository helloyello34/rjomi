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
    /// Constructor for Side Service
    SidesService();

    /// Send a side dish to the Repository
    void add_sides(Sides& newSide);

    /// Sends vector to Repository and overwrites the data in file
    void overwrite_sides(vector<Sides>&sides);

    /// Reads data from Repository and fills the vector
    vector<Sides> get_sides_vector();


private:
    SidesRepository sides_repo;
};

#endif // SIDESSERVICE_H

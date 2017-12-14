#ifndef SIDESREPOSITORY_H
#define SIDESREPOSITORY_H

#include "Sides.h"
#include "UnableToOpenFileException.h"

#include <vector>

using namespace std;

class SidesRepository
{
public:

    /// Side dish Repository constructor
    SidesRepository();

    /// Store side to file
    void store_side(Sides& side);

    /// reads from file to sides
    void read_side(vector<Sides>&sides);

    /// writes over former data from sides
    void overwrite_sides(vector<Sides>&sides);
private:
};

#endif // SIDESREPOSITORY_H

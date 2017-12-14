#include "SidesService.h"

SidesService::SidesService()
{
    //ctor
}

void SidesService::add_sides(Sides& newSide)
{
    // Call to repository class to store the new side dish
    sides_repo.store_side(newSide);
}

vector<Sides> SidesService::get_sides_vector()
{
    // Call to repository class to read the data to vectro
    vector<Sides>temp;
    sides_repo.read_side(temp);
    return temp;
}

void SidesService::overwrite_sides(vector<Sides>&sides)
{
    // Call to the repository class to write over existing data
    sides_repo.overwrite_sides(sides);
}

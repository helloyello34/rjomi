#include "SidesService.h"

SidesService::SidesService()
{
    //ctor
}

void SidesService::add_sides(Sides& newSide)
{
    sides_repo.store_side(newSide);
}

vector<Sides> SidesService::get_sides_vector()
{
    vector<Sides>temp;
    sides_repo.read_side(temp);
    return temp;
}

void SidesService::overwrite_sides(vector<Sides>&sides)
{
    sides_repo.overwrite_sides(sides);
}

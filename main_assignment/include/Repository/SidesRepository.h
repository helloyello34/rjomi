#ifndef SIDESREPOSITORY_H
#define SIDESREPOSITORY_H

#include "Sides.h"

#include <vector>

using namespace std;

class SidesRepository
{
    public:
        SidesRepository();
        void store_side(Sides& side);
        void read_side(vector<Sides>&sides);
        void overwrite_sides(vector<Sides>&sides);
    private:
};

#endif // SIDESREPOSITORY_H

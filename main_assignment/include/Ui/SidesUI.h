#ifndef SIDESUI_H
#define SIDESUI_H

#include "Sides.h"
#include "SidesService.h"

class SidesUI
{
    public:
        SidesUI();

        void add_sides();
        void edit_sides();
        void delete_sides();
        void view_sides();

    private:
        vector<Sides>sides;
        SidesService sides_service;
};

#endif // SIDESUI_H

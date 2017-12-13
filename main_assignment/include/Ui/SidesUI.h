#ifndef SIDESUI_H
#define SIDESUI_H

#include "Sides.h"
#include "SidesService.h"

#include <stdlib.h>

class SidesUI
{
    public:
        SidesUI();

        //////////////////////////////////
        /// Add side dish to the menu
        void add_sides();

        /// Edit/Change side dish on the menu
        void edit_sides();

        /// Delete side dish of the menu
        void delete_sides();

        /// View avaliable side dishes on the menu
        void view_sides();
        //////////////////////////////////

        //////////////////////////////////
        /// Returns a specific side dish
        Sides get_side(size_t id);

        /// Returns the number of side dishes avaliable
        size_t get_vector_size();
        //////////////////////////////////

    private:
        vector<Sides>sides;
        SidesService sides_service;
};

#endif // SIDESUI_H

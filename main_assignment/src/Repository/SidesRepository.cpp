#include "SidesRepository.h"

SidesRepository::SidesRepository()
{
    //ctor
}

void SidesRepository::store_side(Sides& side)
{
    // Makes ofstream file to write data to sides data file
    ofstream file;
    file.open("binaries\\Menu\\sides.dat", ios::binary|ios::app);

    // Checks if the file is open
    if(file.is_open())
    {
        // Write the new side dish to the file
        side.write(file);

        // Close the file
        file.close();

    }
    else
    {
        cout << "File could not open !" << endl;
    }
}

void SidesRepository::read_side(vector<Sides>&sides)
{
    // Makes ifstream file to read data from sides data file
    ifstream file;
    file.open("binaries\\Menu\\sides.dat", ios::binary);

    // Checks if the file is open
    if(file.is_open())
    {
        // Makes a temp side dish
        Sides temp;

        // Clears the vector
        sides.clear();

        while(!(file.eof()))
        {
            // Read data to the temp side dish
            temp.read(file);

            // Puts the temp side dish to the vector
            sides.push_back(temp);
        }

        // Deletes the last side dish in the vector
        sides.pop_back();

        // Close the file
        file.close();

    }
    else
    {
        throw UnableToOpenFileException();
    }

}

void SidesRepository::overwrite_sides(vector<Sides>&sides)
{
    // Makes ofstream file to write data to sides data file
    ofstream file;
    file.open("binaries\\Menu\\sides.dat", ios::binary);

    // Checks if the file is open
    if(file.is_open())
    {

        for(unsigned int i = 0; i < sides.size(); i++)
        {
            // writes the side dish to the file
            sides[i].write(file);
        }

        // Close file
        file.close();

    }
    else
    {
        cout << "File could not open !" << endl;
    }
}

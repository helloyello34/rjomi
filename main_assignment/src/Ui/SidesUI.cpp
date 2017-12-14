#include "SidesUI.h"

SidesUI::SidesUI()
{
    //ctor
}

/// Add side dish to the menu
void SidesUI::add_sides()
{
    // Construct an instance of a side dish
    Sides newSide;
    try{
    cin.ignore();
    cout << "   Add Sides" << endl;
    cout << " ===================" << endl;
    // Write into the new side dish
    cin >> newSide;
    // Send the side dish to the Service class
    this->sides_service.add_sides(newSide);
    cout << " ===================" << endl << endl << "  ";
    }
    catch(InvalidNameException){
        cout << "Error: Invalid name" << endl;
    }
    catch(InvalidPriceException){
        cout << "Error: Invalid price" << endl;
    }
    catch (UnableToOpenFileException) {
        cout << "Error: Could not open file!" << endl;
    }
}

/// Edit/Change side dish on the menu
void SidesUI::edit_sides()
{
    try {
    // Clear everything in the vector
    this->sides.clear();
    // Read data from file to the vector
    this->sides = this->sides_service.get_sides_vector();
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Unable to open file!" << endl;
        cout << "  ";
        return;
    }
    cout << "   Edit sides" << endl;
    cout << " ===================" << endl;
    // View all avaliable side dishes
    view_sides();
    unsigned int id;
    cout << "  Which drink would you like to edit? " << endl;
    cout << "  '0' To exit" << endl;
    cout << "  Id: ";

    try{
    // Input the index of the side dish to be changed
    cin >> id;
    system("CLS");
    // Error check
    if(cin.fail()){
        throw InvalidIdException();
    }
    if(id == 0){
        return;
    }
    if(id > this->sides.size()){
        throw InvalidIdException();
    }
    cin.ignore();
    cout << "   Edit Sides" << endl;
    cout << " ==================" << endl;
    // Writing into the side dish at the index
    cin >> this->sides[id-1];
    cout << " ==================" << endl << endl << "  ";
    // Overwrite the data on the file
    sides_service.overwrite_sides(sides);
    }
    catch(InvalidIdException){
        cout << "Error: Invalid id" << endl;
    }
    catch (InvalidNameException){
        cout << "  Error: Invalid name" << endl;
    }
    catch (InvalidPriceException){
        cout << "  Error: Invalid price" << endl;
    }

}

void SidesUI::delete_sides()
{
    cout << "   Delete sides" << endl;
    cout << " =====================" << endl;
    // View all avaliable side dishes
    view_sides();
    unsigned int id;
    cout << "  Which drink would you like to delete? " << endl;
    cout << "  '0' To exit" << endl;
    cout << "  Id: ";

    try{
    // Input the index of the side dish to be deleted
    cin >> id;
    // Error check
    if(cin.fail()){
        cin.clear();
        throw InvalidIdException();
    }
    if(id == 0){
        return;
    }
    if(id > this->sides.size()){
        throw InvalidIdException();
    }
    cin.ignore();
    // Delete the side dish at the index id
    this->sides.erase(this->sides.begin()+(id-1));
    // Overwrite the data on the file
    sides_service.overwrite_sides(sides);
    system("CLS");
    cout << "  Side successfully deleted" << endl;
    cout << endl << "  ";
    }
    catch(InvalidIdException){
        cout << "Error: Invalid id" << endl;
    }
    catch (InvalidNameException){
        cout << "  Error: Invalid name" << endl;
    }
    catch (InvalidPriceException){
        cout << "  Error: Invalid price" << endl;
    }
}

void SidesUI::view_sides()
{
    try {
    // Clear the data on the vector
    this->sides.clear();
    // Read the data from
    this->sides = sides_service.get_sides_vector();

    cout << "    Sides" << endl;
    cout << "  -------------------" << endl;
    for (size_t i = 0; i < this->sides.size(); i++) {
        cout << "   Id: " << i+1 << endl;
        // print out the side dish at index i
        cout << this->sides[i];
        cout << "  -------------------" << endl;
    }
    }
    catch (UnableToOpenFileException)
    {
        cout << "Error: Unable to open file!" << endl;
    }
}

Sides SidesUI::get_side(size_t id)
{
    // Read data from file to the vector
    this->sides = sides_service.get_sides_vector();
    // Return the side dish at index id
    return this->sides[id-1];
}

size_t SidesUI::get_vector_size()
{
    try{
    // Read data from file to the vector
    this->sides = sides_service.get_sides_vector();
    // Return the number of side dishes
    return this->sides.size();
    }
    catch (UnableToOpenFileException)
    {
        cout << "Error: Unable to open file!" << endl;
    }
    return 0;
}

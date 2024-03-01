/*
Author:  Suraj Hamal
Date:    02/24/2024
Course:  CS Programming 210
Company: Chada Tech
Purpose: To read, write, and count the grocery items purchased from a file.
*/

// Including the libraries needed for the program
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Declaring the variables needed for the program 
map<string, int> freq;      // Creating a map container to store the values 
ifstream inFS;              // Declaring ifstream variable to read from file 
ofstream outFS;             // Declaring ofstream variable to write to file 
string item;


//**********************************FUNCTIONS*****************************************************************
//************************************************************************************************************

// Function with while loop and if condition to read the contents of file and store it into the map container 
// Exception handler if the file didnot reach the end of line or in stream fail.  
void ReadFromFile() {

    inFS >> item;
    while (!inFS.fail()) {

        if (freq.count(item)) {
            freq[item]++;
        }
        else {
            freq.emplace(item, 1);
        }
        inFS >> item;
    }
    if (!inFS.eof()) {
        throw runtime_error("Input failure before reaching end of file.");
    }

    inFS.close();
}
//------------------------------------------------------------------------------------------------------------

//Function to write to into new file from map container.
void WriteToFile() {

    for (auto i = freq.begin(); i != freq.end(); i++) {
        outFS << i->first << " " << i->second << endl;
    }
    if (outFS.fail()) {
        throw runtime_error("Couldnot write to the file. Opertion failed.");
    }

    outFS.close();
}
//-----------------------------------------------------------------------------------------------------------

// Function to get the user typed item, validate it, loops until user types the correct item,
// and counts and prints the user typed right item with its frequency.
void UserItem() {
    // Declaring variables needed for this function
    int count = 0;
    string userItem;

    cout << "Enter a Grocery item name: " << endl;
    cin >> userItem;

    // Input validation of user input, Looping until the user enters the correct item.
    while (freq.count(userItem) == 0 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Couldnot find \"" << userItem << "\" item. " << endl;
        cout << "Enter a valid item name again with first letter Upper case or Press \"0\" to go to Main Menu" << endl;
        cin >> userItem;

        // if condition to break the loop if user decides to go to the main menu.
        if (userItem == "0") {
            break;
        }
    }

    // Condition to check if key exists in the map container, if it does then counts.
    if (freq.count(userItem) > 0) {
        count = freq[userItem];
    }
    cout << "-----------------------------------------------------" << endl;
    cout << userItem << " " << count << endl;
    cout << endl;
}
//---------------------------------------------------------------------------------------------------------------------------

//Function to print all the items and frequencies of the map container.
void PrintAllItem() {
    // Header
    cout << "------------------------" << endl;
    cout << setw(12) << left << "Items " << "| Frequency" << endl;
    cout << "------------------------" << endl;

    // main Loop
    for (auto i = freq.begin(); i != freq.end(); i++) {
        cout << setw(11) << left << i->first << " => " << setw(5) << left << i->second << endl;
    }

    // Footer
    cout << "------------------------" << endl;
    cout << endl;
}
//----------------------------------------------------------------------------------------------------------------------------

// Function prints the frequency of all items in the input file as a histogram
// Uses the nested loop to print astreiks each time it finds the same item. 
void PrintItemHistogram() {

    // Header
    cout << "------------------------" << endl;
    cout << setw(11) << left << "Items " << "| Histogram" << endl;
    cout << "------------------------" << endl;

    // Nested loop
    for (auto i = freq.begin(); i != freq.end(); i++) {
        cout << setw(11) << left << i->first << "| ";
        for (int j = 0; j < i->second; j++) {
            cout << "*";
        }
        cout << endl;
    }

    //Footer
    cout << "------------------------" << endl;
}
//----------------------------------------------------------------------------------------------------------------------------

// Function to display the main Menu with Options to the user
void DisplayMenu() {
    cout << "****************************************************************************************" << endl;
    cout << "* Option 1 --> Input the Item to get its frequency.                                    *" << endl;
    cout << "* Option 2 --> Prints all the items and their frequencies.                             *" << endl;
    cout << "* Option 3 --> Prints all the items with their frequencies in the form of a histogram. *" << endl;
    cout << "* Option 4 --> Exit the Program.                                                       *" << endl;
    cout << "****************************************************************************************" << endl;
}
//-------------------------------------END OF FUNCTIONS-----------------------------------------------------------------------

//-----------------------------------START OF MAIN FUNCTION-------------------------------------------------------------------

int main() {
    // Using try block to handle the exception, also used inside the functions
    try {
        // Opening the CS210_Project_Three_Input_File.txt file
        inFS.open("CS210_Project_Three_Input_File.txt");

        // Condition to check if the file is opened and exception handler to catch the error
        if (!inFS.is_open()) {
            throw runtime_error("Could not open file \"CS210_Project_Three_Input_File.txt\"");
        }

        // Calling the ReadFromFile function to read the file and store it into the map container. 
        ReadFromFile();

        // Opening a new file to write the data from the map container. 
        outFS.open("Frequency.dat");

        // If condition to check for errors while opening the file and try-catch block to handle exception. 
        if (outFS.fail() || !outFS.is_open()) {
            throw runtime_error("Could not open file \"Frequency.dat\"");
        }

        // Calling WriteToFile function to write the file into new file "Frequency.dat"
        WriteToFile();

        // Declaring variable for the while loop and switch statement for the menu option.
        int choice = 0;

        while (choice != 4) {

            // calling display menu to show options to the user.
            DisplayMenu();

            cout << "Select option" << endl;
            cin >> choice;

            // Input validation if the choice is other than integer.
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Wrong Type!!! Enter Integers only!!!" << endl;
            }
            switch (choice) {
            case 1:
                UserItem();             // Calling UserItem function for user input
                break;
            case 2:
                PrintAllItem();         // Calling PrintAllItem function to print all the item from the map container
                break;
            case 3:
                PrintItemHistogram();   // Calling PrintItemHistogram to print all the item with histogram
                break;
            case 4:
                cout << "Thank you for Using this program. Goodbye... " << endl;
                break;
            default:
                cout << "Invalid Option!!! Select Option 1 to 4." << endl;
                break;
            }
        }

    }
    // Catch statements to catch the various runtime errors while opening,
    // closing and reading the files within the main function and functions above.
    catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
        cout << "Check the Errors and run the program again..." << endl;
    }

    return 0;
}
//----------------------------------END OF THE GROCERY-TRACKING PROGRAM--------------------------------------------------------
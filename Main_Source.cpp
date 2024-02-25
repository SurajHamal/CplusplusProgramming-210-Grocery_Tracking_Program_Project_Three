/*
Date:    02/08/2024
Author:  Suraj Hamal
Company: AIRGEAD BANKING
Purpose: TO print the balance sheet with year-end Balance and Interest
         after calculationg the user entered initial amount, additional
         monthly deposit, interest rate and number of years.
*/
#include <iostream>
#include <iomanip>
#include "AirgeadFunctions.h"
#include <stdexcept>

using namespace std;


int main() {

    // Variables to store the user input values from the user
    double userAmount;
    double userDeposit;
    double userInterest;
    int userYears;
    char quitCmd = 'a';

    Investment newAccount;      // creating a userInvestment object
    newAccount.DisplayMainMenu();   // calling Display menu function to show the menu to the user

    while (quitCmd != 'q') {		// using a while loop to iterate if input validation fails or user wants to check more rates
        try {							// using try and catch block for the input validation
            cout << setfill('*') << setw(42) << '*' << endl;
            cout << setfill('*') << setw(15) << '*' << " DATA INPUT ";
            cout << setfill('*') << setw(15) << '*' << endl;

            // Getting different inputs from the user, storing it to the variables, 
            // using if throw conditions to check to see if its positive real number with the error message attached to it. 
            // and setting it to the userInvestment object
            cout << "Initial Investment Amount: $";
            cin >> userAmount;

            if (userAmount < 0 || cin.fail()) {
                throw runtime_error("Invalid Initial Amount!!! Deposit must be positive real number.");
            }
            newAccount.SetInvestmentAmount(userAmount);

            cout << "Monthly Deposit: $";
            cin >> userDeposit;

            if (userDeposit < 0 || cin.fail()) {
                throw runtime_error("Invalid Deposit!!! Deposit must be positive real number.");
            }
            newAccount.SetMonthlyDeposit(userDeposit);

            cout << "Annual Interest: %";
            cin >> userInterest;
            if (userInterest < 0 || cin.fail()) {
                throw runtime_error("Invalid Interest!!! Interest must be positive real number.");
            }
            newAccount.SetAnnualInterest(userInterest);

            cout << "Number of years: ";
            cin >> userYears;
            if (userYears < 0 || cin.fail()) {
                throw runtime_error("Invalid Year!!! Year must be positive real number.");
            }
            newAccount.SetNumberOfYears(userYears);
            cout << endl;

            // Printing the balance sheets with user input values after the calculation
            newAccount.PrintBalanceSheet(userYears);

        }

        // catch block to catch any invalid inputs from the user fro above with its message
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
            cout << endl;
            cout << "Cannot compute the year-end balances and interest. Try again!!!" << endl;
        }

        // Give options to user to either quit or continue
        cout << "Press 'q' to quit" << endl;
        cout << "Press any letters or numbers other than 'q' and hit Enter to test different monthly amounts,";
        cout << "interest rates, and lengths." << endl;
        cin >> quitCmd;
    }

    return 0;
}






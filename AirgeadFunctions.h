// using header file guards
#ifndef AIRGEAD_FUNCTIONS_H
#define AIRGEAD_FUNCTIONS_H

#include <string>
#include <iostream>
#include <string>

using namespace std;

class Investment {

public: // public class members
    Investment(double m_investmentAmount = 0.0, double m_monthlyDeposit = 0.0, 
                double m_annualInterest = 0.0, int numberOfYears = 0);     // default constructor
    
    // Mutators
    void SetInvestmentAmount(double t_investmentAmount);  
    void SetMonthlyDeposit(double t_monthlyDeposit);
    void SetAnnualInterest(double t_annualInterest);
    void SetNumberOfYears(int t_numberOfYears);

    // Accessors
    double GetInvestmentAmount() const;                 
    double GetMonthlyDeposit() const;
    double GetAnnualInterest() const;
    int GetNumberOfYears() const;

    // Calculating and printing functions
    void DisplayMainMenu();
    double ClosingBalance(int t_years, double t_deposit);
    double InterestAmount(int t_years, double t_deposit);
    void PrintBalanceSheet(int t_years);

private: // private class members
    double m_investmentAmount;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

};

#endif  
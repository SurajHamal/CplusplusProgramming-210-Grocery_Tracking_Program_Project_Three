#include "AirgeadFunctions.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Another Constructor
Investment::Investment(double m_investmentAmount, double m_monthlyDeposit,
			double m_annualInterest, int m_numberOfYears) {
	this->m_investmentAmount = m_investmentAmount;
	this->m_monthlyDeposit = m_monthlyDeposit;
	this->m_annualInterest = m_annualInterest;
	this->m_numberOfYears = m_numberOfYears;
}

//--------------------------------------------------------------------------------------
// Mutators functions
void Investment::SetInvestmentAmount(double t_investmentAmount) {
	this->m_investmentAmount = t_investmentAmount;
}

void Investment::SetMonthlyDeposit(double t_monthlyDeposit) {
	this->m_monthlyDeposit = t_monthlyDeposit;
}

void Investment::SetAnnualInterest(double t_annualInterest) {
	m_annualInterest = t_annualInterest;
}

void Investment::SetNumberOfYears(int t_numberOfYears) {
	m_numberOfYears = t_numberOfYears;
}
//-------------------------------------------------------------------------------------

// Accessors functions
double Investment::GetInvestmentAmount() const {
	return m_investmentAmount;
}

double Investment::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}

double Investment::GetAnnualInterest() const {
	return m_annualInterest;
}

int Investment::GetNumberOfYears() const {
	return m_numberOfYears;
}
//--------------------------------------------------------------------------------------

// Function that just displays the Menu before before the user Input 
void Investment::DisplayMainMenu() {
	cout << setfill('*') << setw(42) << '*' << endl;
	cout << setfill('*') << setw(15) << '*' << " DATA INPUT ";
	cout << setfill('*') << setw(15) << '*' << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
}
//--------------------------------------------------------------------------------------

// Function to calculate earned interest using nested loop to loop through the months and years 
double Investment::InterestAmount(int t_years, double t_deposit) {
	double closingBalance = GetInvestmentAmount();
	double earnedInterest = 0;
	double compoundInterest = 0;
	for (unsigned i = 1; i < t_years + 1; ++i) {
		earnedInterest = 0;
		for (unsigned j = 1; j < 12 + 1; ++j) {
			compoundInterest = (closingBalance + t_deposit) * ((GetAnnualInterest() / 100) / 12);
			closingBalance = (closingBalance + t_deposit) + compoundInterest;
			earnedInterest = compoundInterest + earnedInterest;
		}
	}
	return earnedInterest;
}
//--------------------------------------------------------------------------------------

// Function to calculate the closing balance by iterating through the monthly loop
double Investment::ClosingBalance(int t_years, double t_deposit) {
	double closingBalance = GetInvestmentAmount();
	double earnedInterest = 0;
	double compoundInterest = 0;
	for (unsigned i = 1; i < (t_years * 12) + 1; ++i) {
		compoundInterest = (closingBalance + t_deposit) * ((GetAnnualInterest() / 100) / 12);
		closingBalance = (closingBalance + t_deposit) + compoundInterest;
	}
	return closingBalance;
}
//--------------------------------------------------------------------------------------

// Function to print the two balance sheets without and with the additional monthly deposits 
void Investment::PrintBalanceSheet(int t_years) {
	// balance sheet without monthly deposit
	cout << setfill(' ') << setw(15) << ' ' <<
		"Balance and Interest Without Additional Monthly Deposits" <<
		setfill(' ') << setw(15) << ' ' << endl;
	cout << setfill('=') << setw(90) << '=' << endl;
	cout << setfill(' ') << setw(10) << "Year";
	cout << setw(30) << "Year End Balance";
	cout << setw(40) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(90) << '-' << endl;

	for (unsigned i = 1; i < (t_years + 1); ++i) {
		cout << setfill(' ') << setw(10) << i << ' ';
		cout << right << setw(20) << "$" << fixed << setprecision(2) << ClosingBalance(i, 0);
		cout << right << setw(30) << "$" << InterestAmount(i, 0) << endl;
	}
	cout << endl;

	// Print balance sheet with monthly deposit included
	cout << setfill(' ') << setw(15) << ' ' <<
		"Balance and Interest with Additional Monthly Deposits" <<
		setfill(' ') << setw(15) << ' ' << endl;
	cout << setfill('=') << setw(90) << '=' << endl;
	cout << setfill(' ') << setw(10) << "Year";
	cout << right << setw(30) << "Year End Balance";
	cout << right << setw(40) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(90) << '-' << endl;

	for (unsigned i = 1; i < (GetNumberOfYears() + 1); ++i) {
		cout << setfill(' ') << right << setw(10) << i << ' ';
		cout << setfill(' ') << right << setw(20) << "$";
		cout << right << ClosingBalance(i, GetMonthlyDeposit());
		cout << setfill(' ') << right << setw(30) << "$";
		cout << right << InterestAmount(i, GetMonthlyDeposit()) << endl;
	}
}
//--------------------------------------------------------------------------------------
//-----------------------------End-of-the-Functions-------------------------------------

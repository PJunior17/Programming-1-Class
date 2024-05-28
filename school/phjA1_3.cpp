#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	float loan_amount;
	float annual_interest_rate;
	int num_payments;

	std::cout << "Load Amount: $";
	std::cin >> loan_amount;
	std::cout << "Annual interest rate (in the format 0.12 (for 12%): ";
	std::cin >> annual_interest_rate;
	std::cout << "Number of monthly payments to be made: ";
	std::cin >> num_payments;

	float rate = annual_interest_rate / 12;
	float monthly_interest_rate = rate * 100;
	float payment = ((rate * pow(1+rate, num_payments)) / (pow(1+rate, num_payments) -1)) * loan_amount;
	float amount_paid_back = num_payments * payment;
	float interest_paid = amount_paid_back - loan_amount;
	
	std::cout << std::fixed;
	std::cout << "- - Loan Report - -\n\n";
	std::cout << "Loan Amount: $" << std::setprecision(2) << loan_amount << std::endl;
	std::cout << "Monthly Interest Rate: " << std::setprecision(2) << monthly_interest_rate << "%" << std::endl;
	std::cout << "Number of Payments: " << std::setprecision(2) << num_payments << std::endl;
	std::cout << "Monthly Payment: $" << std::setprecision(2) << payment << std::endl;
	std::cout << "Amount Paid Back $" << std::setprecision(2) << amount_paid_back << std::endl;
	std::cout << "Interest Paid $" << std::setprecision(2) << interest_paid << std::endl;

	

	return 0;
}


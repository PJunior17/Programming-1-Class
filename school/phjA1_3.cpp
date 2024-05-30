/* Programmer Name: Phiron Hin Jr
 * File Name: phjA1_3.cpp
 * Summary: This code will take the user inputs: loan amount, annual interest rate, and number of payments. Then it 
 * will calculate the monthly payments the user has to make and generate a loan report. The loan report will consist of
 * information the user has entered, how much monthly payments they will have to make, and how much money they will end 
 * up paying due to interest.  
 * Challenging: The formatting of the loan report was quite challenging as I have never worked with iomanip before. 
 * It was also interesting to see that there is a function to set the precision for decimals where as in C you would
 * put something like printf("%.2f", some_float); I do like that there is a function for this but it feels like it 
 * just adds verbosity compared to C.
 * Time: This took about 30 minutes to code
 * Revision: 5/28/24 Rev 1.0: Wrote base code to make the function work
 * 	     5/30/24 Rev 1.1: Formatted the loan reciept to make the amounts align with eachother and wrote description
 *
 * The complete Chart based on the requirements of the assignment example:
 * Load Amount: $1000000
 * Annual interest rate (in the format 0.12 (for 12%): .24
 * Number of monthly payments to be made: 24
 * - - Loan Report - -

 * Loan Amount:                           $1000000.00
 * Monthly Interest Rate:                  2.00%
 * Number of Payments:                     24
 * Monthly Payment:                       $52871.14
 * Amount Paid Back:                      $1268907.25
 * Interest Paid:                         $268907.25
 */

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
	std::cout << "Loan Amount:" << std::setprecision(2) << std::setw(28) << "$" << loan_amount << std::endl;
	std::cout << "Monthly Interest Rate:" << std::setprecision(2) << std::setw(22) << monthly_interest_rate << "%" << std::endl;
	std::cout << "Number of Payments:" << std::setprecision(2) << std::setw(23) << num_payments << std::endl;
	std::cout << "Monthly Payment:" << std::setprecision(2) << std::setw(24) << "$" << payment << std::endl;
	std::cout << "Amount Paid Back:" << std::setprecision(2) << std::setw(23) << "$" << amount_paid_back << std::endl;
	std::cout << "Interest Paid:" << std::setprecision(2) << std::setw(26) << "$" << interest_paid << std::endl;

	return 0;
}


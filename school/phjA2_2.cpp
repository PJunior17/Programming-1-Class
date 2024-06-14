/* Programmer Name: Phiron Hin Jr
 * File Name: phjA2_2.cpp
 * Summary: This code will take user input for an account balance and the annal interest 
 * rate. Then it will ask the user for desposits and withdrawls per month for a 3 month 
 * period. A report will be assembled at the end showing the user their quarterly 
 * savings account statement.
 * Challenging: The ordering of all the variables to be used appropriately was challenging
 * because there were a lot of variables to keep track of and we aren't using structs 
 * to group all the variables together. 
 * Time: This took a 45 minutes to code
 * Revision: 6/4/24 Rev 1.0: Wrote all code
 * 	     6/9/24 Rev 2.0: Wrote description
 *  
 * The complete Chart based on the requirements of the assignment example:
Enter the starting balance on the account: $1200
Enter annual interest rate (e.g. 0.04): 0.02

Month 1
Total deposited for the month: $1200
Total withdrawn for the month: $100
Interest recieved this month: $2.92
Ending monthly balance: $2302.92

Month 2
Total deposited for the month: $123
Total withdrawn for the month: $1314
Interest recieved this month: $2.85
Ending monthly balance: $1114.76

Month 3
Total deposited for the month: $3
Total withdrawn for the month: $44
Interest recieved this month: $1.82
Ending monthly balance: $1075.59

Quarterly Savings Account Statement

Starting Balance:   $      1200.00
Total Deposits:    +$      1326.00
Total Withdrawls:  -$      1458.00
Total Interest:    +$         7.59
                      ________________
Ending Balance:       1075.59
----------------------------------------------------------
*/

#include <iostream>
#include <iomanip>

int main() {
	float balance;
	std::cout << "Enter the starting balance on the account: $";
	std::cin >> balance;	
	
	float interest_rate;
	std::cout << "Enter annual interest rate (e.g. 0.04): ";
	std::cin >> interest_rate;
	std::cout << "\n";
	
	int month = 1;
	float start_month_balance = balance;
	float end_month_balance = balance;
	float monthly_interest_rate = interest_rate / 12;
	float monthly_interest_added;

	float total_deposited;
	float total_withdrawn;
	float total_interest;
	float monthly_deposit;
	float monthly_withdrawn;
	do {
		std::cout << std::fixed;
		std::cout << "Month " << month << std::endl;
		
		std::cout << "Total deposited for the month: $";
		std::cin >> monthly_deposit;
		end_month_balance += monthly_deposit;
		total_deposited += monthly_deposit;

		std::cout << "Total withdrawn for the month: $";
		std::cin >> monthly_withdrawn;
		end_month_balance -= monthly_withdrawn;
		total_withdrawn += monthly_withdrawn;

		monthly_interest_added = monthly_interest_rate * ((start_month_balance + end_month_balance) / 2);
		std::cout << "Interest recieved this month: " << std::setprecision(2) << "$" <<  monthly_interest_added << std::endl;
		total_interest += monthly_interest_added;

		end_month_balance += monthly_interest_added;
		std::cout << "Ending monthly balance: " << std::setprecision(2) << "$" << end_month_balance << "\n\n";
		
		start_month_balance = end_month_balance;
		month++;	
	} while(month < 4);
	
	std::cout << "Quarterly Savings Account Statement\n\n";
	std::cout << "Starting Balance:   $ " << std::setprecision(2) << std::setw(12) << balance << std::endl;
	std::cout << "Total Deposits:    +$" << std::setprecision(2) << std::setw(13)<< total_deposited << std::endl;
	std::cout << "Total Withdrawls:  -$" << std::setprecision(2) << std::setw(13)<< total_withdrawn << std::endl;
	std::cout << "Total Interest:    +$" << std::setprecision(2) << std::setw(13)<< total_interest << std::endl;
	std::cout << std::setw(38) << "________________" << std::endl;
	std::cout << "Ending Balance: " << std::setprecision(2) << std::setw(13)<< end_month_balance << std::endl;

	std::cout << "----------------------------------------------------------\n";

	return 0;
}


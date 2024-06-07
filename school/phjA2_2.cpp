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
	do {
		std::cout << std::fixed;
		std::cout << "Month " << month << std::endl;
		
		float monthly_deposit;
		std::cout << "Total deposited for the month: $";
		std::cin >> monthly_deposit;
		end_month_balance += monthly_deposit;
		total_deposited += monthly_deposit;

		float monthly_withdrawn;
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
	std::cout << "Starting Balance: " << std::setprecision(2) << std::setw(12) << balance << std::endl;
	std::cout << "Total Deposits: " << std::setprecision(2) << std::setw(14)<< total_deposited << std::endl;
	std::cout << "Total Withdrawls: " << std::setprecision(2) << std::setw(12)<< total_withdrawn << std::endl;
	std::cout << "Total Interest: " << std::setprecision(2) << std::setw(14)<< total_interest << std::endl;
	std::cout << "________________" << std::endl;
	std::cout << "Ending Balance: " << std::setprecision(2) << std::setw(13)<< end_month_balance << std::endl;

	std::cout << "----------------------------------------------------------\n";

	return 0;
}


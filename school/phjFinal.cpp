/*rev 1.0 6/17/24 wrote function prototypes and started the main function
 *    1.1 6/18/24 wrote the display_seating_chart, validate_ticket, request_tickets functions and got them to work
 *    2.0 6/20/24 refactored code to use pointer notation instead of array notation
 *
 *
 *
 */

#include <iostream>
#include <string>
#include <iomanip>

//Function Prototypes
void display_seating_chart(std::string seats[15][30]);
void display_seating_prices();
void update_seating_prices();
bool validate_ticket_request(std::string seats[15][30], int, int);
void request_tickets(std::string seats[15][30]);
void print_sales_report(std::string seats[15][30]);

int main() {
	float seat_price[15] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0};
	std::string seats[15][30];	

	for(int i = 0; i < 15; i++) {
		for(int j = 0; j < 30; j++) {
			seats[i][j] = "  #";
		}
	}

	int choice;
	do {	
		std::cout << "       C++ Theater\n\n";
		std::cout << "1. Display Seating Chart\n";
		std::cout << "2. Display Seating Prices\n";
		std::cout << "3. Update Seating Prices\n";
		std::cout << "4. Request Tickets\n";
		std::cout << "5. Print Sales Report\n";
		std::cout << "6. Exit the Program\n\n";
		std::cout << "Enter your choice (1-6): ";
		
		std::cin >> choice;
		if(choice < 1 || choice > 6) {
			std::cout << "Please enter a choice between 1-6: ";
			std::cin >> choice;
		}

		switch(choice) {
			case(1):
				display_seating_chart(seats);
				std::cout << "\n\n";
				break;
			
			case(2):
				display_seating_prices();
				std::cout << "\n\n";
				break;
			case(3):
				update_seating_prices();
				std::cout << "\n\n";
				break;
			case(4):
				request_tickets(seats);
				display_seating_chart(seats);
				std::cout << "\n\n";
				break;
			case(5):
				print_sales_report(seats);
				std::cout << "\n\n";
				break;
			case(6):
				std::cout << "\n\n";
				return 0;
				break;
		}
	} while(choice != 6);
	return 0;
}

void display_seating_chart(std::string seats[15][30]) {
	std::cout << "\t  ";
	for(int i = 1; i < 31; i++) {
		if(i < 10) {
			std::cout << "0";
		}
		std::cout << i << " ";
	}
	std::cout << "\n";

	int row_count = 1;
	for(int i = 0; i < 15; i++) {
		std::cout << "Row " << row_count << "   ";
		if(i < 9) std::cout << " ";
		row_count++;
		for(int j = 0; j < 30; j++) {
			std::cout << seats[i][j];
		}
		std::cout << "\n";
	}
}


void display_seating_prices() {
	return;
}

void update_seating_prices() {
	
	return;
}

bool validate_ticket_request(std::string seats[15][30], int row, int col) {
	if(row < 1 || row > 15 || col < 1 || col > 30) {
		std::cout << "This seat does not exist. Please enter values 1-15 for row and 1-30 for seat.\n\n";
		return false;
	}
	
	if(seats[row-1][col-1] == " *") {
		std::cout << "This seat is not available.\n\n";
		return false;
	}
	return true;
}

void request_tickets(std::string seats[15][30]) {
	int row;
	int col;
	do {
		std::cout << "Please enter the row of the seat you would like: ";
		std::cin >> row;
		std::cout << "Please enter the seat number you would like: ";
		std::cin >> col;
		validate_ticket_request(seats, row, col);
	} while(!validate_ticket_request(seats, row, col));

	seats[row-1][col-1] = "  *";
}

void print_sales_report(std::string seats[15][30]) {
	float total = 0.0;
	for(int i = 0; i < 15; i++) {
		for(int j = 0; j < 30; j++) {
			if(seats[i][j] == "  *") {
				total += (i+1);
			}
		}
	}
}


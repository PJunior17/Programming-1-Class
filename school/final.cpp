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
#include <fstream>

//FUNCTION PROTOTYPES//
void initialize_empty_seats(std::string* seats, int, int);
void initialize_seat_prices(float* seat_prices);

//inside switch statement//
void display_seating_chart(std::string* seats, int, int);
void display_seating_prices();
void update_seating_prices(float* seat_prices);
bool validate_ticket_request(std::string* seats , int, int);
void request_tickets(std::string* seats);
//void print_sales_report(std::string* seats);

int main() {
	std::string* seats;	
	int rows = 15;
	int cols = 30;
	seats = new std::string[rows*cols];
	float seat_prices[15] = {30.0, 30.0, 30.0, 30.0, 
				 20.0, 20.0, 20.0, 20.0, 
				 12.0, 12.0, 12.0, 12.0, 
				 8.0, 8.0, 8.0};
	

	initialize_empty_seats(seats, rows, cols);	
	initialize_seat_prices(seat_prices);	

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

		std::string password;

		switch(choice) {
			case(1):
				display_seating_chart(seats, rows, cols);
				std::cout << "\n\n";
				break;
			
			case(2):
				display_seating_prices();
				std::cout << "\n\n";
				break;
			case(3):
				std::cout << "Please enter the Manager's password to update seating prices ";
				std::cout << "(Hint: password): ";
				std::cin >> password;
				if(password != "password") {
					std::cout << "You are not the Manager, only the Manager can change the seating prices\n";
					break;
				}

				update_seating_prices(seat_prices);
				std::cout << "\n\n";
				break;
			case(4):
				request_tickets(seats);
				display_seating_chart(seats, rows, cols);
				std::cout << "\n\n";
				break;
			case(5):
			//	print_sales_report(seats);
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

void initialize_empty_seats(std::string* seats, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			*(seats+i * cols+j) = "  #";
		}
	}
}

void initialize_seat_prices(float* seat_prices) {
	std::ofstream prices;
	prices.open("seat_prices.txt");
	for(int i = 0; i < 15; i++) {
		prices << "Row " << (i+1) << ": $" << std::fixed << std::setprecision(2) << seat_prices[i] << "\n";
	}
	prices.close();

}

void display_seating_chart(std::string* seats, int rows, int cols) {
	std::cout << "\t  ";
	for(int i = 1; i < 31; i++) {
		if(i < 10) {
			std::cout << "0";
		}
		std::cout << i << " ";
	}
	std::cout << "\n";

	int row_count = 1;
	for(int i = 0; i < rows; i++) {
		std::cout << "Row " << row_count << "   ";
		if(i < 9) std::cout << " ";
		row_count++;
		for(int j = 0; j < cols; j++) {
			std::cout << *(seats+i * cols+j); 
		}
		std::cout << "\n";
	}
}

void display_seating_prices() {
	std::string line;
	std::ifstream prices ("seat_prices.txt");
	
	if(!prices.is_open()) { 
		std::cout << "Failed to open the file\n";	
	}
	while(std::getline(prices, line)) {
		std::cout << line << std::endl;
	}
	prices.close();
}

void update_seating_prices(float* seat_prices) {
	int change;
	float price;
	std::cout << "Enter the row you want to change the price of: ";
	std::cin >> change;
	std::cout << "Enter the new price: $";
	std::cin >> price;
	
	seat_prices[change-1] = price;

	std::ofstream prices;
	prices.open("seat_prices.txt");
	for(int i = 0; i < 15; i++) {
		prices << "Row " << i << ": $" << std::fixed << std::setprecision(2) << seat_prices[i] << "\n";
	}
	prices.close();

	display_seating_prices();
}

bool validate_ticket_request(std::string* seats, int row, int col) {
	if(row < 1 || row > 15 || col < 1 || col > 30) {
		std::cout << "This seat does not exist. Please enter values 1-15 for row and 1-30 for seat.\n\n";
		return false;
	}
	
	if(*(seats+(row-1) * 30+(col-1)) == "  *") {
		std::cout << "This seat is not available.\n\n";
		return false;
	}
	return true;
}

void request_tickets(std::string* seats) {
	int row;
	int col;
	bool valid;
	do {
		std::cout << "Please enter the row of the seat you would like: ";
		std::cin >> row;
		std::cout << "Please enter the seat number you would like: ";
		std::cin >> col;
		valid = validate_ticket_request(seats, row, col);
	} while(!valid);
	
	*(seats+(row-1) * 30+(col-1)) = "  *";
}







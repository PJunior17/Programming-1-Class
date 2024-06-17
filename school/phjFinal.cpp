#include <iostream>
#include <string>
#include <iomanip>

//Function Prototypes
void display_seating_chart(std::string seats[15][30]);
void display_seating_prices();
void update_seating_prices();
void request_tickets();
void print_sales_report();

int main() {
	float seat_price[15] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0};
	std::string seats[15][30];	

	for(int i = 0; i < 15; i++) {
		for(int j = 0; j < 30; j++) {
			seats[i][j] = " #";
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
				break;
			
			case(2):
				display_seating_prices();
				break;
			case(3):
				update_seating_prices();
				break;
			case(4):
				request_tickets();
				break;
			case(5):
				print_sales_report();
				break;
			case(6):
				return 0;
				break;
		}
	} while(choice < 1 || choice > 6);
	return 0;
}

void display_seating_chart(std::string seats[15][30]) {
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

void request_tickets() {
	return;
}

void print_sales_report() {
	return;
}


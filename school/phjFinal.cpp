/* Programmer Name: Phiron Hin Jr
 * File Name: phjFinal.cpp
 * Summary: This code replicated the movie theater terminal where you can purchase tickets from. Here the user will buy tickets and 
 * have the options to display a seating chart, display the seating prices, request tickets, and print the sales report. If the user
 * is a manager they are allowed to change the price of the tickets as much as they want.
 * Challenging: The challenging part of this code was to refator all the code to use the poitner notation instead of the array 
 * notation. I was in pretty deep with the array notation so it took a lot of work to change it to the pointer notation.
 * Time: This took 2.5 hours to code
 * Revision: 1.0 6/17/24 wrote function prototypes and started the main function
 *           1.1 6/18/24 wrote the display_seating_chart, validate_ticket, request_tickets functions and got them to work
 *    	     2.0 6/20/24 refactored code to use pointer notation instead of array notation
 *           2.1 6/21/24 wrote the sales report and fixed all error validation checks
 *           2.2 6/23/24 wrote description and comments for grades
 *
 * This is a complete chart based on the requirements of the assignement example:
 *
       C++ Theater

1. Display Seating Chart
2. Display Seating Prices
3. Update Seating Prices
4. Request Tickets
5. Print Sales Report
6. Exit the Program

Enter your choice (1-6): 4
Please enter the row of the seat you would like: 1
Please enter the seat number you would like: 1
          01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
Row 1      *  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 2      #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 3      #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 4      #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 5      #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 6      #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 7      #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 8      #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 9      #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 10     #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 11     #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 12     #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 13     #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 14     #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
Row 15     #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #


       C++ Theater

1. Display Seating Chart
2. Display Seating Prices
3. Update Seating Prices
4. Request Tickets
5. Print Sales Report
6. Exit the Program

Enter your choice (1-6): 5
**************************
Movie Ticket Recipt
**************************
Number of Seats Purchased:  1
Number of Seats Available:  449
Total for Seats Purchased: $30.00
**************************
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

//FUNCTION PROTOTYPES//

//initaization function prototypes 
void initialize_empty_seats(std::string* seats, int, int);
void initialize_seat_prices(float* seat_prices);

//functions inside of switch statement
void display_seating_chart(std::string* seats, int, int);
void display_seating_prices();
void update_seating_prices(float* seat_prices);
bool validate_ticket_request(std::string* seats , int, int);
void request_tickets(std::string* seats);
void print_sales_report(std::string* seats, float* seat_prices, int, int);

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
				print_sales_report(seats, seat_prices, rows, cols);
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

//initializes all the empty seats in the theater for the user to choose from
void initialize_empty_seats(std::string* seats, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			*(seats+i * cols+j) = "  #";
		}
	}
}


//initializes the seat prices and put the prices into the text file "seat_prices.txt"
void initialize_seat_prices(float* seat_prices) {
	std::ofstream prices;
	prices.open("seat_prices.txt");
	for(int i = 0; i < 15; i++) {
		prices << "Row " << (i+1) << ": $" << std::fixed << std::setprecision(2) << seat_prices[i] << "\n";
	}
	prices.close();

}

//will show the seating chart with # being an empty seat and * being a seat that is purchased
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

//will read from the seat_prices.txt file and show all the seat prices to the user
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

//allows the manager to change the seat prices for the user to purchase
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

//makes sure that the user is purchasing a ticket that is valid in the theater
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

//allows the user to purchase a ticket in the theater
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

//prints a reciept for the user
void print_sales_report(std::string* seats, float *seat_prices, int rows, int cols) {
	float total = 0.0;
	int count = 0;
	int available = 0;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {	
			if(*(seats+i * cols+j) == "  *") {
				total += *(seat_prices+i);
			       	count++;	
			}
			if(*(seats+i * cols+j) == "  #") {
				available++;
			}
		}
	}
	std::cout << std::fixed;
	std::cout << "\n**************************\n";
	std::cout << "Movie Ticket Recipt\n";
	std::cout << "**************************\n";
	std::cout << "Number of Seats Purchased:  " << count << std::endl; 
	std::cout << "Number of Seats Available:  " << available << std::endl;
	std::cout << "Total for Seats Purchased: $" << std::setprecision(2) << total << std::endl;
	std::cout << "**************************\n";
}
		

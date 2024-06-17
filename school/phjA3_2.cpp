/* Programmer Name: Phiron Hin Jr
 * File Name: phjA3_2.cpp
 * Summary: This code will generate a random number for the for the computer that will 
 * correspond to a list for rock, paper, scissors. The user will then choose a number 
 * for a list that also corresponds to one of the options. Then it will compare the two 
 * numbers and choose a winner and a loser. The winner will then be outputed with a 
 * message in the terminal 
 * Challenging: The most challenging part was to learn how to use random.
 * Time: This took 45 minutes to code
 * Revision: 6/16/24 Rev 1.0: Wrote code and description
 * The complete Chart based on the requirements of the assignment example:
 *
Game Menu
---------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice: 2
Tie. No Winner
You selected: Paper
The computer selected: Scissors
Computer Wins! Scissors cuts Paper
 *
 */

#include <iostream>
#include <random>

//GLOBALS
std::random_device cpu_pick;
std::uniform_int_distribution<int> randomInt(1,3);

//Function Prototypes
void tie_check(int, int);
bool rock_chosen(int);
bool paper_chosen(int);
bool scissors_chosen(int);

int main() {
	int number;
	do {
		int cpu_plays = randomInt(cpu_pick);
		std::cout << "Game Menu\n";
		std::cout << "---------\n";
		std::cout << "1) Rock\n";
		std::cout << "2) Paper\n";
		std::cout << "3) Scissors\n";
		std::cout << "4) Quit\n\n";
		std::cout << "Enter your choice: ";

		std::cin >> number;
		if(number < 1 || number > 4) {
			std::cout << "You entered a number not on the list\n";
			std::cout << "Please enter a number on the list: ";
			std::cin >> number;
		}
		tie_check(number, cpu_plays);

		switch(number) {
			case(1):
				if(rock_chosen(cpu_plays)) {
					std::cout << "You selected: Rock\n";
					std::cout << "The computer selected: Scissors\n";
					std::cout << "YOU WIN! Rock smashes Scissors\n";
				} else if(!rock_chosen(cpu_plays)) {
					std::cout << "You selected: Rock\n";
					std::cout << "The computer selected: Paper\n";
					std::cout << "Computer Wins! Paper wraps Rock\n";
				}
				break;
			case(2):
				if(paper_chosen(cpu_plays)) {
					std::cout << "You selected: Paper\n";
					std::cout << "The computer selected: Rock\n";
					std::cout << "YOU WIN! Paper wraps Rock\n";
				} else if(!paper_chosen(cpu_plays)) {
					std::cout << "You selected: Paper\n";
					std::cout << "The computer selected: Scissors\n";
					std::cout << "Computer Wins! Scissors cuts Paper\n";
				}
				break;
			case(3):
				if(scissors_chosen(cpu_plays)) {
					std::cout << "You selected: Scissors\n";
					std::cout << "The computer selected: Paper\n";
					std::cout << "YOU WIN! Scissors cuts Paper\n";
				} else if(!scissors_chosen(cpu_plays)) {
					std::cout << "You selected: Scissors\n";
					std::cout << "The computer selected: Rocl\n";
					std::cout << "Computer Wins! Rock smashes Scissors\n";
				}
				break;
			case(4):
				return 0;
				break;
		}
	} while(number < 1 || number > 4);
	
	return 0;
}

void tie_check(int number, int cpu_plays) {
	if(number == cpu_plays) {
		std::cout << "Tie. No Winner\n";
	}
}

bool rock_chosen(int cpu_plays) {
	return cpu_plays == 3;
}

bool paper_chosen(int cpu_plays) {
	return cpu_plays == 1;
}

bool scissors_chosen(int cpu_plays) {
	return cpu_plays == 2;
}



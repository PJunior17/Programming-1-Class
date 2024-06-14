/* Programmer Name: Phiron Hin Jr
 * File Name: phjA2_3.cpp
 * Summary: This code takes a user input and inputs into a file named "Numbers.txt". The
 * user then inputs all the numbers going into this file which then adds all of them
 * and computes an average.
 * Challenging: Learning how to open and write to a file then read from the file was hard.
 * I only have done this in python so this was not too different but still challenging.
 * Time: This took 1 hour to code
 * Revision: 6/9/24 Rev 1.0: Wrote code and description
 *
 * The complete Chart based on the requirements of the assignment example:
For how many numbers do you want to enter? 3
Write the data to Numbers.txt file
Enter the number 1: 2
Enter the number 2: 4
Enter the number 3: 6
Data written to Numbers.txt
-----The end for entering data-----
Enter the file name: Numbers.txt
2
4
6
Numbers of numbers: 3
Sum of numbers: 12.00
Average of the numbers: 4.00
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
	int num;

	std::cout << "For how many numbers do you want to enter? ";
	std::cin >> num;
	
	std::cout << "Write the data to Numbers.txt file\n";

	int counter = 1;
	int user_input;
	float sum;
		
	std::ofstream my_file;
	my_file.open("Numbers.txt");
	do {
		std::cout << "Enter the number " << counter << ": ";
		std::cin >> user_input;
		my_file << user_input << "\n";
		sum += user_input;
		counter++;
	} while(counter < num+1);
	my_file.close();
	
	float average = sum / num;

	std::cout << "Data written to Numbers.txt\n";
       	std::cout << "-----The end for entering data-----\n";	

	std::string file_name;
	std::cout << "Enter the file name: ";
	std::cin >> file_name;
	std::string line;

	std::ifstream my_file2 ("Numbers.txt");
	if(file_name == "Numbers.txt") {
		if(my_file2.is_open()) {
		 	while(std::getline (my_file2, line)) {
				std::cout << line << "\n";
				}
			my_file2.close();
		}
	}
	else {
		std::cout << "Error opening the file" << std::endl;
		std::cout << "Numbers of numbers: 0" << std::endl;
		std::cout << "Sum of numbers: 0.00" << std::endl;
		std::cout << "Average of the numbers: 0.00" << std::endl;
		return 0;
	}
	
	std::cout << std::fixed;

	std::cout << "Numbers of numbers: " << std::setprecision(2) << num << std::endl;
	std::cout << "Sum of numbers: " << std::setprecision(2) << sum << std::endl;
	std::cout << "Average of the numbers: " << std::setprecision(2) << average << std::endl;

	return 0;
}


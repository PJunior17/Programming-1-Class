/* Programmer Name: Phiron Hin Jr
 * File Name: phjA1_2.cpp
 * Summary: This code takes in a user input of total cookies and outputs a proportionate recipe for cooikes 
 * based on the fact that it takes 1.5 cups of sugar, 1 cup of butter, and 2.75 cups of flour to make 48 cookies.
 * Challenging: The most difficult part was to remember to multiply the proportion by the ingredients rather than 
 * divide. Another challenge was learning how to take user input in C++ 
 * Time: This took about 10 minutes to code
 * Revision: 5/28/24 Rev 1.0: Wrote code and description
 *
 * The complete Chart based on the requirements of the assignment example:
 * How many cookies do you want to bake? 24
 * To make 24 cookies you need 0.75 cups of sugar, 0.5 cups of butter, and 1.375 cups of flour to make 24 cookies.
 */

#include <iostream>

int main() {
	//declare and initialized variables based on the description of the recipe
	float sugar = 1.5;
	float butter = 1;
	float flour = 2.75;
	float base_num_cookies = 48;
	
	//delcared a variable for the user input to be saved and taking in the user input
	int total_cookies;
	std::cout << "How many cookies do you want to bake? ";
	std::cin >> total_cookies;
	
	//math to make a proportionate recipe based on the amount of cookies the user wants to make
	float proportion = total_cookies / base_num_cookies;
	sugar = sugar * proportion;
	butter = butter * proportion;
	flour = flour * proportion;
	
	//print the recipe the user asked for to the terminal
	std::cout << "To make " << total_cookies << " you should use ";
	std::cout << sugar << " cups of sugar, ";
	std::cout << butter << " cups of butter, and "; 
	std::cout << flour << " cups of flour.\n";
	return 0;
}

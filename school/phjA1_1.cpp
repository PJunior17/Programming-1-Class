/* Programmer Name: Phiron Hin Jr
 * File Name: phjA1_1.cpp
 * Summary: This code is meant to calculate the amount of gallons of paint needed to paint a 
 * 100ft x 6ft fence on both sides for two coats.
 * Challenging: The most difficult part was getting used to the verbosity of C++ because I mostly write in C
 * Time: This took a little less than 5 minutes to code
 * Revision: 5/28/24 Rev 1.0: Wrote code and description
 *
 * The complete Chart based on the requirements of the assignment example:
 * 7.05882 gallons of paint are needed to paint 2 coats on each side of a 100 x 6 foot fence.
 *
 */

#include <iostream>

int main() {
	//declare and initialized variables we will use
	float total_gallons;
	float paint_in_gallon = 340.0;
	float fence_two_sides = 1200.0;
	float coats = 2.0;
	
	//declared, initialized, and used previous variables to calculate the total gallons need
	float total_area_two_coats = fence_two_sides * coats;	
	total_gallons = total_area_two_coats / paint_in_gallon;
	
	//print the total amount of gallons to the terminal
	std::cout << total_gallons << " gallons of paint are needed to paint ";
	std::cout << "2 coats on each side a 100 x 6 foot fence.\n";

	return 0;

}

#include <iostream>
#include <cmath>

const float PI = 3.14159;
int number;
float area;

int main() {
	do {
		std::cout << "Geometry Calculator\n\n";
		std::cout << "1. Calculate the area of a Circle" << std::endl;
		std::cout << "2. Calculate the area of a Rectangle" << std::endl;
		std::cout << "3. Calculate the area of a Triangle" << std::endl;
		std::cout << "4. Quit\n\n"; 
	
		std::cout << "Enter a your choice (1-4): ";
		std::cin >> number;
		
		switch(number) {
			case(1):
				float radius;

				std::cout << "\nEnter the circle's radius: ";
				std::cin >> radius;
				
				if(radius < 0) {
					std::cout << "\nThe radius cannot be less than zero\n\n";
					return 0;
				}	

				area = PI * pow(radius, 2);
				std::cout << "\nThe area is " << area << "\n\n";
				std::cout << "---------------------------------------------------------------------\n\n";
				break;
			
			case(2):
				float length;
				float width;
			
				std::cout << "\nEnter the rectangle's length: ";
				std::cin >> length;
				if(length < 0) {
					std::cout << "\nThe length cannot be less than zero\n\n";
					return 0;
				}

				std::cout << "\nEnter the rectangle's width: ";
				std::cin >> width;
				if(width < 0) {
					std::cout << "\nThe width cannot be less than zero\n\n";
					return 0;
				}

				area = length * width;
				std::cout << "\nThe area is " << area << "\n\n";
				std::cout << "---------------------------------------------------------------------\n\n";
				break;

			case(3):
				float base;
				float height;

				std::cout << "\nEnter the triangle's base: ";
				std::cin >> base;
				if(base < 0) {
					std::cout << "\nThe base cannot be less than zero\n\n";
					return 0;
				}
				
				std::cout << "\nEnter the triangle's height: ";
				std::cin >> height;	
				if(height < 0) {
					std::cout << "\nThe height cannot be less than zero\n\n";
					return 0;
				}

				area = (base * height) / 2;
				std::cout << "\nThe area is " << area << "\n\n";
				std::cout << "---------------------------------------------------------------------\n\n";
				break;

			case(4):
				return 0;
				break;
		}

	} while(number >= 1 && number <= 4);

	if(number < 1 || number > 4) {
		std::cout << "Choice must be inbetween the range of 1 through 4" << std::endl;
	}
	
	return 0;
}

/* Programmer Name: Phiron Hin Jr
 * File Name: phjA3_1.cpp
 * Summary: this program will calculate the hospital bill of the user based on certain
 * variables. the user must state whether what kind of patient they were and then they 
 * will be prompted with charges to enter. once entered the hospital bill will be 
 * calculated and put into a file named hospital.txt
 * Challenging: the most challenging thing was to make sure to pass by reference rather
 * than pass by value. another challenge was to figure out how to make the validate 
 * function. 
 * Time: This took 1.5 hours to code
 * Revision: 6/16/24 Rev 1.0: Wrote code and description
 *
 * The complete Chart based on the requirements of the assignment example:
This program will compute patient hospital charges.
Enter I for inpatient or O for outpatient: I
Number of days in hospital: -1
Please enter a number greater than 0
Number of days in hospital: 2
Daily room rate: $4
Lab fees and other service charges: $-22
Please enter a number greater than 0
Lab fees and other service charges: $1
Medication charges: $2
The billing report has been written to the hospital.txt file
pjunior@DESKTOP-GP394GB:~/school/school/A3$ cat hospital.txt
**************************
Hospital Billing Statement
**************************
Room Charges    $ 8.00
Lab & Services  $ 1.00
Medication      $ 2.00
Total Charges   $ 11.00
**************************
 *
 */


#include <iostream>
#include <fstream>
#include <iomanip>

//GLOBAL Variables
int num_days;
float daily_rate;
float charge_services;
float charge_medication;

//Function Prototypes
bool validate_inputs(float);
void confirmed_inpatient(int&, float&, float&, float&);
void confirmed_outpatient(float&, float&);
float patient_charges(int, float, float, float);
float patient_charges(float, float);
void billing_statement(int, float, float, float, float);
void billing_statement(float, float, float);

int main() {
	std::cout << "This program will compute patient hospital charges.\n";
	char patient_type;
	std::cout << "Enter I for inpatient or O for outpatient: ";
	std::cin >> patient_type;
	
	//this is the main logic of the program. here we ask the patient type and then
	//based on that answer we get user input and give a billing report
	if(patient_type == 'I') {
		confirmed_inpatient(num_days, daily_rate, 
				    charge_services, charge_medication);
		float total_charges = patient_charges(num_days, daily_rate, 
				                      charge_services, charge_medication); 
		billing_statement(num_days, daily_rate, 
				  charge_services, charge_medication, 
				  total_charges);

	} else if(patient_type == 'O') {
		confirmed_outpatient(charge_services, charge_medication);
		float total_charges = patient_charges(charge_services, charge_medication);
		billing_statement(charge_services, charge_medication, total_charges);

	}
	
	return 0;
}

//boolean function to check if values inputed by the user are greater than 0
bool validate_data(float input) {
	return input > 0;
}	

//this function takes parameters by reference so we can save the user input.
//we will take the number of days, the daily rate of those days, the charge of services
//and the charge of medication
//we will also loop through every input if the user made a mistake and put a number 
//below 0
void confirmed_inpatient(int& num_days, float& daily_rate, 
		         float& charge_services, float& charge_medication) {	
	std::cout << "Number of days in hospital: ";
	do {
		std::cin >> num_days;
		if(!validate_data(num_days)) {
			std::cout << "Please enter a number greater than 0\n";
			std::cout << "Number of days in hospital: ";
		}
	} while(!validate_data(num_days));
	
	std::cout << "Daily room rate: $";
	do {
		std::cin >> daily_rate;
		if(!validate_data(daily_rate)) {
			std::cout << "Please enter a number greater than 0\n";
			std::cout << "Daily room rate: $";
		}
	} while(!validate_data(daily_rate));

	std::cout << "Lab fees and other service charges: $";
	do {
		std::cin >> charge_services;
		if(!validate_data(charge_services)) {
			std::cout << "Please enter a number greater than 0\n";
			std::cout << "Lab fees and other service charges: $";
		}
	} while(!validate_data(charge_services));

        std::cout << "Medication charges: $";
	do {
        	std::cin >> charge_medication;
		if(!validate_data(charge_medication)) {
			std::cout << "Please enter a number greater than 0\n";
			std::cout << "Medication charges: $";
		}
	} while(!validate_data(charge_medication));

	std::cout << "The billing report has been written to the hospital.txt file\n";
}


//this function takes parameters by reference so we can save the user input.
//it will take the charge of services and the charge of medicaiton.
//we will also loop every input in case the user inputs a value lower than 0
void confirmed_outpatient(float& charge_services, float& charge_medication) {
	std::cout << "Lab fees and other service charges: $";
	do {
		std::cin >> charge_services;
		if(!validate_data(charge_services)) {
			std::cout << "Please enter a number greater than 0\n";
			std::cout << "Lab fees and other service charges: $";
		}
	} while(!validate_data(charge_services));

        std::cout << "Medication charges: $";
	do {
        	std::cin >> charge_medication;
		if(!validate_data(charge_medication)) {
			std::cout << "Please enter a number greater than 0\n";
			std::cout << "Medication charges: $";
		}
	} while(!validate_data(charge_services));

	std::cout << "The billing report has been written to the hospital.txt file\n";
}

//here we take all the user inputed data and return the total charges so we can 
//put it in the bill
float patient_charges(int num_days, float daily_rate, float charge_services, float charge_medication) {
	float total_charges;
	float room_charges = num_days * daily_rate;
	total_charges = room_charges + charge_services + charge_medication;
	return total_charges;
}

//here we take all the user inputed data and return the total charges so we can 
//put it in the bill
float patient_charges(float charge_services, float charge_medication) {
	float total_charges = charge_services + charge_medication;
	return total_charges;
}

//here we will put the user's bill inside of a file called hospital.txt
void billing_statement(int num_days, float daily_rate, float charge_services, float charge_medication, float total_charges) {
	std::ofstream bill;
	bill.open("hospital.txt");
	bill << "**************************\n";
	bill << "Hospital Billing Statement\n";
	bill << "**************************\n";
	bill << "Room Charges    $ " << std::setprecision(2) << std::fixed << num_days * daily_rate << std::endl;
	bill << "Lab & Services  $ " << std::setprecision(2) << charge_services << std::endl;
	bill << "Medication      $ " << std::setprecision(2) << charge_medication << std::endl;
	bill << "Total Charges   $ " << std::setprecision(2) << total_charges << std::endl;
	bill << "**************************\n";
	bill.close();

}


//here we will put the user's bill inside of a file called hospital.txt
void billing_statement(float charge_services, float charge_medication, float total_charges) {
	std::cout << std::fixed;
	std::ofstream bill;
	bill.open("hospital.txt");
	bill << "**************************\n";
	bill << "Hospital Billing Statement\n";
	bill << "**************************\n";
	bill << "Medication      $ " << std::setprecision(2) << charge_medication << std::endl;
	bill << "Total Charges   $ " << std::setprecision(2) << total_charges << std::endl;
	bill << "**************************\n";
	bill.close();
}


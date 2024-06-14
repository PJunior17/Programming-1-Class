#include <iostream>
#include <fstream>
#include <string>

//GLOBALS
int num_days;
float daily_rate;
float charge_services;
float charge_medication;

//Function Prototypes
float validate_inputs(float);
float patient_charges(int, float, float, float);
float patient_charges(float, float);
void confirmed_inpatient();
void confirmed_outpatient();

int main() {
	confirmed_inpatient();
	return 0;
}

void confirmed_inpatient() {
		std::cout << "Number of days in hospital: ";
		std::cin >> num_days;

		std::cout << "Daily room rate: $";
		std::cin >> daily_rate;

		std::cout << "Lab fees and other service charges: $";
		std::cin >> charge_services;

		std::cout << "Medication charges: $";
		std::cin >> charge_medication;
}


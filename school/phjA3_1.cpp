#include <iostream>
#include <fstream>
#include <string>

float validate_inputs(float);
float patient_charges(int, float, float, float);
float patient_charges(float, float);

int main() {
	int num_days;
	float daily_rate;
	float charge_services;
	float charge_medication;

	string patient_type;
	std::cout << "inpatient or outpatient? ";
	std::cin >> patient_type;

	if(patient_type == "inpatient") {
		std::cout << "Number of days in hospital: ";
		std::cin >> num_days;

		std::cout << "Daily room rate: $";
		std::cin >> daily_rate;

		std::cout << "Lab fees and other service charges: $";
		std::cin >> charge_services;

		std::cout << "Medication charges: $";
		std::cin >> charge_medication;
	}

	if(patient_type == "outpatient") {
		std::cout << "Lab fees and other service charges: $";
		std::cin >> charge_services;

		std::cout << "Medication charges: $";
		std::cin >> charge_medication;
	}

	return 0;
}


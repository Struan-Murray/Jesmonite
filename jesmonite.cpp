#include <iostream>
#include <cmath>

int main() {
	// Constants for AC100
	const float powder_liquid_ratio = 2.5 / 1.0;
	const float wet_density = 1.75; // Advised 1.75 wet mix density from Jesmonite Engineers. Compared to water
	const float waste_percentage = 0.05; // Percentage weight wasted
	const float waste_grams = 3; // Constant weight wasted
	const float min_water_weight = 20; // Minimum calculatable mass in grams

	// Calculated Constants
	const float total_parts = powder_liquid_ratio + 1.0;
	const float powder_fraction = powder_liquid_ratio / total_parts;
	const float liquid_fraction = 1.0 / total_parts;
	const float powder_conversion = powder_fraction * wet_density;
	const float liquid_conversion = liquid_fraction * wet_density;

	// Variables
	float water_weight = 0;
	float powder_weight = 0;
	float liquid_weight = 0;
	float mix_cup_area = 0;

	// Main Program

	while(true){



	std::cout << "How much water does the mould hold? (grams) ";
	std::cin >> water_weight;

	// DEV
	mix_cup_area = 4.836 * std::pow(water_weight,2.0/3.0); // Area of a sphere that would contain the liquid
	std::cout << mix_cup_area << "cm2\n\n";
	// DEV

	if(water_weight < min_water_weight)
	{
		water_weight = min_water_weight;
	}

	water_weight = water_weight * (1 + waste_percentage) + waste_grams;

	powder_weight = water_weight * powder_conversion;
	liquid_weight = water_weight * liquid_conversion;

	std::cout << "Powder: " << std::floor(powder_weight) << " grams\n";
	std::cout << "Liquid: " << std::ceil (liquid_weight) << " grams\n\n";



	}
	return 0;
}

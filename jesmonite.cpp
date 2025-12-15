#include <iostream>

int main() {
    // All regards to AC100
    const float powder_liquid_ratio = 2.5 / 1.0;
    const float wet_density = 1.75; // Advised 1.75 wet mix density from Jesmonite Engineers. Compared to water
    
    float total_parts = powder_liquid_ratio + 1.0;
    
    std::cout << "How much water fills the mould (grams)? ";
    
    float water_weight = 0;
    std::cin >> water_weight;
    
    if(water_weight < 4)
    {
        water_weight = 4;
    }
    
    float powder_weight = water_weight / total_parts * powder_liquid_ratio;
    float liquid_weight = water_weight / total_parts;
    
    std::cout << "Powder: " << powder_weight << " grams\n";
    std::cout << "Liquid: " << liquid_weight << " grams\n";
    
    return 0;
}

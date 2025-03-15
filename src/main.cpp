#include "CargoTransportation.h"
#include <iostream>

int main() {
    try
    {    
        CargoCreator create(1200, 352);
        
        for(int i = 0; i < 4; ++i) {
            std::cout << std::endl;
            create.calculateCargoPrice(i);
        }
        std::cout << "\n\n";
        for(int i = 0; i < 4; ++i) {
            std::cout << std::endl;
            create.outputTransportInformation(i);
        }   
    }
    catch(const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << '\n';
    }
    
    return 0;
}
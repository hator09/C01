#include "Harl.hpp"

int main() {
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    
    // Prueba extra para un nivel no existente
    harl.complain("ANYTHING_ELSE");

    return 0;
}
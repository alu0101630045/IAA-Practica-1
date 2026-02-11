#include "../lib/DistribucionConjunta.h"
#include "../lib/Functions.h"

int main() {
    std::pair<DistribucionConjunta, int> distribucion;
    distribucion = MenuPrincipal();
    ejecutar_simulacion(distribucion.first.get_p(), distribucion.second);
    return 0;
}
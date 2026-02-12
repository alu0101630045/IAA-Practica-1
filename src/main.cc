#include "../lib/DistribucionConjunta.h"
#include "../lib/Functions.h"

int main(int argc, char* argv[]) {
    std::pair<DistribucionConjunta, int> distribucion;
    std::string fichero_entrada = argv[1];
    distribucion = MenuPrincipal(fichero_entrada);
    ejecutar_simulacion(distribucion.first.get_p(), distribucion.second);
    return 0;
}
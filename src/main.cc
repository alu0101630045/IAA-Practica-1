#include "../lib/DistribucionConjunta.h"
#include "../lib/Functions.h"

int main() {
    int n;
    std::cout << ">>> Cantidad total de variables binarias: ";
    std::cin >> n;

    DistribucionConjunta dc(n);

    std::cout << "Seleccione metodo de carga:\n1. Archivo CSV (distribucion.csv)\n2. Generacion Aleatoria\nOpcion: ";
    int opcion;
    std::cin >> opcion;

    if (opcion == 1) {
        if (!dc.cargarDesdeCSV("inputs/input_5var.csv")) {
            std::cout << "No se pudo leer el archivo. Usando datos aleatorios...\n";
            dc.generarAleatoria();
        }
    } else {
        dc.generarAleatoria();
    }

    dc.imprimirArrayp(); 

    int maskC = 0; // Máscara de variables condicionadas
    int valC = 0;  // Valor de las variables condicionadas
    int maskI = 0; // Máscara de variables de interés
    
    int n_condicionadas, n_interes;

    std::cout << "\n=== Seleccion de Variables ===" << std::endl;

    std::cout << "¿Cuantas variables estan condicionadas (E)? ";
    std::cin >> n_condicionadas;

    for (int i = 0; i < n_condicionadas; ++i) {
        int idx, val;
        std::cout << "  [Condicion " << i + 1 << "] Indice (1-" << n << "): ";
        std::cin >> idx;
        std::cout << "  [Condicion " << i + 1 << "] Valor (0 o 1): ";
        std::cin >> val;
        int bit_pos = idx - 1; 
        maskC |= (1 << bit_pos); 
        if (val == 1) {
            valC |= (1 << bit_pos); 
        }
    }

    std::cout << "\n¿Cuantas variables son de interes (Y)? ";
    std::cin >> n_interes;

    for (int i = 0; i < n_interes; ++i) {
        int idx;
        std::cout << "  [Interes " << i + 1 << "] Indice (1-" << n << "): ";
        std::cin >> idx;

        int bit_pos = idx - 1;
        maskI |= (1 << bit_pos); 
    }

    std::cout << "MaskC: " << maskC << std::endl;
    std::cout << "valC: " << valC << std::endl;
    std::cout << "MaskI: " << maskI << std::endl;

    std::vector<double> resultado = prob_cond_bin(dc.get_p(), n, maskC, valC, maskI);

    std::cout << "\n--- Resultados ---" << std::endl;
    for (int i = 0; i < resultado.size(); ++i) {
        std::cout << "Indice " << i << ": " << resultado[i] << std::endl;
    }

    ejecutar_simulacion(dc.get_p(), n);
    
    return 0;
}
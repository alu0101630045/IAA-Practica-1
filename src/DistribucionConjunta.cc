#include "../lib/DistribucionConjunta.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <random>

/// @brief Constructor de la clase DistribucionConjunta
/// @param n Número de variables aleatorias
DistribucionConjunta::DistribucionConjunta(int n) : n_vars(n) {
    p.resize(1 << n, 0.0);
}

/// @brief Carga la distribución conjunta desde un archivo CSV
/// @param filename 
/// @return true si se cargó correctamente, false en caso contrario 
bool DistribucionConjunta::cargarDesdeCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string line;
    double suma = 0.0;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string mask, prob_str;
        
        if (std::getline(ss, mask, ',') && std::getline(ss, prob_str)) {
            try {
                int index = std::stoi(mask, nullptr, 2);
                double prob = std::stod(prob_str);
                p[index] = prob;
                suma += prob;
            } catch (...) { continue; }
        }
    }
    if (suma > 0) {
        for (double& val : p) val /= suma;
    }
    return true;
}

/// @brief Genera una distribución conjunta aleatoria
void DistribucionConjunta::generarAleatoria() {
    static bool init = false;
    if (!init) { std::srand(std::time(NULL)); init = true; }
    for (double& val : p) val = 0.0;
    for (int i = 0; i < 100; ++i) {
        int idx = std::rand() % p.size();
        p[idx] += 1.0;
    }
    for (double& val : p) val /= 100.0;
}

/// @brief Imprime el array p para depuración
void DistribucionConjunta::imprimirArrayp() const { 
        for (size_t i = 0; i < p.size(); ++i) {
            std::cout << "p[" << i << "] = " << p[i] << std::endl;
        }
    }
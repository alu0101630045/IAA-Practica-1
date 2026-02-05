#include <iostream>

#include "../lib/Inferencia.h"

int main() {
  std::ifstream fichero_entrada("inputs/input1.csv");
  if (!fichero_entrada.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo de entrada." << std::endl;
    return 1; 
  }
  Inferencia inferencia_uno(fichero_entrada);
  
  std::vector<double> probabilidades = inferencia_uno.get_probabilidades();
  
  for (int i = 0; i < probabilidades.size(); i++) {
    std::cout << probabilidades[i]<< '\n';
  }
  return 0;
}
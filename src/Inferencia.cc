#include <string>
#include <sstream>

#include "../lib/Inferencia.h"


Inferencia::Inferencia(std::ifstream& fichero_csv) {
  int tamaño_total = 0;
  fichero_csv >> tamaño_total;
  int tam = 0;
  fichero_csv >> tam;
  probabilidades_.resize(tamaño_total);

  int variables_indice = 0;
  double probabilidad = 0.0;
  std::string input = "";
  std::string variables_binarias_string = "";
  int i = 0;
  
  while (i < tamaño_total) {
    fichero_csv >> variables_binarias_string;
    fichero_csv >> probabilidad;

    variables_indice = std::stoi(variables_binarias_string, nullptr, 2);
    probabilidades_[variables_indice] = probabilidad;
    i++;
    
  }
}
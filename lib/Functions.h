#include <vector>
#include <iostream>
#include <cmath>

/**
 * @brief Versión moderna usando std::vector
 * @param p      Vector de la distribución conjunta (pasado por referencia constante para no copiarlo)
 * @param N      Número de variables
 * @param maskC  Máscara de condición
 * @param valC   Valor de condición
 * @param maskI  Máscara de interés
 * @return std::vector<double> Vector con la distribución condicional
 */
std::vector<double> prob_cond_bin(const std::vector<double>& p, int N, int maskC, int valC, int maskI) {
  int n_interes = 0;
  int temp = maskI;
  while (temp > 0) {
    if (temp & 1) n_interes++;
    temp >>= 1;
  }
  std::vector<double> result(1 << n_interes, 0.0);

  double prob_evidencia = 0.0;
  int size_p = p.size();

  for (int k = 0; k < size_p; ++k) {
    if ((k & maskC) == valC) {
      int idx_res = 0;
      int current_pos = 0;

      for (int bit = 0; bit < N; ++bit) {
        if ((maskI >> bit) & 1) {
          if ((k >> bit) & 1) {
            idx_res |= (1 << current_pos);
          }
          current_pos++;
        }
      }

      result[idx_res] += p[k];
      prob_evidencia += p[k];
    }
  }

  if (prob_evidencia > 0) {
    for (double& val : result) {
      val /= prob_evidencia;
    }
  } else {
    std::cerr << "Advertencia: Probabilidad de evidencia es 0." << std::endl;
  }

  return result;
}
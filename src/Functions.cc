#include "../lib/Functions.h"

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

/// @brief Ejecuta una simulación con un número de variables especificado y 
///        número aleatorio de variables de interés y condicionadas.
/// @param p 
/// @param N 
void ejecutar_simulacion(const std::vector<double>& p, int N) {
  std::cout << "\n=== Iniciando Simulacion de Rendimiento (Funcion Suelta) ===\n";
  std::cout << "N_Vars,N_Interes,N_Condicionadas,Tiempo(s)\n";
  std::vector<int> indices(N);
  for (int i = 0; i < N; ++i) {
    indices[i] = i;
  }

  for (int ni = 1; ni <= N; ++ni) {
    for (int nc = 0; nc <= (N - ni); ++nc) {
      for (int i = N - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(indices[i], indices[j]);
      }
      int maskI = 0;
      int maskC = 0;
      int valC = 0;

      for (int i = 0; i < ni; ++i) {
        maskI |= (1 << indices[i]);
      }

      for (int i = 0; i < nc; ++i) {
        int idx = indices[ni + i]; 
        maskC |= (1 << idx);
        if (std::rand() % 2 == 1) {
          valC |= (1 << idx);
        }
      }
      
      auto start = std::chrono::high_resolution_clock::now();
      std::vector<double> temp = prob_cond_bin(p, N, maskC, valC, maskI);
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> elapsed = end - start;
      std::cout << N << "," << ni << "," << nc << "," 
                << std::fixed << std::setprecision(6) << elapsed.count() << "\n";
    }
  }
  std::cout << "=== Fin de Simulacion ===\n";
}

std::pair<DistribucionConjunta, int> MenuPrincipal() {
  std::pair<DistribucionConjunta, int> distribucion;
  int n;
  std::cout << ">>> Cantidad total de variables binarias: ";
  std::cin >> n;

  DistribucionConjunta dc(n);

  std::cout << "Seleccione metodo de carga:\n1. Archivo CSV (distribucion.csv)\n2. Generacion Aleatoria\nOpcion: ";
  int opcion;
  std::cin >> opcion;

  if (opcion == 1) {
    if (!dc.cargarDesdeCSV("inputs/input.csv")) {
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
  distribucion.first = dc;
  distribucion.second = n;
  return distribucion;
}
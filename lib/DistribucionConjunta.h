#ifndef DISTRIBUCION_CONJUNTA_H
#define DISTRIBUCION_CONJUNTA_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

class DistribucionConjunta {
  public:
    DistribucionConjunta(int n);
    bool cargarDesdeCSV(const std::string& filename);
    void generarAleatoria();
    void imprimirConfiguracion(const std::map<int, int>& config) const;
    void imprimirArrayp() const;

  private:
    int n_vars;
    std::vector<double> p; 
    
};

#endif
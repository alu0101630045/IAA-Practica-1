#ifndef INFERENCIA_H_
#define INFERENCIA_H_

#include <vector>
#include <fstream>
#include <iostream>

class Inferencia {
  public:
    Inferencia(std::ifstream& fichero_csv);
    std::vector<double> get_probabilidades() {return probabilidades_;}

  private:
  std::vector<double> probabilidades_;
};

#endif //INFERENCIA_H_
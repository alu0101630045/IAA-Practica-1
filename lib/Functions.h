#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm> 
#include <chrono>    
#include <cstdlib>   
#include <iomanip>   

std::vector<double> prob_cond_bin(const std::vector<double>& p, int N, int maskC, int valC, int maskI);
void ejecutar_simulacion(const std::vector<double>& p, int N);

#endif
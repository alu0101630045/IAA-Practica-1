# IAA-Practica-1

## Descripción

Este repositorio contiene la implementación de la Práctica 1 de la asignatura de Inteligencia Artificial Avanzada (IAA).

## Objetivo

# Práctica 1: Cálculo de Probabilidades con Variables Binarias

Este proyecto implementa una herramienta en C++ para el cálculo eficiente de probabilidades condicionales sobre un conjunto de variables binarias. El programa procesa una distribución de probabilidad conjunta proporcionada mediante un archivo CSV y permite realizar consultas de inferencia.

## Descripción del Proyecto

El objetivo principal de la aplicación es calcular la probabilidad posterior P(Y | E) de un subconjunto de variables de interés Y, dada una evidencia E sobre otro subconjunto de variables condicionadas.

El algoritmo emplea operaciones a nivel de bits (bitwise operations) para filtrar, marginalizar y compactar las tablas de probabilidad. Este enfoque optimiza el uso de memoria y reduce significativamente el tiempo de ejecución en comparación con iteraciones convencionales sobre estructuras de datos complejas.

## Estructura del Proyecto

La organización de directorios del proyecto es la siguiente:

```text
.
├── src/                    # Código fuente (.cc)
│   ├── main.cc             # Punto de entrada principal
│   └── DistribucionConjunta.cc
├── include/                # Cabeceras (.h)
│   └── DistribucionConjunta.h
├── inputs/                 # Archivos CSV de entrada (distribuciones)
├── outputs/                # Resultados de simulaciones
├── Makefile                # Archivo de compilación automatizada
└── README.md               # Documentación del proyecto

```

## Requisitos

- gcc

## Instalación

```bash
git clone https://github.com/alu0101630045/IAA-Practica-1.git
cd IAA-Practica-1
make
```

## Uso

./p01_binary <filename>

## Resultados

Compruebe los resultados de las simulaciones en el directorio outputs/

## Autores

- **Pablo García de los Reyes**
- **César Navarro Santos**
# Práctica 1 Inferencia Condicional en Distribuciones Discretas Binarias

Este proyecto implementa una herramienta en C++ para calcular distribuciones de probabilidad condicionales a partir de una distribución conjunta de variables binarias. Utiliza técnicas de marginalización para inferir probabilidades $P(Y|E)$.

## Información del Proyecto

**Asignatura:** Inteligencia Artificial Avanzada  
**Fecha:** [05/02/2026]

**Autores:**
* Pablo García de los Reyes
* César Navarro Santos

---

## Funcionalidades

1.  **Carga de Distribución Conjunta:**
    * **Desde CSV:** Lectura de archivos con formato `máscara,probabilidad`.
    * **Aleatoria:** Generación automática de probabilidades. Se utilizan 2 decimales (posibilidad de usar más pero no se especifica en el guión y así evitamos residuos)

2.  **Selección de variables**
    * **Variables condicionadas** en maskC se crea la máscara para las variables condicionadas y se actualizan los valores en valC
    * **Variables de interés** en maskI se crea la mácara para las variables de interés y las demás se consideran marginadas.

3.  **Carga de las probabilidades en un array de probabilidades**
    * Cada máscara representa un número en binario, el número representado en binario será el índice para la probabilidad en el array de probabilidades.

---

## Estructura de Archivos

* `main.cc`: Punto de entrada del programa. Gestiona la interacción con el usuario.
* `DistribucionConjunta.h`: Definición de la clase y cabeceras.
* `DistribucionConjunta.cc`: Implementación de la lógica.
* `input1.csv` Archivo de entrada de datos.

---

## Compilación y Ejecución

El código no requiere librerías externas, solo un compilador estándar de C++.

### Compilación (Linux)
```bash
make clean
make
´´´
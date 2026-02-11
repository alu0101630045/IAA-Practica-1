# 1. Compilador y Flags
CXX = g++
# -I./lib sigue siendo clave para que encuentre tus .h
CXXFLAGS = -std=c++17 -Wall -g -I./lib

# 2. Definición de directorios
SRC_DIR = src
OBJ_DIR = obj

# 3. Nombre del ejecutable
TARGET = p01_binary

# 4. Archivos fuente
# Listamos los archivos que están dentro de la carpeta src
SRCS = $(SRC_DIR)/main.cc $(SRC_DIR)/Functions.cc $(SRC_DIR)/DistribucionConjunta.cc

# 5. Generación de lista de objetos
# Aquí ocurre la magia: cambia "src/%.cc" por "obj/%.o"
OBJS = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRCS))

# --- Reglas ---

all: $(TARGET)

# Regla para crear el ejecutable final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar cada objeto y guardarlo en obj/
# El comando '@mkdir -p $(OBJ_DIR)' crea la carpeta si no existe antes de compilar
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza: ahora borramos la carpeta obj entera
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
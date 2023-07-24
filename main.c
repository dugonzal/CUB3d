#include <stdio.h>
#include <stdlib.h>

void liberarArrayDeCadenas(char **str, int numElementos) {
    for (int i = 0; i < numElementos; i++) {
        free(str[i]); // Liberar cada cadena individual
        str[i] = NULL; // Establecer el puntero a NULL para evitar problemas de acceso después de liberar
    }
    free(str); // Liberar el array de punteros a cadenas
}

int main() {
    int numElementos = 3;
    char **str = (char **)malloc(numElementos * sizeof(char *));

    // Asignar memoria para cada cadena individual y copiar el contenido
    str[0] = strdup("Hola");
    str[1] = strdup("Mundo");
    str[2] = strdup("Ejemplo");

    // Liberar el array de cadenas
    liberarArrayDeCadenas(str, numElementos);

    return 0;
}


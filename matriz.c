#include <stdio.h>
#include <stdlib.h>

int main()
{
    int capacidad_asientos;
    printf("Introduce la capacidad de asientos del camión: ");
    scanf("%d", &capacidad_asientos);

    // Calcular el número de filas
    int num_filas = capacidad_asientos / 4;

    // Crear una matriz de 'num_filas' filas y 4 columnas
    int **matriz = malloc(num_filas * sizeof(int *));
    for (int i = 0; i < num_filas; i++)
    {
        matriz[i] = malloc(4 * sizeof(int));
    }

    // Inicializar la matriz con ceros (falso)
    for (int i = 0; i < num_filas; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = 0;
        }
    }

    // Imprimir la matriz
    printf("  ");
    for (int i = 0; i < num_filas; i++)
    {
        if (i < 10)
        {
            printf("  %d", i + 1);
        }
        else
        {
            printf(" %d", i + 1);
        }
    }
    printf("\n  ");
    for (int i = 0; i < num_filas; i++)
    {
        printf("___");
    }
    printf("\n");
    for (int j = 0; j < 4; j++)
    {
        printf("%d | ", j + 1);
        for (int i = 0; i < num_filas; i++)
        {
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Liberar la memoria
    for (int i = 0; i < num_filas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

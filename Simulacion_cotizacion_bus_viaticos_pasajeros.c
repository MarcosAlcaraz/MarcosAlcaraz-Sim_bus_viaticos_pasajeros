#include <stdio.h>
#include <stdlib.h>

int main()
{
    int capacidad_asientos = 0, numero_invitados = 0, numero_ocupantes = 0, numero_viaticos = 0, numero_viaticos_ocupantes = 0;
    int fila, columna;
    float costo_viaje, precio_viaticos, precio_boleto_camion;

    // Presentación de programa
    printf("Practica 4\nSeccion D07\nBarba Ivan\n\n");

    // Se piden los datos y se validan
    do
    {
        printf("Capacidad de asientos del Camion (Multiplo de 4): ");
        scanf("%d", &capacidad_asientos);

        if (capacidad_asientos < 4)
        {
            printf("\nLa capacidad de asientos debe ser mayor a 4\n\nINTENTALO DE NUEVO\n");
            system("pause");
            system("cls");
        }
    } while (capacidad_asientos < 4);

    do
    {
        printf("\nPrecio de viaticos: ");
        scanf("%f", &precio_viaticos);

        if (precio_viaticos < 0)
        {
            printf("\nEl precio de viaticos debe ser mayor o igual a cero\n\nINTENTALO DE NUEVO\n");
            system("pause");
            system("cls");
        }
    } while (precio_viaticos < 0);

    do
    {
        printf("\nPrecio de boleto de camion: ");
        scanf("%f", &precio_boleto_camion);

        if (precio_boleto_camion < 0)
        {
            printf("\nEl precio del boleto del camion debe ser mayor o igual a cero\n\nINTENTALO DE NUEVO\n");
            system("pause");
            system("cls");
        }
    } while (precio_boleto_camion < 0);

    do
    {
        printf("\nNumero de invitados: ");
        scanf("%d", &numero_invitados);

        if (numero_invitados > capacidad_asientos && numero_invitados > 1)
        {
            printf("\nEl numero de invitados debe ser menor o igual a la capacidad de asientos y mayor a 1\n\nINTENTALO DE NUEVO\n");
            system("pause");
            system("cls");
        }
    } while (numero_invitados > capacidad_asientos && numero_invitados > 0);

    do
    {
        printf("\nNumero de invitados que compraran viaticos: ");
        scanf("%d", &numero_viaticos);

        if (numero_viaticos > numero_invitados)
        {
            printf("\nLa cantidad de viaticos debe ser menor o igual a la cantidad de invitados\n\nINTENTALO DE NUEVO\n");
            system("pause");
            system("cls");
        }
    } while (numero_viaticos > numero_invitados);

    // Crear una matriz de 'num_filas' filas y 4 columnas (representando 2 asientos de cada lado del camion)
    int num_filas = capacidad_asientos / 4;
    int matriz[num_filas][4];

    // Inicializar la matriz con ceros (falso/asiento_desocupado)
    for (int i = 0; i < num_filas; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = 0;
        }
    }

    // Pide "numero_invitados" veces el asiento de un invitado a ocupar
    for (int i = 0; i < numero_invitados; i++)
    {
        // Ciclo que valida si el asiento está o no disponible
        do
        {
            system("cls");
            printf("ASIENTOS DISPONIBLES\n\n");

            // Imprimir la matriz al usuario
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

            // Pide la fila y columna del asiento que se desea ocupar por el invitado y valida la entrada
            printf("\n\nFila y columna del asiento para el invitado %d", i + 1);

            do
            {
                printf("\nFila: ");
                scanf("%d", &fila);

                if (fila < 1 && fila > num_filas)
                {
                    printf("\nLa fila debe estar dentro del rango de la matriz de arriba");
                }
            } while (fila < 1 && fila > num_filas);

            do
            {
                printf("\nColumna: ");
                scanf("%d", &columna);

                if (columna < 1 && columna > 4)
                {
                    printf("\nLa columna debe estar dentro del rango de la matriz de arriba");
                }
            } while (columna < 1 && columna > 4);

            if (matriz[columna - 1][fila - 1] == 1)
            {
                printf("\nEste asiento ya está ocupado\nINTENTELO DE NUEVO\n\n");
                system("pause");
            }
        } while (matriz[columna - 1][fila - 1] == 1);

        matriz[columna - 1][fila - 1] = 1;
        system("cls");
    }

    // Evalua si el camion esta o no lleno antes de comprar asientos extras
    if (numero_invitados < capacidad_asientos)
    {
        // Pide los asientos que se comprarán para otras personas
        do
        {
            system("cls");
            printf("\nNumero de boletos de bus a comprar para ocupantes extras [ Quedan %d asientos disponibles ]: ", capacidad_asientos - numero_invitados);
            scanf("%d", &numero_ocupantes);

            if ((numero_ocupantes + numero_invitados) > capacidad_asientos)
            {
                printf("\nEl no debe superar la cantidad de asientos del camion sumados con los de los invitados\nINTENTALO DE NUEVO\n");
                system("pause");
            }
        } while (numero_ocupantes + numero_invitados > capacidad_asientos);
        // Si no hay ocupantes a sumar al bus, se negará la condición para acceder a la selección de asientos
        if (numero_ocupantes == 0)
        {
            numero_ocupantes--;
        }
        else
        {
            // Define cuántos viáticos se comprarán
            do
            {
                printf("\nNumero de ocupantes extras que compraran viaticos: ");
                scanf("%d", &numero_viaticos_ocupantes);

                if (numero_viaticos_ocupantes > numero_ocupantes)
                {
                    printf("\nLa cantidad de viaticos debe ser menor o igual a la cantidad de ocupantes\n\nINTENTALO DE NUEVO\n");
                    system("pause");
                    system("cls");
                }
            } while (numero_viaticos_ocupantes > numero_ocupantes);
        }

        // Repite el ciclo "numero_ocupantes" veces
        for (int i = 0; i < numero_ocupantes; i++)
        {
            // Ciclo que valida si el asiento está o no disponible
            do
            {
                system("cls");
                printf("ASIENTOS DISPONIBLES PARA COMPRAR PARA OCUPANTES EXTRAS\n\n");

                // Imprimir la matriz al usuario
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

                // Pide la fila y columna del asiento que se desea ocupar por el invitado y valida la entrada
                printf("\n\nFila y columna del asiento para comprar del ocupante %d", i + 1);

                do
                {
                    printf("\nFila: ");
                    scanf("%d", &fila);

                    if (fila < 1 && fila > num_filas)
                    {
                        printf("\nLa fila debe estar dentro del rango de la matriz de arriba");
                    }
                } while (fila < 1 && fila > num_filas);

                do
                {
                    printf("\nColumna: ");
                    scanf("%d", &columna);

                    if (columna < 1 && columna > num_filas)
                    {
                        printf("\nLa columna debe estar dentro del rango de la matriz de arriba");
                    }
                } while (columna < 1 && columna > num_filas);

                if (matriz[columna - 1][fila - 1] == 1 || matriz[columna - 1][fila - 1] == 2)
                {
                    printf("\nEste asiento ya está ocupado\nINTENTELO DE NUEVO\n\n");
                    system("pause");
                }
            } while (matriz[columna - 1][fila - 1] == 1 || matriz[columna - 1][fila - 1] == 2);

            matriz[columna - 1][fila - 1] = 2;
            system("cls");
        }
    }
    else
    {
        system("cls");
        printf("El camion esta lleno. No hay espacio para comprar asientos para otros ocupantes.\n");
        system("pause");
    }

    // Calcula costo del viaje
    float total = (numero_ocupantes * precio_boleto_camion) + ((numero_viaticos + numero_viaticos_ocupantes) * precio_viaticos);
    system("cls");

    // Imprimir la matriz al usuario
    printf("ASIENTOS OCUPADOS\n0: Vacio\n1: Invitado\n2: Ocupado\n\n  ");
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

    printf("Practica 4\nSeccion D07\nBarba Ivan\n\n");
    printf("PRECIO DEL VIAJE");
    printf("\n%d boletos camion: %.2f", numero_ocupantes, (numero_ocupantes * precio_boleto_camion));
    printf("\n%d viaticos      : %.2f", (numero_viaticos + numero_viaticos_ocupantes), ((numero_viaticos + numero_viaticos_ocupantes) * precio_viaticos));
    printf("\nTOTAL            : %.2f\n\n", total);

    system("pause");

    return 0;
}
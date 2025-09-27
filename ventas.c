//Trabajo en grupo Romina Gomez y Hugo Yepez

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int id, stock = 0, opcion, cantidad;
    char nombre[50];
    float precio, ganancias = 0, descuento, totalVenta;

   
    printf("=== REGISTRO DEL PRODUCTO ===\n");
    printf("Ingrese ID del producto: ");
    scanf("%d", &id);
    getchar(); 

    printf("Ingrese nombre del producto: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    printf("Ingrese cantidad en stock: ");
    scanf("%d", &stock);

    printf("Ingrese precio unitario: ");
    scanf("%f", &precio);

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Consultar informacion del producto\n");
        printf("4. Ver ganancias acumuladas\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese cantidad a vender: ");
                scanf("%d", &cantidad);

                if (cantidad <= 0) {
                    printf("Error: La cantidad debe ser positiva.\n");
                } else if (cantidad > stock) {
                    printf("Error: No hay suficiente stock disponible.\n");
                } else {
                    printf("Ingrese descuento en porcentaje (0 si no aplica): ");
                    scanf("%f", &descuento);

                    if (descuento < 0 || descuento > 100) {
                        printf("Descuento invalido. Se aplicara 0%%.\n");
                        descuento = 0;
                    }

                    totalVenta = cantidad * precio * (1 - descuento / 100);
                    stock -= cantidad;
                    ganancias += totalVenta;

                    printf("Venta realizada con exito.\n");
                    printf("Total de la venta: $%.2f\n", totalVenta);
                }
                break;

            case 2:
                printf("Ingrese cantidad a reabastecer: ");
                scanf("%d", &cantidad);

                if (cantidad <= 0) {
                    printf("Error: La cantidad debe ser positiva.\n");
                } else {
                    stock += cantidad;
                    printf("Reabastecimiento realizado. Stock actual: %d\n", stock);
                }
                break;

            case 3:
                printf("\n=== INFORMACION DEL PRODUCTO ===\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: $%.2f\n", precio);
                break;

            case 4:
                printf("Ganancias acumuladas: $%.2f\n", ganancias);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

    } while(opcion != 5);

    return 0;
}

#include <stdio.h>
#include "funciones.h"
#include "mi_string.h"

// del tp1 lo que integraba al do-while 

void cargar_articulo(articulos_t articulos[]) {
    int sucursal, i = 0, opc;
    char articulo[90];
    int articulo_index;

    do {
     printf("Ingrese la descripcion del articulo: ");
     scanf("%s", articulo);

        i = 0;
        while (articulos[i].descripcion[0] && mi_strcmp(articulo, articulos[i].descripcion)) i++;
        articulo_index = i;
        mi_strcpy(articulos[articulo_index].descripcion, articulo);

        printf("\n%s, Indice: %d\n", articulos[articulo_index].descripcion, articulo_index);
        printf("Para que sucursal va a realizar la carga? (1,2,3): ");
        scanf("%d", &sucursal);

        printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
        scanf("%d", &articulos[articulo_index].cantidad_sucursal[sucursal - 1]);

        // Recalcular total
        articulos[articulo_index].total = 0;
        for (i = 0; i < 3; i++)
            articulos[articulo_index].total += articulos[articulo_index].cantidad_sucursal[i];

        printf("Desea ingresar otro articulo? 1-Si, 2-No: ");
        scanf("%d", &opc);
    } while (opc == 1);
}

//impresion
void imprimir_articulos(articulos_t articulos[]) {
    int i = 0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < CANT_ARTICULOS && articulos[i].descripcion[0]) {
        printf("%s\t%d\t%d\t%d\t%d\n",
            articulos[i].descripcion,
            articulos[i].cantidad_sucursal[SUCURSAL_1],
            articulos[i].cantidad_sucursal[SUCURSAL_2],
            articulos[i].cantidad_sucursal[SUCURSAL_3],
            articulos[i].total);
        i++;
    }
}
// del tp1 -- bloque del for que ordenaba por el total
void ordenar_articulos(articulos_t articulos[]) {
    int i, j;
    for (i = 1; i < CANT_ARTICULOS; i++) {
        for (j = 0; j < CANT_ARTICULOS - 1; j++) {
            if (articulos[j].total < articulos[j + 1].total) {
                articulos_t aux = articulos[j];
                articulos[j] = articulos[j + 1];
                articulos[j + 1] = aux;
            }
        }
    }
}

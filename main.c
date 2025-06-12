//int main(void)
//int  opc=0, i, articulo_index, sucursal;
// char articulo[90];
//  articulos_t articulos[CANT_ARTICULOS] = {0};
//   printf("Bienvendio al final de Info 1\n\n");
//*CARGA de las fichas*/

#include <stdio.h>
#include "funciones.h"
#include "mi_string.h"

int main(void)
{
    articulos_t articulos[CANT_ARTICULOS] = {0};

    printf("Bienvenido al final de Info 1\n\n");

    cargar_articulo(articulos);

    printf("\n ARTÍCULOS CARGADOS \n");
    imprimir_articulos(articulos);

    ordenar_articulos(articulos);

    printf("\nARTÍCULOS ORDENADOS POR TOTAL\n");
    imprimir_articulos(articulos);

    return 0;
}

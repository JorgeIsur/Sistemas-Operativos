#include "cubiculos.h"

void limpiarCubiculo(int cubiculo){
    int departamento;
    int posicion;
    char *limpio = "<-DISPONIBLE->"; 
    if ((departamento=open("profesores",O_RDWR))<0)
    {
        printf("No pude abrir el archivo\n");
        exit(1);
    }
    posicion = (cubiculo-1)*TAMNOMBRE;

    lseek(departamento,posicion,0);
    write(departamento,limpio,sizeof(limpio));
    printf("Limpieza de cubiculo realizada");
}
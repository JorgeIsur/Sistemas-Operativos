#include "cubiculos.h"

void cambiarCubiculo(int nuevoCubiculo, char *nombre){
    int departamento;
    int posicion;
    if ((departamento=open("profesores",O_RDWR))<0)
    {
        printf("No pude abrir el archivo\n");
        exit(1);
    }
    posicion = (nuevoCubiculo-1)*TAMNOMBRE;

    lseek(departamento,posicion,0);
    write(departamento,nombre,sizeof(nombre));
    printf("Cambio de cubiculo exitoso");
}
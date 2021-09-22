#include "cubiculos.h"

void agregaProfesor(char *ocupante){
    int departamento;
    int nombre;
    int buffer;
    if ((departamento=open("profesores",O_RDWR))<0)
    {
        printf("No pude abrir el archivo\n");
        exit(1);
    }
    lseek(departamento,0,2);
    write(departamento,ocupante,sizeof(ocupante));
    close(departamento);
    printf("Escritura exitosa");
}
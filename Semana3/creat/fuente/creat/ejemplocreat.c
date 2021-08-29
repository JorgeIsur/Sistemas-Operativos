#include "ejemplocreat.h"
int main(void)
{
    int desarchivo;
    char nombrearchivo[]=”nuevo”;
    if((desarchivo=creat(ARCHIVO,PERMISOS))==-1)
    {
        printf(“No pude crear el archivo %s\n”,ARCHIVO);
        exit(1); 
    }
    /* Resto del programa */
    return(0);
}
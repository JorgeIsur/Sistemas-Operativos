#include "entregable6.h"

int esperaComando(char *nombre,char *comando){
    struct stat archivo;
    time_t tiempoActual;
    time_t tiempoModificacion;
    char exec[20] = "/bin/";
    int probar = stat(nombre,&archivo);
    if (probar!=0)
    {
        printf("Error al ejecutar stat en %s\n",nombre);
        exit(1);
    }
    printf("Archivo modificado en:\t%s",ctime(&archivo.st_mtime));
    tiempoModificacion = archivo.st_mtime;
    tiempoActual = time(0);
    if ((tiempoModificacion != tiempoActual)&& probar==0)
    {
        printf("El archivo  %s fue modificado\n",nombre);
        printf("Ejecutando comando:\t%s\n",comando);
        strcat(exec,comando);
        execl(exec,comando,NULL);
        perror("Fallo el execl para correr el comando\n");
        return(errno);
    }
    else{
        printf("El archivo %s no ha sido modificado\n",nombre);
    }
    return 0;
}
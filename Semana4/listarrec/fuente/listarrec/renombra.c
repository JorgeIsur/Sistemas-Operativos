#include <listarrec.h>

int renombra(const char *nombre, int caracter){
    char *opciones[6] = {"*b","*c","/","->","@","*"};
    char *newName;
    char *ruta = realpath(nombre,NULL);
    int ret;
    for (int i = 0; opciones[i]; i++){
        if (caracter==i)
        {
            printf("renombrando....\n");
            newName=strcat(nombre,opciones[i]);
            printf("Nuevo nombre:%s\n",newName);          
        }
    }
    if ((ret=rename(ruta,newName)==0))
    {
        printf("Renombrado exitoso.\n");
        return 1;
    }
    else{
        perror(NULL);
        fprintf(stderr,"Valor errno:%d\n",errno);
        printf("Fallo al renombrar\n");
        exit(0);
    }
    return(0);
}
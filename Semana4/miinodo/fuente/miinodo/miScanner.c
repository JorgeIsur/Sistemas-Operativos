#include "miinodo.h"

char *miScanner(char *nombre,char *archivo){
    struct dirent *entradadirectorio;
    DIR *directorio;
    if ((directorio=opendir(nombre))==NULL)
    {
        fprintf(stderr,"\aNo pude abrir el directorio %s",nombre);
        perror("\n");
        return(-1);
    }
    while (entradadirectorio=readdir(directorio))
    {
        if (entradadirectorio->d_name!=NULL)
        {
            return(entradadirectorio->d_name);
        }
    }
    if (closedir(directorio)==-1)
    {
        fprintf(stderr,"\a No pude cerrar el directorio %s",nombre);
        perror("\n");
        return(-1);
    }
    return(0);
    
}
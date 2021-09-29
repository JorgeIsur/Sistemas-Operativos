#include <miinodo.h>

int renombrar(char *dir,char *nombre, int caracter){
    char *opciones[6] = {"*b","*c","/","->","@","*"};
    char *newName;
    char *ruta = realpath(nombre,NULL);
    char *newRoute;
    int ret;

    struct dirent *entradadirectorio;
    DIR *directorio;
    for (int i = 0; opciones[i]; i++){
        if (caracter==i)
        {
            printf("renombrando....\n");
            newName=strcat(nombre,opciones[i]);
            printf("Nuevo nombre:%s\n",newName);          
        }
    }
    if ((directorio=opendir(dir))==NULL)
    {
        fprintf(stderr,"\aNo pude abrir el directorio %s",dir);
        perror("\n");
        return(-1);
    }
    while (entradadirectorio=readdir(directorio))
    {
        printf("%s\n",entradadirectorio->d_name);
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
    }
    if (closedir(directorio)==-1)
    {
        fprintf(stderr,"\a No pude cerrar el directorio %s",dir);
        perror("\n");
        return(-1);
    }
    return(0);
}
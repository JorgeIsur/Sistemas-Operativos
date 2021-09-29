#include <listarrec.h>
int escaneoDir(const char *dir){
    char *opciones[6] = {"*b","*c","/","->","@","*"};
    char *newName;
    int ret;
    DIR *dirr;
    struct dirent *entrada;
    if ((dirr = opendir(dir))!= NULL)
    {
    while ((entrada =readdir(dirr))!=NULL)
       {    
            printf("Archivo:\t%s\n",entrada->d_name);
            if ( !strcmp(entrada->d_name, ".") || !strcmp(entrada->d_name, "..") ){
                // do nothing (straight logic)
            } 
            else {
                //do something
                char *ruta = realpath(entrada->d_name,NULL);
                struct stat sb;
                int caracter;
                int status;
                if (stat(entrada->d_name, &sb) == -1) {
                    perror("stat");
                    exit(EXIT_FAILURE);
                }
                switch (sb.st_mode & S_IFMT) {
                    case S_IFBLK:  
                        printf("Dispositivo de bloque\n");
                        caracter = 0;                    
                        newName=strcat(entrada->d_name,opciones[caracter]);
                        printf("Nuevo nombre:%s\n",newName);
                        if ((ret=rename(ruta,newName))==0)
                        {
                            printf("Renombrado exitoso.\n");
                        }
                        else{
                            perror(NULL);
                            fprintf(stderr,"Valor errno:%d\n",errno);
                            printf("Fallo al renombrar\n");
                            exit(0);
                        }
                        break;
                    case S_IFCHR:  
                        printf("Dispositivo de caracter\n");
                        caracter = 1;        
                        newName=strcat(entrada->d_name,opciones[caracter]);
                        printf("Nuevo nombre:%s\n",newName);
                        if ((ret=rename(ruta,newName))==0)
                        {
                            printf("Renombrado exitoso.\n");
                        }
                        else{
                            perror(NULL);
                            fprintf(stderr,"Valor errno:%d\n",errno);
                            printf("Fallo al renombrar\n");
                            exit(0);
                        }
                        break;
                    case S_IFDIR:  
                        printf("Directorio\n");
                        caracter = 2;            
                        newName=strcat(entrada->d_name,opciones[caracter]);
                        printf("Nuevo nombre:%s\n",newName);
                        if ((ret=rename(ruta,newName))==0)
                        {
                            printf("Renombrado exitoso.\n");
                        }
                        else{
                            perror(NULL);
                            fprintf(stderr,"Valor errno:%d\n",errno);
                            printf("Fallo al renombrar\n");
                            exit(0);
                        }
                        break;
                    case S_IFLNK:  
                        printf("Liga simbolica\n");
                        caracter = 3;        
                        newName=strcat(entrada->d_name,opciones[caracter]);
                        printf("Nuevo nombre:%s\n",newName);
                        if ((ret=rename(ruta,newName))==0)
                        {
                            printf("Renombrado exitoso.\n");
                        }
                        else{
                            perror(NULL);
                            fprintf(stderr,"Valor errno:%d\n",errno);
                            printf("Fallo al renombrar\n");
                            exit(0);
                        }
                        break;
                    case S_IFREG:  
                        printf("Archivo regular.\n");     
                        caracter = 4;
                        newName=strcat(entrada->d_name,opciones[caracter]);
                        printf("Nuevo nombre:%s\n",newName);
                        if ((ret=rename(ruta,newName))==0)
                        {
                            printf("Renombrado exitoso.\n");
                        }
                        else{
                            perror(NULL);
                            fprintf(stderr,"Valor errno:%d\n",errno);
                            printf("Fallo al renombrar\n");
                            exit(0);
                        }
                        break;
                    case S_IXUSR:
                        printf("Archivo ejecutable.\n");
                        caracter = 5;
                        newName=strcat(entrada->d_name,opciones[caracter]);
                        printf("Nuevo nombre:%s\n",newName);
                        if ((ret=rename(ruta,newName))==0)
                        {
                            printf("Renombrado exitoso.\n");
                        }
                        else{
                            perror(NULL);
                            fprintf(stderr,"Valor errno:%d\n",errno);
                            printf("Fallo al renombrar\n");
                            exit(0);
                        }
                        break;
                    default:       printf("Desconocido(?)\n");                break;
                }
            }
        }
        closedir(dirr);
    }
    else{
        printf("No se pudo abrir el folder.\n");
        exit(1);
    }
    return(0);
}
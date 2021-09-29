#include <listarrec.h>

int escaneoArchivos(char *nombre){
    
   struct stat sb;
   int caracter;
   int status;
   if (stat(nombre, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
   printf("Tipo de archivo:         ");

   switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:  
        printf("Dispositivo de bloque\n");
        caracter = 0;                    
        renombra(nombre,caracter);
        break;
    case S_IFCHR:  
        printf("Dispositivo de caracter\n");
        caracter = 1;        
        renombra(nombre,caracter);
        break;
    case S_IFDIR:  
        printf("Directorio\n");
        caracter = 2;            
        renombra(nombre,caracter);
        break;
    case S_IFLNK:  
        printf("Liga simbolica\n");
        caracter = 3;        
        renombra(nombre,caracter);     
        break;
    case S_IFREG:  
        printf("Archivo regular.\n");     
        caracter = 4;
        renombra(nombre,caracter);
        break;
    case S_IXUSR:
        printf("Archivo ejecutable.\n");
        caracter = 5;
        renombra(nombre,caracter);
        break;
    default:       printf("Desconocido(?)\n");                break;
    }

   printf("Numero i-nodo:            %ld\n", (long) sb.st_ino);
   printf("Numero de ligas:               %ld\n", (long) sb.st_nlink);
    printf("Propiedad:                UID=%ld   GID=%ld\n",
            (long) sb.st_uid, (long) sb.st_gid);
    printf("Tamaño del archivo:                %lld bytes\n",
            (long long) sb.st_size);
   printf("Ultimo cambio de status:       %s", ctime(&sb.st_ctime));
    printf("Ultimo acceso al archivo:         %s", ctime(&sb.st_atime));
    printf("Ultima modificacion al archivo:   %s", ctime(&sb.st_mtime));

   exit(EXIT_SUCCESS);
    return 0;
}
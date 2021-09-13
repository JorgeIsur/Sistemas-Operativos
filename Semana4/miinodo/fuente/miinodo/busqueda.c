#include <miinodo.h>

int escaneoDir(const char *archivo, const struct stat *metadata, int tipo){
    const char *archivo_nuevo;
    char *simbolo;
    if (tipo==FTW_NS)
    {
        printf("No se pudo llenar la estructura stat\n");
        exit(1);
    }
    if (tipo==FTW_D)
    {
        printf("Es un directorio\n");
        simbolo = '/';
        archivo_nuevo=strcat(archivo,simbolo);
        renombrar(archivo,archivo_nuevo);
    }
    if (tipo==FTW_DNR)
    {
        printf("Directorio ilegible\n");
        exit(1);
    }
    if (tipo==FTW_F)
    {
        printf("Es un archivo\n");
        simbolo = '*';
        archivo_nuevo=strcat(archivo,simbolo);
    }
    if (tipo==FTW_SL)
    {
        printf("Es una liga simbolica\n");
        simbolo = '->';
        archivo_nuevo=strcat(archivo,simbolo);
    }
    if (metadata->st_mode==060000)
    {
        printf("Es un dispositivo de bloque\n");
        simbolo = '*b';
        archivo_nuevo=strcat(archivo,simbolo);
    }
    if (metadata->st_mode==020000)
    {
        printf("Es un dispositivo de carácter\n");
        simbolo = '*c';
        archivo_nuevo=strcat(archivo,simbolo);
    }
    printf("%i\t%-s\n",metadata->st_ino,archivo);
    return 0;
}
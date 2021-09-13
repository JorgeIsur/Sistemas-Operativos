#include <miinodo.h>

int renombrar(const char *archivo, const char *archivo_nuevo){
    if (rename(archivo, archivo_nuevo)!=0)
    {
        printf("Error al renombrar archivo/directorio");
    }
    if (rename(archivo,archivo_nuevo)==0)
    {
        printf("Renombrar exitoso.");
    }
}
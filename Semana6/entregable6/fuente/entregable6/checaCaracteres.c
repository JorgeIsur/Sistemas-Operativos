#include "entregable6.h"

void checaCaracteres(char *comando){
    char problemas[5] = {'?',';','&','%',','};
    char comentario = '#';
    char *juez = "LIMPIO";
    for (int i = 0; i < 4; i++)
    {
        juez = strchr(comando,problemas[i]);
        if (juez!=NULL)
        {
            printf("Caracter invalido:\t%s\n",&problemas[i]);
            printf("Cerrando el programa...\n");
            exit(1);
        }
        printf("Checando caracteres...\n");
    }
    juez = strchr(comando,comentario);
    if (juez!=NULL)
    {
        printf("Esto es un comentario\n");
        printf("Los comentarios no se ejecutarán\n");
        printf("Saliendo del programa...\n");
        exit(0);
    }
    
    if (juez==NULL)
    {
        printf("->OK\n");
    }
    
}
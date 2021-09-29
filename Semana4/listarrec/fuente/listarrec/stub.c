#include "listarrec.h"

int main(int argc, char const *argv[])
{
    int opt;
    char *archivo;
    printf("1. Mostrar el contenido.\n");
    printf("2. Renombrar.\n");
    printf("==>");
    scanf("%i",&opt);
    if (opt==1)
    {
        switch (argc)
        {
        case 1:
            ftw(".",procesaarchivo,1);
            break;
        case 2:
            ftw(argv[1],procesaarchivo,1);
            break;
        default:
            fprintf(stderr,"Uso:\n");
            fprintf(stderr,"%s[directorio]\n");
            exit(1);
        }
    }
    if (opt==2)
    {
        printf("Iniciando renombrado..\n");
        escaneoDir(argv[1]);
    }
    return 0;
}

#include <entregable6.h>

int main(void)
{
    pid_t pid;
    pid_t pid2;
    pid_t pid3;
    char nombre[10];
    char comando[10];
    int opt;
    printf("Selecciona la acción a realizar\n");
    printf("1.Creación de procesos\n");
    printf("2.Ejecución de comando si el archivo fue modificado\n");
    scanf("%i",&opt);
    if (opt==1)
    {
        printf("Un proceso para probar la llamada al fork:\n");
        pid = fork(); /*doble proceso*/
        pid2 = fork();
        pid3 = fork();
        if (!pid) //si es el proceso hijo entra en el if
        {
            printf("Soy el proceso hijo, pid=%d\n", getpid());
        }   
        else if (pid>0)
        {
            printf("Soy el proceso padre, pid=%d\n",getpid());
        }   
        else{
            printf("Fallo el fork...no hay proceso");
        }
        return 0;
    }
    if (opt==2)
    {
        printf("Ingresa el nombre del archivo a evaluar:\n");
        scanf("%s",&nombre);
        printf("Ingresa el comando a ejecutar:\n");
        scanf("%s",&comando);
        checaCaracteres(comando);
        esperaComando(nombre,comando);
        return 0;
    }
    return 0;
}

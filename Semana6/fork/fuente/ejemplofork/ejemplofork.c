#include <ejemplofork.h>

int main(void)
{
    pid_t pid;
    printf("Un proceso para probar la llamada al fork:\n");
    pid = fork(); /*doble proceso*/
    if (!pid) //si es el proceso hijo entra en el if
    {
        printf("Soy el proceso hijo, pid=%d\n",pid);
    }
    else if (pid>0)
    {
        printf("Soy el proceso padre, pid=%d\n",pid);
    }
    else{
        printf("Fallo el fork...no hay proceso");
    }
    return 0;
}

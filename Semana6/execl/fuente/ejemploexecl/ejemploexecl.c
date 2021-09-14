#include <ejemploexecl.h>

int main(void)
{
    printf("Ejecutando el comando ls\n");
    execl("/bin/ls","ls","-FRal",NULL);
    perror("Fallo el execl para correr el ls\n");
    return(errno);
}

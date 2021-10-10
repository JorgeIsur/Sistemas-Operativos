#include "entregable8.h"

int main(void){
    char *comando1[] = {"ls","-Fal","/etc",NULL};
    char *comando2[] = {"more",NULL};
    int retorno;
    printf("juntar regreso %i\n",(retorno = juntar(comando1,comando2)));
    exit(retorno);
}
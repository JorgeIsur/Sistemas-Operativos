#include "entregable8.h"

int juntar(char *comando1[],char *comando2[]){
    int p[2],estado;
    switch(fork()){
        case -1:
            error("Fallo en el 1er fork");
            break;
        case 0:
            break;
        default:
            wait(&estado);
            return(estado);
    }
    if(pipe(p)<0){
        error("Fallo en el pipe");
    }
    switch(fork()){
        case -1:
            error("Fallo en el 2do fork");
            break;
        case 0:
            close(1);
            dup(p[1]);
            close(p[0]);
            close(p[1]);
            execvp(comando1[0],comando1);
            error("Fallo en el 1er execvp");
            break;
        default:
            close(0);
            dup(p[0]);
            close(p[0]);
            close(p[1]);
            execvp(comando2[0],comando2);
            error("Fallo el 2do execvp");
            break;
    }
}
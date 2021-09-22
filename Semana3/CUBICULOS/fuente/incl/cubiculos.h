#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMCUBICULOS 10
#define TAMNOMBRE 51

char *dimeprofesor(int);
void agregaProfesor(char *);
void cambiarCubiculo(int,char *);
void limpiarCubiculo(int);

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define TAM 10

void checabloqueo(int,long,int,long,char *);
int bloquearegistro(int,long,short,long);

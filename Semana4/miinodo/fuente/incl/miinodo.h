#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <ftw.h>
#include <string.h>
#include <time.h>
int miinodo(char *,char *);
int escaneoArchivos(char *,char *);
int renombrar(char *,char *,int);
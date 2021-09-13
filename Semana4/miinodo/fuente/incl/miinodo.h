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
int miinodo(char *,char *);
int escaneoDir(const char *archivo, const struct stat *metadata, int tipo);
int renombrar(const char *archivo, const char *archivo_nuevo);
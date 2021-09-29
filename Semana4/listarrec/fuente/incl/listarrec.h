#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ftw.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
int escaneoDir(const char *);
int procesaarchivo(
    const char *,
    const struct stat *,
    int
);
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ftw.h>
int procesaarchivo(
    const char *,
    const struct stat *,
    int
);
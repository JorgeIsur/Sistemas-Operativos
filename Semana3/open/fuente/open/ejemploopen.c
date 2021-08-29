#include "ejemploopen.h"
int main(void){
    int fdArchi;
    if ((fdArchi=open(ARCHIVO,O_RDWR))==-1)
    {
        printf("\a No pude abrir el archivo %s\n",ARCHIVO);
        exit(1);
    }
    return 0;
}
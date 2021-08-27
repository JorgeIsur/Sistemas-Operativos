#include "cubiculos.h"

int main(void)
{
        int profesor;
        char *ocupante;

        for(profesor=1;profesor<=NUMCUBICULOS;profesor++)
                if((ocupante=dimeprofesor(profesor))!=NULL)
                        printf("Cubiculo %2i: %s\n",profesor,ocupante);
                else
                        printf("\aError en el Cubiculo %i\n",profesor);
        return (0);
}

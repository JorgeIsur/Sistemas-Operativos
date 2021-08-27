#include "cubiculos.h"

char *dimeprofesor(int numcubiculos)
{
        long desplazamiento;
        int leern;
        int departamento=-1;
        char *nombres;

        if((nombres=(char *)calloc(TAMNOMBRE,sizeof(char)))==NULL)
        {
                fprintf(stderr,"No hay memoria para el buffer\n");
                exit(-3);
        }

        /* Abrir por primera vez el archivo de profesores */
        if(departamento==-1)
        {
                if((departamento=open("profesores",O_RDONLY))<0)
                        return NULL;
        }
        /* Calcular el desplazamiento */
       desplazamiento=(numcubiculos-1)*TAMNOMBRE;

       /* Hallar el cubiculo y el nombre del ocupante */
       if(lseek(departamento,desplazamiento,0)<0)
               return NULL;
               /* Leer el nombre del profesor */
       leern=read(departamento,nombres,TAMNOMBRE);

       if(leern<=0)
            return NULL;
       else
        { 
                nombres[leern-1]='\0';
                return(nombres);
        }
}

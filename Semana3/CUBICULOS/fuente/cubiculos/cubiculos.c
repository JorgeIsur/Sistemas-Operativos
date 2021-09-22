#include "cubiculos.h"

int main(void)
{
        int opt=0;
        int profesor;
        char *ocupante;
        char *simbolo;
        char *nuevo_profesor;
        int cubiculo;
        printf("Elige una opción:\n");
        printf("1.Mostrar contenido del archivo Profesores\n"
                "2.Agregar profesor\n"
                "3.Cambiar de cubiculo a profesor\n"
                "4.Desocupar un cubiculo\n"
                "0.Salir\n");
        printf("Selección:\t");
        scanf("%i",&opt);
        do{
                switch (opt)
                {
                case 1:
                        for(profesor=1;profesor<=NUMCUBICULOS;profesor++){
                                printf("%i\n",profesor);
                                if((ocupante=dimeprofesor(profesor))!=NULL){
                                        printf("Cubiculo %2i: %s\n",profesor,ocupante);
                                }
                                else{
                                        printf("\aError en el Cubiculo %i\n",profesor);
                                }
                        }
                break;
                case 2:
                        printf("Ingresa el nombre del profesor:\t");
                        scanf("%s",ocupante);
                        simbolo = "\n";
                        nuevo_profesor = strcat(ocupante,simbolo);
                        agregaProfesor(nuevo_profesor);
                break;
                case 3:
                        printf("Número máximo de cúbiculos:\t%i\n",NUMCUBICULOS);
                        printf("Ingresa el número de cubiculo que deseas:\t");
                        scanf("%i",&cubiculo);
                        printf("Ingresa el nombre del profesor:\t");
                        scanf("%s",ocupante);
                        simbolo = "\n";
                        nuevo_profesor = strcat(ocupante,simbolo);
                        cambiarCubiculo(cubiculo,nuevo_profesor);
                        break;
                case 4:
                        printf("Numero maximo de cubiculos:\t%i\n",NUMCUBICULOS);
                        printf("Ingresa el número del cubiculo a limpiar:\t");
                        scanf("%i",&cubiculo);
                        limpiarCubiculo(cubiculo);
                        break;
                case 0:
                        exit(0);
                        break;
                }
        }while(opt=!0);
return (0);
}

/***********************************************************************
* Archivo real.c : Funciones paar el manejo de vectores de reales. 	   *
*    				 												   *
* Este archivo contiene :										       *
*																	   *
* crea_vector : Obtiene dinámicamente un vector de reales.			   *
* corta_vector : Regresa el vector a la memoria.					   *
* copia_vector : Copia un vector en otro.							   *
***********************************************************************/

#include "real.h"
#include "salir.h"

/***********************************************************************
* crea_vector : Obtiene una vector dinamicamente. Si no puede aborta el*
* programa.															   *
***********************************************************************/
vector crea_vector(int longitud)
{
 vector grillete;

 if ((grillete=(vector)calloc(longitud,sizeof (real)))==NULL) {
	 perror("\aNo pude crear el vector\n");
	 abortar();
	 return NULL;
 }
 return (grillete);
}

/***********************************************************************
* corta_vector : Libera una vector.                                    *
***********************************************************************/
void corta_vector(vector grillete)
{
 free(grillete);
}

/***********************************************************************
* copia_vector : Copia un vector.                                      *
***********************************************************************/
void copia_vector(vector grillete,vector eslabon,int n)
{
 int i=0;

 for (i=0;i<n;i++)
	*grillete++=*eslabon++;
}

/**************************************************************************
* realcmp : Compara reales. Regresa 0 si son iguales, regresa 1 si el     *
* primero es mayor al segundo y regresa -1 en caso contrario.             *
**************************************************************************/
int realcmp(real r1,real r2)
{
 if (cricon(r2,r1)<=TOL)
	return (0);
 else if (r1>r2)
	return (1);
 else
	return (-1);
}

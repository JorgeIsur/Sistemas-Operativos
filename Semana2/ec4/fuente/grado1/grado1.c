/**************************************************************************
* lineal : Resuelve la ecuaci�n lineal mediante la formula analitica y    *
* regresa el n�mero de raices halladas.                      			  *
**************************************************************************/
#include "grado4.h"

num_tipo_raiz lineal(real *c,real *x)
{
 if (realcmp(c[1],0.))
 {
	/* Soluci�n de la ecuaci�n lineal general */
	x[0] = -c[0]/c[1];
	return (0);
 }
 else
	 /* Soluci�n de la ecuaci�n constante degenerada */
	 return constante(c,x);
}


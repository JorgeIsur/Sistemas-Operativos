/**************************************************************************
* lineal : Resuelve la ecuación lineal mediante la formula analitica y    *
* regresa el número de raices halladas.                      			  *
**************************************************************************/
#include "grado4.h"

num_tipo_raiz lineal(real *c,real *x)
{
 if (realcmp(c[1],0.))
 {
	/* Solución de la ecuación lineal general */
	x[0] = -c[0]/c[1];
	return (0);
 }
 else
	 /* Solución de la ecuaci¢n constante degenerada */
	 return constante(c,x);
}


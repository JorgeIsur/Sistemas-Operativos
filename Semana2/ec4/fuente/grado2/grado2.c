/**************************************************************************
* cuadratica : Resuelve la ecuación cuadratica mediante la formula del    *
* chicharronero y regresa el número de pares conjugados de raices         *
* complejas. Si todas son reales regresa 0.                               *
*                                                                         *
* Tabla de variables:                                                     *
* dis: discriminante de la ecuación cuadratica.                           *
*                                                                         *
* Notas:                                                                  *
* Si existen raices complejas, la parte real y la parte imaginaria se     *
* almacenan consecutivamente y se calculan por separado.                  *
* En la primera parte del arreglo que tiene las raices se almacenan las   *
* raices reales (si existen). En el resto se almacenan las complejas (si  *
* existen).                                                               *
**************************************************************************/
#include "grado4.h"

num_tipo_raiz cuadratica(real *c,real *x)
{
 real dis;
 if (realcmp(c[2],0.))
 {
	/* Solución de la ecuación cuadratica general */
	/* Cálculo del discriminante */
	dis=cuad(c[1])-4.*c[2]*c[0];

	if (!realcmp(dis,0.))
	{
		/* Solución si existen raices identicas */
		x[1] = x[0] = -c[1]/2./c[2];
		return (0);
	}
	else if (realcmp(dis,0.)>0)
	{
		/* Solución si existen raices diferentes */
		x[0] = (-c[1]+sqrt(dis))/(double)2/c[2];
		x[1] = (-c[1]-sqrt(dis))/2./c[2];
		return (0);
	}
	else
	{
		/* Solución si existen raices complejas */
		x[0] = -c[1]/2./c[2];
		x[1] = fabs(sqrt(-dis)/2./c[2]);
		return (1);
	}
 }
 else
	 /* Solución de la ecuación lineal degenerada */
	 return lineal(c,x);
}


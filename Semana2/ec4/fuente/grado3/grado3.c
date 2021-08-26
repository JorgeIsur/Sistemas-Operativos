/**************************************************************************
* cubica : Resuelve la ecuación cúbica mediante las formulas de Tartaglia *
* y regresa el número de pares conjugados de raices complejas. Si todas   *
* son reales regresa 0.                                                   *
*                                                                         *
* Tabla de variables:                                                     *
* p,q,u,v: valores auxiliares.                                            *
* cte: "constante" para regresar a la ecuación cúbica general.            *
* dis: discriminante de la ecuación cúbica.                               *
*                                                                         *
* Notas:                                                                  *
* Si existen raices complejas, la parte real y la parte imaginaria se     *
* almacenan consecutivamente y se calculan por separado.                  *
* En la primera parte del arreglo que tiene las raices se almacenan las   *
* raices reales. En el resto se almacenan las complejas (si existen).     *
**************************************************************************/
#include "grado4.h"

num_tipo_raiz cubica(real *c,real *x)
{
 #define _CTE sqrt((double).75)
 real p,q,dis,u,v,cte;
 if (realcmp(c[3],0.))
 {
	/* Solución de la ecuación cúbica general */
	/* Cálculo de los valores auxiliares p & q. */
	p = c[1]/c[3]/(real)3-cuad(c[2]/c[3])/(real)9;
	q = cubo(c[2]/c[3])/(real)27-c[2]*c[1]/cuad(c[3])/(real)6+
	c[0]/c[3]/(real)2;

	/* Cálculo del discriminante */
	dis = cuad(q)+cubo(p);

	/* Cálculo del valor auxiliar cte. */
	cte = c[2]/c[3]/(real)3;

	if (!realcmp(dis,0.))
	{
		/* Solución si existen raices identicas */
		x[0] = -2.*cbrt(q)-cte;
		x[2] = x[1] = cbrt(q)-cte;
		return (0);
	}
	else if (realcmp(dis,0.)>0)
	{
		/* Solución si existen raices complejas */
		u = cbrt(sqrt(dis)-q);
		v =-cbrt(sqrt(dis)+q);
		x[0] = u+v-cte;
		x[1] = -(u+v)/(real)2-cte;
		x[2] =fabs(_CTE*(u-v));
		return (1);
	}
	else
	{
		/* Solución si existen raices distintas */
		u = sgn(q)*sqrt(fabs(p));
		v = acos(q/cubo(u));
		x[0] = -2.*u*cos(v/(real)3)-cte;
		x[1] =  2.*u*cos((PI+v)/(real)3)-cte;
		x[2] =  2.*u*cos((PI-v)/(real)3)-cte;
		return (0);
	}
 }
 else
	 /* Solución de la ecuación cuadratica degenerada */
	 return cuadratica(c,x);
}


/**************************************************************************
* Libreria Grado4 Contiene las funciones para la solución analitica de los*
* polinomios de grado 0 al 4.                                             *
* Referencia: "Manual de Matemáticas Para Ingenieros y Estudiantes",      *
* I. Bronshtein, K. Semendiaev. ECP México 1985.                          *
* Versión 2: 16 de Agosto de 1995 DC. 19:05:55 Hrs.                       *
* Dise¤ada por: Ing. Hugo Pablo Leyva.                                    *
* Revisión 26 de Abril de 1998 DC. 17:38:14 Hrs.					      *
* Revisada por: M en C Hugo Pablo Leyva.								  *
**************************************************************************/

#include "grado4.h"

/**************************************************************************
* cuartica:Resuelve la ecuación cuartica mediante las formulas analiticas *
* y regresa el número de pares conjugados de raices complejas. Si todas   *
* son reales regresa 0.                                                   *
*                                                                         *
* Tabla de variables:                                                     *
* d: coeficientes auxiliares.                                             *
* y: raices auxiliares. 						  						  *
* A: valor auxiliar.                                                      *
* raiz_cub: raiz de la ecuación cúbica auxiliar.                          *
* tipo1, tipo2: Número y tipos de las raices de las ecuaciones auxiliares.*
* conta: contador para el ciclo for.                                      *
*                                                                         *
* Notas:                                                                  *
* Si existen raices complejas, la parte real y la parte imaginaria se     *
* almacenan consecutivamente y se calculan por separado.                  *
* En la primera parte del arreglo que tiene las raices se almacenan las   *
* raices reales (si existen). En el resto se almacenan las complejas (si  *
* existen).                                                               *
**************************************************************************/

num_tipo_raiz cuartica(real *c,real *x)
{
 real d[4],y[4];
 real A,raiz_cub;
 num_tipo_raiz tipo1,tipo2;
 int conta=0;

 if (realcmp(c[4],0.))
 {
	 if (realcmp(c[3],0.) || realcmp(c[1],0.))
	 {
		/* Solución de la ecuación cuartica general */
		/* Cálculo de los coeficientes de la ecuación cúbica auxiliar */
		d[3]=8.;
		d[2]=-4.*c[2]/c[4];
		d[1]=(2.*c[3]*c[1]/c[4]-8.*c[0])/c[4];
		d[0]=c[0]/c[4]*(4.*c[2]/c[4]-cuad(c[3]/c[4]))-cuad(c[1]/c[4]);

		/* Solución de la ecuación cúbica auxiliar */
		tipo1 = cubica(d,y);

		if (tipo1)
			/* Cálculo del valor auxiliar A si la ecuación cúbica tiene
				raices complejas */
			A = (8.*y[conta]+cuad(c[3]/c[4])-4.*c[2]/c[4]);
		else
			/* Cálculo del valor auxiliar A si la ecuación cúbica no
				tiene raices complejas */
			for (conta=0;conta<3;++conta)
				if (realcmp((A =
					(8.*y[conta]+cuad(c[3]/c[4])-4.*c[2]/c[4])),0.)>0)
					break;

		A = sqrt(fabs(A));
		raiz_cub = y[conta<3?conta:--conta];

		/* Cálculo de los coeficientes de la primera ecuación cuadratica
		auxiliar */
		d[2]=1.;
		d[1]=(c[3]/c[4]+A)/2.;
		d[0]=realcmp(A,0.)?raiz_cub+(c[3]*raiz_cub-c[1])/c[4]/A:raiz_cub;

		/* Solución de la primera ecuación cuadratica auxiliar */
		tipo1 = cuadratica(d,y);

		/* Cálculo de los coeficientes de la otra ecuación cuadratica
		auxiliar */
		d[1]=(c[3]/c[4]-A)/2.;
		d[0]=realcmp(A,0.)?raiz_cub-(c[3]*raiz_cub-c[1])/c[4]/A:raiz_cub;

		/* Solución de la segunda ecuación cuadratica auxiliar */
		tipo2 = cuadratica(d,y+2);

		/* Clasificación de las raices */
		if (!tipo1 && !tipo2)
		{
			x[0] = y[0], x[1] = y[1], x[2] = y[2], x[3] = y[3];
			return (0);
		}
		else if (!tipo1 && tipo2)
		{
			x[0] = y[0], x[1] = y[1], x[2] = y[2], x[3] = y[3];
			return (1);
		}
		else if (tipo1 && !tipo2)
		{
			x[0] = y[2], x[1] = y[3], x[2] = y[0], x[3] = y[1];
			return (1);
		}
		else
		{
			x[0] = y[0], x[1] = y[1], x[2] = y[2], x[3] = y[3];
			return (2);
		}
	 }
	 else
	 {
		/* Solución de la ecuación cuartica bicuadratica */
		/* Cálculo de los coeficientes de la ecuación cuadratica
			auxiliar */
		d[2] = c[4];
		d[1] = c[2];
		d[0] = c[0];

		/* Solución de la ecuación cuadratica auxiliar */
		tipo1 = cuadratica(d,y);

		/* Cálculo y clasificación de las raices */
		if (!tipo1)
		{
			if (realcmp(y[0],0.)>=0 && realcmp(y[1],0.)>=0)
			{
				x[0] = sqrt(y[0]),x[1] = -x[0];
				x[2] = sqrt(y[1]),x[3] = -x[2];
				return (0);
			}
			else if (realcmp(y[0],0.)>=0 && realcmp(y[1],0.)<0)
			{
				x[0] = sqrt(y[0]),x[1] = -x[0];
				x[2] = 0.,x[3] = sqrt(-y[1]);
				return (1);
			}
			else if (realcmp(y[0],0.)<0 && realcmp(y[1],0.)>=0)
			{
				x[0] = sqrt(y[1]),x[1] = -x[0];
				x[2] = 0.,x[3] = sqrt(-y[0]);
				return (1);
			}
			else
			{
				x[2] = x[0] = 0.;
				x[1] = sqrt(-y[0]),x[3] = sqrt(-y[1]);
				return (2);
			}
	   }
	   else
	   {
			y[2] = sqrt(cuad(y[0])+cuad(y[1]));
			y[3] = (y[0])?atan2(y[1],y[0]):sgn(y[1])>=0?PI/2.:1.5*PI;
			x[0] = sqrt(y[2])*cos(y[3]/2.);
			x[3] = x[1] = sqrt(y[2])*sin(y[3]/2.);
			x[2] = -x[0];
			return (2);
	   }
	 }

 }
 else
	 /* Solución de la ecuación cúbica degenerada */
	 return cubica(c,x);
}

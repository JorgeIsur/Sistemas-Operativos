/***********************************************************************
* Header para el manejo de vectores de reales.						   *
***********************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <float.h>


#ifndef _REAL

	typedef double real;
	typedef real *vector;

	vector crea_vector(int);
	void corta_vector(vector);
	void copia_vector(vector,vector,int);
	int realcmp(real,real);

	/* Macros */

	/* CONCRI : Criterio de convergencia con error y valor real */
	#define CONCRI(vr,error) ( (vr)?( (error)/(vr) ):( (error) ) )

	/* concri : Idem pero absoluto */
	#define concri(vr,error) fabs(CONCRI((vr),(error)))

	/* CRICON : Criterio de convergencia con aproximaci¢n y valor real*/
	#define CRICON(vr,va) ( (vr)?( 1-(va)/(vr) ):( (vr)-(va) ) )

	/* cricon : Idem pero absoluto */
	#define cricon(vr,va) fabs(CRICON((vr),(va)))

	/* Cálculo del cuadrado */
	#define cuad(x) ((x)*(x))

	/* Cálculo del cubo */
	#define cubo(x) ((x)*(x)*(x))

	/* Cálculo de la raiz c£bica */
	#define UN_TERCIO ((real)1/(real)3)
	#define cbrt(x) ((x)?pow(fabs((real)(x)),UN_TERCIO)*\
					signo((x)):(real)0)

	/* Cálculo de la  funci¢n signo */
	#define signo(x) ((x)>0?(real)1:((x)?(real)-1:(real)0))

	/* Cálculo de la  funci¢n signo modificada */
	#define sgn(x) (((x))?signo((x)):(real)1)

	#ifndef PI
		#define PI 3.14159265358979323846264338327950288
	#endif

	/* Tolerancia para comparar reales */
	#define TOL 5.e-9

	#define _REAL 1

#endif

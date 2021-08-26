/***********************************************************************
* Header para el manejo de utilerias de polinomios.					   *
***********************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include "real.h"
#include "salir.h"

#ifndef _POLINOMIO

	/* Definición de los tipos de datosy número de raices */
	typedef int num_tipo_raiz;

/* Definición de macros */
#define MAXIMO_GRADO 4
#define MAX_RAICES MAXIMO_GRADO
#define MAX_COEF (MAX_RAICES+1)

	void imprime_raices(real *,real *,int,num_tipo_raiz);
	bool checa_raices(real *,real *,int,num_tipo_raiz);
	void visto_bueno(real *,real *,int,num_tipo_raiz);
	void bien(void);
	void mal(void);
	void error_num_tipo_raiz(void);
	real divsinreal(int,real *,real,real *);
	real divsincompleja(int,real *,real,real,real *,real *,real *);
	real norma(int,real *);
	void error1(void);
	void errorn(void);
	void error_opcion(void);

	#define _POLINOMIO 1

#endif

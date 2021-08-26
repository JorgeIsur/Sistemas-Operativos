/***********************************************************************
* Archivo salir.h: Contiene los headers y prototipos de las funciones  *
* para salir de un programa. 			   		       				   *
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "cadena.h"

#ifdef __TURBOC__
	  #include <conio.h>
#endif

#ifndef _SALIR


	typedef enum {FALSO,CIERTO} bool;

	void despedidas(void);
	void abortar(void);
	void salir(void);
	void salida_1(void);
	void salida_2(void);
	void limpia(void);
	void comando(cadena);

	#define _SALIR 1

#endif

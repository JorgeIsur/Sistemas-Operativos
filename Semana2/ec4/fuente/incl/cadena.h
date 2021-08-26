/***********************************************************************
* Header para el manejo de cadenas.                		       		   *
***********************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef _CADENA

	typedef char caracter;
	typedef caracter *cadena;

	cadena crea_cadena(int);
	cadena *crea_cadenas(int);
	void corta_cadenas(cadena *);
	void corta_cadena(cadena);
	cadena cambia_ext(cadena,cadena,cadena);
	cadena mayusculas(cadena);
	cadena remcarcad(cadena,caracter,caracter);
	cadena relledona(int,cadena,cadena);
	void incarcarcad(cadena,caracter,caracter);
	cadena limpiafgets(cadena);

	#define LONCAD 200
	#define _CADENA 1

#endif

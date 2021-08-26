/***********************************************************************
* Archivo salir.c: Contiene las funciones para salir de un programa.   *
*																	   *
* Este archivo contiene:											   *
*																	   *
* despedidas : Define las funciones que seran llamadas al terminar el  *
* el programa.												           *
* abortar : Termina la ejecución del programa anormalmente.			   *
* salir : Termina normalmente la ejecución del programa.			   *
* salida_1 : Primera función llamada al terminar el programa.          *
* salida_2 : Segunda función llamada al terminar el programa.          *
* limpia : Limpia la pantalla.									       *
* comando: Ejecuta un comando del SO.							       *
***********************************************************************/

#include "salir.h"

/***********************************************************************
* despedidas: Funciones que se llamaran al terminar el programa.       *
***********************************************************************/
void despedidas(void)
{
 atexit(salida_2);
 atexit(salida_1);
}

/***********************************************************************
* abortar: Aborta la ejecución del programa. Regresa al sist. operativo*
* el valor correspondiente.                                            *
***********************************************************************/
void abortar(void)
{
 putchar('\a');
 exit(EXIT_FAILURE);
}

/***********************************************************************
* salir: Termina la ejecución del programa y regresa al sist. operativo*
* el valor correspondiente.                                            *
***********************************************************************/
void salir(void)
{
 exit(EXIT_SUCCESS);
}

/***********************************************************************
* salida_1: Primera función llamada para despedir al programa.         *
***********************************************************************/
void salida_1(void)
{
 printf("\n\aYa termine por fin\nGracias por la preferencia\n");
}

/***********************************************************************
* salida_2: Segunda función llamada para despedir al programa.         *
***********************************************************************/
void salida_2(void)
{
 #ifdef __MSDOS__
	printf("\nCorri en una simple PC\nBye\n");
 #elif __unix
	printf("\nCorri en una multiusuario\nBye\n");
 #else
	printf("\nCorri en una patito\nBye\n");
 #endif
}

/***********************************************************************
* limpia : Limpia la pantalla.                                         *
***********************************************************************/
void limpia(void)
{
 #ifdef __TURBOC__
	clrscr();
 #elif __MSDOS__
	system("cls");
 #elif __unix
	system("clear");
 #else
	int i;
	for(i=0;i<50;i++,putchar('\n');
 #endif
}

/***********************************************************************
* comando : Ejecuta un comando del SO.                                 *
***********************************************************************/
void comando(cadena cmd)
{
 if (system(cmd)) {
 	puts(cmd);
 	perror("\aNo pude ejecutarlo :<\n");
	abortar();
 }
}

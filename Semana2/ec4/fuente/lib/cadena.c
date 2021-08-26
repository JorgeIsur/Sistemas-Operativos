/***********************************************************************
* Archivo cadena.c : Funciones paar el manejo de cadenas.              *
*    				 												   *
* Este archivo contiene :										       *
*																	   *
* crea_cadena : Obtiene dinámicamente cadenas.						   *
* corta_cadena : Regresa la cadena a la memoria.	   				   *
* crea_cadenas : Obtiene dinámicamente un arreglo de cadenas.		   *
* corta_cadenas: Regresa el arrglo de cadenas a la memoria.			   *
* cambia_ext : Cambia la extensión de un archivo.					   *
* mayusculas : Convierte una cadena a mayusculas.					   *
* relledona : Rellena una cadena con blancos.						   *
* remcarcad : Reemplazar un caracter por otro en una cadena.		   *
* incarcarcad: Insertar el caracter c antes de un caracter d en una    *
* cadena.   														   *
***********************************************************************/

#include "cadena.h"
#include "salir.h"

/***********************************************************************
* crea_cadena : Obtiene una cadena dinamicamente. Regresa un apuntador *
* a char. Si no puede crearla aborta el programa.					   *
***********************************************************************/
cadena crea_cadena(int longitud)
{
 cadena grillete;
 if ((grillete=(cadena)calloc(++longitud,sizeof (char)))==NULL) {
     perror("\aNo pude crear la cadena\n");
     abortar();
     return NULL;
 }
 return (grillete);
}

/***********************************************************************
* corta_cadena : Libera una cadena.                                    *
***********************************************************************/
void corta_cadena(cadena grillete)
{
 free(grillete);
}

/***********************************************************************
* crea_cadenas : Obtiene arreglo de cadenas dinamicamente. Regresa un  *
* apuntador a apuntador a char. Si no puede crearlo aborta el programa.*
***********************************************************************/
cadena *crea_cadenas(int longitud)
{
 cadena *grillete;
 if ((grillete=(cadena *)calloc(++longitud,sizeof (cadena)))==NULL) {
     perror("\aNo pude crear las cadenas\n");
     abortar();
     return NULL;
 }
 return (grillete);
}

/***********************************************************************
* corta_cadenas : Libera las cadenas.								   *
***********************************************************************/
void corta_cadenas(cadena *grillete)
{
 int i=0;
 for(;grillete[i]!=NULL;i++)
 	free(grillete[i]);
 free(grillete);
}

/***********************************************************************
* cambia_ext : cambia la extensión de un archivo de MS-DOS.            *
***********************************************************************/
cadena cambia_ext(cadena kennyg,cadena sting,cadena ext)
{
 size_t i=0;
 strcpy(kennyg,sting);
 while (sting[i]) {
       if (sting[i] == '.')
			break;
	   else
			i++;
 }
 if (strlen(sting) == i)
	 kennyg[i] = '.';
 if (strcmp(ext,"")) {
	 kennyg[i+1]='\0';
	 strcat(kennyg,ext);
 }
 else
	 kennyg[i] = '\0';
 return (kennyg);
}

/**********************************************************************
* mayusculas : Convierte una cadena a mayusculas.                     *
**********************************************************************/
cadena mayusculas(cadena mecano)
{
 for (;*mecano;mecano++)
	  *mecano=toupper(*mecano);
 return (mecano);
}

/***********************************************************************
* relledona : Copia sting en kennyg y rellena el sobrante hasta		   *
* completar num_blancos de longitud de kennyg.				       	   *
***********************************************************************/
cadena relledona(int num_blancos,cadena sting,cadena kennyg)
{
 int i,long_cad=strlen(sting);
 if (num_blancos > LONCAD || num_blancos<1) {
	perror("\aNum‚ro de blancos invalido\n");
	return NULL;
 }
 strcpy(kennyg,sting);
 for (i=long_cad;i<num_blancos;i++)
	  strcat(kennyg," ");
 return (kennyg);
}

/**********************************************************************
* remcarcad : Remplaza un caracter por otro en una cadena.			  *
**********************************************************************/
cadena remcarcad(cadena mecano,caracter c,caracter u)
{
 for (;*mecano;mecano++)
 	if(*mecano == c)
	  *mecano=u;
 return (mecano);
}

/**********************************************************************
* incarcarcad :Inserta un caracter c delante de otro caracter d en una*
* cadena .													          *
**********************************************************************/
void incarcarcad(cadena mecano,caracter c,caracter d)
{
 cadena sting;
 for(mecano=strchr(mecano,d);mecano!=NULL;mecano=strchr((mecano+=2),d)){
		for(sting=mecano+strlen(mecano)+1;sting>mecano;sting--)
			*sting=*(sting-1);
		*mecano=c;
	}
}

/**********************************************************************
* limpiafgets :Elimina el caracter \n leido por fgets.                *
**********************************************************************/
cadena limpiafgets(cadena sting)
{
 return (*strrchr(sting,'\n')='\0',sting);
}

/**************************************************************************
* checa_raices : Verifica las reaices obtenidas de la ecuación cuartica.  *
* Regresa CIERTO si pasan la prueba y viceversa.                          *
*                                                                         *
* Notas:                                                                  *
* Se emplea las propiedades de las raices. Si todas las raices son reales *
* se verifica la suma de las mismas. Si se tiene raices complejas se      *
* verifica el producto de todas inclusive si se tienen reales.            *
**************************************************************************/
#include "polinomio.h"

bool checa_raices(real *c,real *x,int grado,num_tipo_raiz tipo)
{
 real LTH;
 int conta;
 if (!grado)
	 return (tipo?FALSO:CIERTO);
 if (tipo)
 {
	for (conta=0,LTH=1.;conta < grado-2*tipo; ++conta)
		LTH*=x[conta];
	for (;conta<grado;conta+=2)
		LTH*=(cuad(x[conta])+cuad(x[conta+1]));
	return (!realcmp(LTH,(grado%2?-1:1)*c[0]/c[grado])?CIERTO:FALSO);
 }
 else
 {
	for (conta=0,LTH=0.;conta < grado; ++conta)
		LTH+=x[conta];
	return (!realcmp(LTH,-c[grado-1]/c[grado])?CIERTO:FALSO);
 }
}

/***************************************************************************
* checa_eval_raices : Verifica las raices obtenidas de la ecuación cuartica*
* evaluando en el polinomio.                                               *
*                                                                          *
* Notas:                                                                   *
* Se evalua mediante división sintetica todas las raices. Los resultados   *
* se almacenan en un arreglo y se compara la norma natural de este contra  *
* 0.                                                                       *
***************************************************************************/
bool checa_eval_raices(real *c,real *x,int grado,num_tipo_raiz tipo)
{
 real LTH[MAX_RAICES],b[MAX_COEF];
 real yr,yi;
 int conta;
 if (!grado)
	return (tipo?FALSO:CIERTO);
 if (tipo)
 {
	for (conta=0;conta < grado-2*tipo; ++conta)
		LTH[conta]=divsinreal(grado,c,x[conta],b);
	for (;conta<grado;conta+=2)
		LTH[conta+1]=LTH[conta]=
					divsincompleja(grado,c,x[conta],x[conta+1],b,&yr,&yi);
	return (!realcmp(norma(grado,LTH),0.)?CIERTO:FALSO);
 }
 else
 {
	for (conta=0;conta < grado; ++conta)
		LTH[conta]=divsinreal(grado,c,x[conta],b);
	return (!realcmp(norma(grado,LTH),0.)?CIERTO:FALSO);
 }
}

/**************************************************************************
* imprime_raices : Imprime las raices de la ecuación cuartica.    	  	  *
**************************************************************************/
void imprime_raices(real *c,real *x,int grado,num_tipo_raiz tipo)
{
 int conta;
 printf("\t\t\t\tEcuación\t\t\t\n");
 if (!grado)
	printf("      \t\t\t%#.19g = %#.19g\t\t      \n",c[0],0.);
 else
 {
	for (conta=grado;conta>=2;--conta)
		printf("      \t\t\t%#+.19gx^%d \t\t\t\t      \n",c[conta],conta);
	printf("      \t\t\t%#+.19gx    \t\t\t\t      \n",c[conta--]);
	printf("      \t\t\t%#+.19g =   \t\t\t\t      \n",c[conta]);
	printf("      \t\t\t%#.19g\t\t      \n",0.);
 }
 if (!grado)
 {
	if (tipo)
		printf("      \t\t\tLa ecuación no tiene raices.\t\t\t      \n");
	else
		printf(
		"      \tLa ecuación es valida para todos los reales y complejos.\t      \n");
	return;
 }
 printf("      \t\t\tLas raices son:\t\t\t      \n");
 if (tipo)
 {
	for (conta=0;conta < grado-2*tipo; ++conta)
		printf("      \t\t\tx%d = %#+.19g\t\t\t\t      \n",conta+1,
														x[conta]);
	for (;conta<grado;conta+=2)
	{
		printf("      \t\tx%d = %#+.19g +%#.19g i\t\t      \n",conta+1,
													x[conta],x[conta+1]);
		printf("      \t\tx%d = %#+.19g -%#.19g i\t\t      \n",conta+2,
													x[conta],x[conta+1]);
	}
 }
 else
	 for (conta=0.;conta < grado; ++conta)
		printf("      \t\t\tx%d = %#+.19g\t\t\t\t      \n",conta+1,
															x[conta]);
}

/**************************************************************************
* visto_bueno : Nos da el visto bueno para las raices.                    *
**************************************************************************/
void visto_bueno(real *c,real *x,int grado,num_tipo_raiz tipo)
{
 printf("      \t\t\tChecando las raices.           \t\t\t      \n");
 checa_raices(c,x,grado,tipo)?bien():mal();
 printf("      \t\t\tEvaluando el polinomio.        \t\t\t      \n");
 checa_eval_raices(c,x,grado,tipo)?bien():mal();
}

/**************************************************************************
* bien : Indica que no hay problema con las raices.                       *
**************************************************************************/
void bien(void)
{
 printf("      \t\t\tNo Hay Problema con las raices.\t\t\t      \n");
}

/**************************************************************************
* mal : Indica que si hay problema con las raices.                        *
**************************************************************************/
void mal(void)
{
 printf("\a");
 printf("      \t\t\t\aSi Hay Problema con las raices.\t\t\t      \n");
}

/**************************************************************************
* error_num_tipo_raiz : Indica que se regreso un num_tipo_raiz indefinido *
* al resolver  las ecuaciones.                                            *
**************************************************************************/
void error_num_tipo_raiz(void)
{
 printf("\a");
 printf("      \t\t\t\aHORROR NúMERO Y TIPO INDEFINIDO.\t\t\t\t\t      \n");
}

/**************************************************************************
* divsinreal : Evalua polinomios mediante división sintetica en valores   *
* reales.                                                                 *
**************************************************************************/
real divsinreal(int grado,real *c,real x,real *b)
{
 int conta=grado-1;
 if (grado > 0)
 {
	b[grado-1] = c[grado];
	for ( conta = grado - 2 ; conta>=0 ; --conta)
		b[conta] = b[conta+1] * x + c[conta + 1];
	return (b[0] * x + c[0]);
 }
 else
	return (c[0]);
}

/***************************************************************************
* divsincompleja : Evalua polinomios mediante división sintetica en valores*
* complejos.                                                               *
***************************************************************************/
real divsincompleja(int grado,real *c,real x,real y,real *b,real *yr,
					real *yi)
{
 int conta=grado-2;
 real u=-2.*x,v=(cuad(x)+cuad(y)),r,s;
 if (grado > 1)
 {
	b[conta--] = c[grado];
	(grado>2)?(b[conta] = c[grado-1]-u*b[grado-2]):
						(r= c[grado-1]-u*b[grado-2]);
	for ( conta = grado - 4 ; conta>=0 ; conta--)
		b[conta] = c[conta+2]-u*b[conta+1] - v*b[conta+2];
	if (grado>2)
		r = c[1]-u*b[0] - v*b[1];
	s = c[0]-u*r - v*b[0];
	*yr = r*x+r*u+s;
	*yi = r*y;
	return sqrt(cuad(*yr)+cuad(*yi));
 }
 else
 {
	*yr = c[0];
	*yi = c[0];
	return sqrt(cuad(*yr)+cuad(*yi));
 }
}

/**************************************************************************
* norma : Cálcula la norma natural de un vector.                          *
**************************************************************************/
real norma(int n,real *x)
{
 int conta;
 real valor,aux;
 for(conta=1,valor=fabs(x[0]);conta<n;conta++)
	if ((aux=fabs(x[conta]))>valor)
		valor=aux;
 return (valor);
}

/************** Rutinas de manejo de errores.**********************/

void error1(void)
{ 
	perror("\aFaltan los coeficientes de la ecuación\n");
	abortar();
}

void errorn(void)
{ 
	perror("\aDemasiados coeficientes de la ecuación\n"); 
	abortar();
}

void error_opcion(void)
{ 
	perror("\aOpción invalida\n");
	abortar();
}

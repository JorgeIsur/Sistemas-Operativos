/**************************************************************************
* constante: Resuelve la ecuación constante mediante las consideraciones  *
* analiticas.                                               			  *
**************************************************************************/
#include "grado4.h"

num_tipo_raiz constante(real *c,real *x)
{
 return (realcmp(c[0],0.)?1:0);
}



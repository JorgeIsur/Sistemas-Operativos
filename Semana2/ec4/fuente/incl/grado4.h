/***************************************************************************
* Header grado4.H: Contiene los heders, macros, tipos de datos y prototipos*
* para la resolución de ecuaciones de grado 0 al 4 analiticamente.         *
***************************************************************************/

/* headers requeridos */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomio.h"
#include "real.h"
#include "salir.h"

/* Prototipos de las funciones */
num_tipo_raiz cuartica(real *,real *);
num_tipo_raiz cubica(real *,real *);
num_tipo_raiz cuadratica(real *,real *);
num_tipo_raiz lineal(real *,real *);
num_tipo_raiz constante(real *,real *);

#include "grado4.h"

int main(int argc,char *argv[])
{
 vector c=crea_vector(MAX_COEF);
 vector x=crea_vector(MAX_RAICES);
 num_tipo_raiz tipo;
 int i,grado=argc-2;
 despedidas();
 limpia();
 switch (argc)
 {
	case 1:
		fprintf(stderr,"uso:\n");
		fprintf(stderr,"%s c0 c1 c2 c3 c4\n",argv[0]);
		salir();
	break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		for(i=0;i<argc-1;i++)
			c[i] = atof(argv[i+1]);
		tipo = cuartica(c,x);
		visto_bueno(c,x,grado,tipo);
		imprime_raices(c,x,grado,tipo);
	break;
	default:
		fprintf(stderr,"Sorry solo resuelvo hasta grado 4\n");
		fprintf(stderr,"\aHorror coeficientes de mas :<\n");
		abortar();
	break;
 }
 salir();
}

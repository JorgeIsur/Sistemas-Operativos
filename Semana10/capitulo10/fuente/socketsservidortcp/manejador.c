#include "manejador.h"

extern int sokectnuevo;

void manejador(int senial)
{
	close(sokectnuevo);
	exit(0);
}

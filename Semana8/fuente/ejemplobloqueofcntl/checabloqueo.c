#include "ejemplobloqueofcntl.h"

void checabloqueo(int descriptorarchivo,long numeroregistros,int tipo,long longitud,char *mensaje)
{
	if(bloquearegistro(descriptorarchivo,numeroregistros,tipo,longitud)!=-1)
		printf("%s: bloqueo exitoso (proceso %i)\n",
				mensaje,getpid());
	else
		error(mensaje);
}

#include "ejemplodeadlock.h"

void vbloqa(int descriptorarchivo,int tipo,long longitud,char *mensaje)
{
	if(lockf(descriptorarchivo,tipo,longitud)!=-1)
		printf("%s: bloqueo exitoso (proceso %i)\n",
				mensaje,getpid());
	else
		error(mensaje);
}

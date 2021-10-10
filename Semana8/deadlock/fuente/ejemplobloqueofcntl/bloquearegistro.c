#include "ejemplobloqueofcntl.h"

int bloquearegistro(int descriptorarchivo,long numeroregistros,short tipo,long longitud)
{
	int valret;
	struct flock archi;

	if(longitud<1)
	{
		fprintf(stderr,"bloquearegistro: longitud invalida\n");
		return(-1);
	}

	switch(tipo)
	{
		case F_RDLCK:
		case F_WRLCK:
		case F_UNLCK:
			archi.l_type=tipo;
			archi.l_whence=1;
			archi.l_start=(numeroregistros-1L)*longitud;
			archi.l_len=longitud;
			return(fcntl(descriptorarchivo,F_SETLKW,&archi));
		default:
			fprintf(stderr,"bloquearegistro: argumento de tipo invalido\n");
			return(-1);
	}
}

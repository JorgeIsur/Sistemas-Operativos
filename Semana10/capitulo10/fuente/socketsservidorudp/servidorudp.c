/* proceso del servidor */
#include "sockets.h"

int main(int argc,char **argv)
{
	int socketnuevo,puerto;
	char caracter;

	/* Puerto del servidor */
	struct sockaddr_in servidor={AF_INET,1991,INADDR_ANY};

	/* La estructura guarda la dirección del proceso2 */
	struct sockaddr_in cliente;
	int longitud_cliente=TAM;

    if(argc!=2)
    {
    	fprintf(stderr,"Uso:\n");
    	fprintf(stderr,"%s puerto \n",argv[0]);
    	exit(1);
    }

    if((puerto=atol(argv[1]))>65535 || puerto <0)
    {
    	fprintf(stderr,"puerto %s invalido\n",argv[1]);
    	exit(2);
    }

    /* Fijar puerto */
    servidor.sin_port=puerto;

	/* Crear el socket */
	if((socketnuevo=socket(AF_INET,SOCK_DGRAM,0)) == -1)
	{
		error("Fallo el socket ... se fundio el foco :-<");
		exit(3);
	}

	/* Asociar la IP al socket */
	if(bind(socketnuevo,(struct sockaddr *)&servidor,TAM) == -1)
	{
		error("Fallo la IP ... se fundio el foco :-<");
		exit(4);
	}

	/* Un ciclo para esperar mensajes */
	for(;;)
	{
		/* Recibir el mensaje y guardar la dirección del clientee */
		if(recvfrom(socketnuevo,&caracter,1,0,&cliente,&longitud_cliente)==-1)
		{
			error("servidor:recibiendo");
			continue;
		}

		caracter=toupper(caracter);

		/* Enviar el mensaje de regreso a quien lo envio */
		if(sendto(socketnuevo,&caracter,1,0,&cliente,longitud_cliente)==-1)
		{	
			error("servidor:enviando");
			continue;
		}

	}

	return(0);
}

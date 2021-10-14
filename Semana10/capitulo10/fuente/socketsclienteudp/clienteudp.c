/* proceso del cliente */
#include "sockets.h"

int main(int argc,char **argv)
{
	int sockfd,puerto;
	char caracter;

	/* Puerto en el cliente */
	struct sockaddr_in cliente={AF_UNIX,INADDR_ANY,INADDR_ANY};

	/* Direccion del servidor */
    struct sockaddr_in servidor={AF_UNIX,1991};

    if(argc!=3)
    {
    	fprintf(stderr,"Uso:\n");
    	fprintf(stderr,"%s puerto IP\n",argv[0]);
    	exit(1);
    }

    if((puerto=atol(argv[1]))>65535 || puerto <0)
    {
    	fprintf(stderr,"puerto %s invalido\n",argv[1]);
    	exit(2);
    }

    /* Fijar puerto */
    servidor.sin_port=puerto;

    /* convertir y almacenar la IP del servidor */
    if((servidor.sin_addr.s_addr=inet_addr(argv[2]))<0)
    {
    	fprintf(stderr,"IP %s invalida\n",argv[2]);
    	exit(3);
    }

	/* Crear el socket */
	if((sockfd=socket(AF_INET,SOCK_DGRAM,0)) == -1)
	{
		error("Fallo el socket ... se fundio el foco :-<");
		exit(4);
	}

	/* Conectar a la IP del servidor al socket */
	if(bind(sockfd,(struct sockaddr *)&cliente,TAM) == -1)
	{
		error("Fallo la IP ... se fundio el foco :-<");
		exit(5);
	}

	/* Ler un caracter del teclado */
	for(;caracter!='\n';)
	{
		read(0,&caracter,1);

		/* Enviar caracteres al servidor */
		if(sendto(sockfd,&caracter,1,0,&servidor,TAM)==-1)
		{
			error("cliente : enviando");
			continue;
		}

		/* Recibir mensaje de regreso */
		if(recv(sockfd,&caracter,1,0)==-1)
		{
			error("cliente : recibiendo");
			continue;
		}

		write(1,&caracter,1);
	}

	return(0);
}

/* proceso del cliente */
#include "sockets.h"

int main(int argc,char **argv)
{
	int sockfd,puerto;
	char caracter,caracterleido;
	struct sockaddr_in server={AF_INET,1991};

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
	server.sin_port=puerto;

	/* convertir y almacenar la IP del servidor */
	if((server.sin_addr.s_addr=inet_addr(argv[2]))<0)
	{
		fprintf(stderr,"IP %s invalida\n",argv[2]);
		exit(3);
	}

	/* Crear el socket */
	if((sockfd=socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		error("Fallo el socket ... se fundio el foco :-<");
		exit(4);
	}

	/* Conectar a la IP del servidor al socket */
	if(connect(sockfd,(struct sockaddr *)&server,TAM) == -1)
	{
		error("Fallo la IP ... se fundio el foco :-<");
		exit(5);
	}

	/* Enviar y recibir información del servidor */
	for(;caracterleido!='\n';)
	{
		read(0,&caracter,1);
		send(sockfd,&caracter,1,0);
		if(recv(sockfd,&caracterleido,1,0)>0)
			write(1,&caracterleido,1);
		else
		{
			error("El servidor se murio .. snif.. snif :-<\n");
			close(sockfd);
			exit(5);
		}
			
	}

	return(0);
}

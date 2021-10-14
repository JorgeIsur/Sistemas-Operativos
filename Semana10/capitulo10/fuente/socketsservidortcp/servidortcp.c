/* proceso del servidor */
#include "sockets.h"
#include "manejador.h"

int sokectnuevo;

int main(int argc,char **argv)
{
	int sockfd,puerto;
	char caracter;
	struct sockaddr_in server={AF_UNIX,7000,INADDR_ANY};
	struct timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	fd_set rds;
	FD_ZERO(&rds);
	FD_SET(sockfd,&rds);
	int res;

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
	server.sin_port=puerto;

	signal(SIGPIPE,manejador);

	/* Crear el socket */
	if((sockfd=socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		error("Fallo el socket ... se fundio el foco :-<");
		exit(1);
	}

	/* Asociar la IP al socket */
	if(bind(sockfd,(struct sockaddr *)&server,TAM) == -1)
	{
		error("Fallo la IP ... se fundio el foco :-<");
		exit(2);
	}

	/* Escuchar por conexiones entrantes */
	if(listen(sockfd,5) == -1)
	{
		error("Fallo la escucha ... se callo el microfono :-<");
		exit(3);
	}
	printf("Escuchando...\n");
	if((res=select(sockfd+1,&rds,NULL,NULL,&timeout))<=0){
		if(res<0){
			printf("Fallido\n");
		}
		else{
			printf("Tiempo de espera terminado...\n");

		}
		exit(0);
	}
	for(;;)
	{	
		/* Aceptar una conexi�n */
		if((sokectnuevo=accept(sockfd,NULL,NULL)) == -1)
		{
			error("Fallo la aceptacion ... dijo que no :-<");
			exit(4);
		}

		/* Tener un hijo para manejar las conexiones */
		if(!fork())
		{
			while(recv(sokectnuevo,&caracter,1,0)>0)
			{
				printf("Mensaje Recibido:%s\n",&caracter);
				caracter=toupper(caracter);
				printf("Mensaje enviado:%s\n",&caracter);
				send(sokectnuevo,&caracter,1,0);
			}
			/* Cuando no se envia mas informaci�n el socket
				se cierra y el hijo termina */
			close(sokectnuevo);
			exit(0);
		}
		/* El padre no requiere el socket */
		close(sokectnuevo);
	}
	return(0);
}

#include "ejemplodeadlock.h"

int main(void)
{
	int descriptorarchivo;
	char buffer[TAM];

	if((descriptorarchivo=open("bloqueado",O_RDWR))<0)
		error("Fallo open");

	lseek(descriptorarchivo,0L,0);
	vbloqa(descriptorarchivo,F_LOCK,10L,"Sección A");
	if(read(descriptorarchivo,buffer,TAM)<0)
		error("Fallo 1er read");
	buffer[TAM]='\0';
	printf("%s\n",buffer);

	if(!fork())
	{

		lseek(descriptorarchivo,10L,0);
		vbloqa(descriptorarchivo,F_LOCK,10L,"Sección B");
		if(read(descriptorarchivo,buffer,TAM)<0)
			error("Fallo 2do read");
		buffer[TAM]='\0';
		printf("%s\n",buffer);

		lseek(descriptorarchivo,0L,0);
		vbloqa(descriptorarchivo,F_LOCK,10L,"Sección C");
		if(read(descriptorarchivo,buffer,TAM)<0)
			error("Fallo 3er read");
		buffer[TAM]='\0';
		printf("%s\n",buffer);

	}
	else
	{
		printf("Padre zzzzzzzzzzz\n");
		sleep(10);

		lseek(descriptorarchivo,10L,0);
		vbloqa(descriptorarchivo,F_LOCK,10L,"Sección D");
		if(read(descriptorarchivo,buffer,TAM)<0)
			error("Fallo 4to read");
		buffer[TAM]='\0';
		printf("%s\n",buffer);
	}
	exit(0);
}

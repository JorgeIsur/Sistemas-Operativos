#######################################################################
# Archivo de descripción para compilar el proyecto de ecuación grado 3#
# $Id: makefile,v 1.1.1.1 2018/01/29 20:36:45 hpl Exp $																  #
#																	  #
# $Author: hpl $															  #
#######################################################################

#######################################################################
# Definición de Macros												  #
#######################################################################
COMPILADOR=cc -g

FUENTE = $(RUTA_GRADO0)grado0.c $(RUTA_GRADO1)grado1.c \
		$(RUTA_GRADO2)grado2.c grado3.c stub.c 

OBJS=$(FUENTE:.c=.o)

HEADER=grado4.h

LIB=grado4

PROG= $(RUTA_BIN)grado3

#######################################################################
# Target principal para compilar el programa.						  #
#######################################################################
$(PROG): $(OBJS) 
	$(COMPILADOR) $(OBJS) -L$(RUTA_LIB) -l$(LIB) -lm -o $@
	@- echo "Compilación terminada $(PROG)"

#######################################################################
# Target para eliminar Objetos.										  #
#######################################################################
LIMPIA:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminado $(PROG)"

#######################################################################
# Target para eliminar Objetos y ejecutable.						  #
#######################################################################
BORRA:
	@- rm -f $(OBJS) $(PROG)
	@- echo "Borrado de archivos terminado $(PROG)"

#######################################################################
# Dependencia de Objetos con fuentes.								  #
#######################################################################
.c.o: 
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o

#######################################################################
# Dependencia de Objetos con headers.								  #
#######################################################################
$(OBJS): $(RUTA_INCL)$(HEADER) $(RUTA_LIB)lib$(LIB).a

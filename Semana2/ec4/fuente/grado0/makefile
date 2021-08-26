#######################################################################
# Archivo de descripción para compilar el proyecto de ecuación grado 0#
# $Id: makefile,v 1.3 2018/01/29 20:58:44 hpl Exp $				  #
#																	  #
# $Author: hpl $													  #
#######################################################################

#######################################################################
# Definición de Macros												  #
#######################################################################
COMPILADOR=cc -g
FUENTE = grado0.c stub.c 
OBJS=$(FUENTE:.c=.o)
HEADER=grado4.h 
LIB=grado4
PROG= $(RUTA_BIN)grado0

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

########################################################################
# Archivo de descripción para compilar la librería					   #
#																	   #
# $Id: makefile,v 1.1.1.1 2018/01/29 20:36:45 hpl Exp $																   #
#																	   #
# $Author: hpl $															   #
########################################################################

########################################################################
# Definición de Macros												   #
########################################################################

LIBRERO=ar -rc

COMPILADOR=cc -g

FUENTE = cadena.c polinomio.c real.c salir.c 

OBJS=$(FUENTE:.c=.o)

HEADER=$(RUTA_INCL)cadena.h $(RUTA_INCL)polinomio.h $(RUTA_INCL)real.h \
		$(RUTA_INCL)salir.h

LIB= $(RUTA_LIB)libgrado4.a

#######################################################################
# Target principal para compilar la libreria.						  #
#######################################################################
$(LIB): $(OBJS)
	$(LIBRERO) $@ $(OBJS)
	@- echo "Compilación de libreria terminada $(LIB)"

#######################################################################
# Target para eliminar Objetos.										  #
#######################################################################
LIMPIA:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminada $(LIB)"

#######################################################################
# Target para eliminar Objetos y ejecutable.						  #
#######################################################################
BORRA:
	@- rm -f $(OBJS) $(LIB) 
	@- echo "Borrado de archivos terminada $(LIB)"

#######################################################################
# Dependencia de Objetos con fuentes.								  #
#######################################################################
.c.o: 
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c 

#######################################################################
# Dependencia de Objetos con headers.								  #
#######################################################################
$(OBJS): $(HEADER)

#######################################################################
# Archivo de descripci▒n para compilar el proyecto de cubiculos       #
# $Id$                                                                #
#                                                                     #
# $Author$                                                            #
#######################################################################

#######################################################################
# Definici▒n de Macros                                                #
#######################################################################
COMPILADOR=cc
FUENTE = procesaarchivo.c stub.c
OBJS=$(FUENTE:.c=.o)
HEADER=listarrec.h
PROG= $(RUTA_BIN)procesaarchivo
#######################################################################
# Target principal para compilar el programa.                         #
#######################################################################
$(PROG): $(OBJS)
					$(COMPILADOR) $(OBJS) -lm -o $@
					@- echo "Compilaci▒n terminada $(PROG)"

#######################################################################
# Target para eliminar Objetos.                                       #
#######################################################################
LIMPIA:
				@- rm -f $(OBJS)
				@- echo "Borrado de objetos terminado $(PROG)"

#######################################################################
# Target para eliminar Objetos y ejecutable.                          #
#######################################################################
BORRA:
				@- rm -f $(OBJS) $(PROG)
				@- echo "Borrado de archivos terminado $(PROG)"
#######################################################################
# Dependencia de Objetos con fuentes.                                 #
#######################################################################
.c.o:
				$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o

#######################################################################
# Dependencia de Objetos con headers.                                 #
#######################################################################
$(OBJS): $(RUTA_INCL)$(HEADER)

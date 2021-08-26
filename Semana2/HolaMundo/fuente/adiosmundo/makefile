####################################################################### 
# Archivo de descripción para compilar el proyecto de adios mundo     # 
# $Id$                                                                # 
#                                                                     #
# $Author$                                                            # 
####################################################################### 
 
####################################################################### 
# Definición de Macros                                                # 
####################################################################### 
COMPILADOR=gcc  
FUENTE = adiosmundo.c 
OBJS=$(FUENTE:.c=.o) 
HEADER=aviso.h 
LIB=aviso 
PROG= $(RUTA_BIN)adiosmundo 
 
####################################################################### 
# Target principal para compilar el programa.                         # 
####################################################################### 
$(PROG): $(OBJS)
        $(COMPILADOR) $(OBJS) -L$(RUTA_LIB) -l$(LIB) -lm -o $@ 
        @- echo "Compilación terminada $(PROG)"
        
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
$(OBJS): $(RUTA_INCL)$(HEADER) $(RUTA_LIB)lib$(LIB).a